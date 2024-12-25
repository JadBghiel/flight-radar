/*
** EPITECH PROJECT, 2024
** my_fgets
** File description:
** reads a line from buffer, stores it into the string pointed to by str
*/
#include "../../include/my.h"

static char *resize_file_buffer(file_buffer_info_t *info)
{
    char *new_buffer;

    info->buffer_size *= 2;
    new_buffer = my_realloc(info->file_buffer, info->buffer_size / 2,
        info->buffer_size);
    if (!new_buffer) {
        my_put_error("my_fgets: mem reallocation failed\n");
        exit(84);
    }
    return new_buffer;
}

static int refill_file_buffer(int fd, file_buffer_info_t *info)
{
    info->total = read(fd, info->file_buffer, info->buffer_size);
    if (info->total <= 0) {
        return 0;
    }
    return 1;
}

static int process_next_char(char *buffer, file_buffer_info_t *info, int *i,
    int size)
{
    char c;

    c = info->file_buffer[info->index];
    info->index++;
    buffer[*i] = c;
    (*i)++;
    if (c == '\n') {
        return 0;
    }
    if (*i >= size - 1) {
        return 0;
    }
    return 1;
}

static int read_line(int fd, char *buffer, file_buffer_info_t *info, int size)
{
    int i = 0;

    while (1) {
        if (info->index >= info->total && !refill_file_buffer(fd, info)) {
            free(info->file_buffer);
            info->file_buffer = NULL;
            return -1;
        }
        if (info->index >= info->buffer_size) {
            info->file_buffer = resize_file_buffer(info);
        }
        if (!process_next_char(buffer, info, &i, size)) {
            break;
        }
    }
    buffer[i] = '\0';
    return 0;
}

char *my_fgets(char *buffer, int size, int fd)
{
    static file_buffer_info_t info = {NULL, 0, 0, 0};

    if (!info.file_buffer) {
        info.buffer_size = 1024;
        info.file_buffer = malloc(info.buffer_size);
        if (!info.file_buffer) {
            my_put_error("my_fgets: mem reallocation failed\n");
            exit(84);
        }
    }
    if (read_line(fd, buffer, &info, size) == -1) {
        return NULL;
    }
    return buffer;
}

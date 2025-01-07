/*
** EPITECH PROJECT, 2024
** validate_script
** File description:
** make sure the script is: readable, right value/syntax
*/
#include "../include/my_radar.h"

int is_valid_integer(const char *str)
{
    if (!str || *str == '\0')
        return 0;
    if (*str == '-')
        str++;
    while (*str) {
        if (!my_isdigit(*str))
            return 0;
        str++;
    }
    return 1;
}

static int validate_token_values(char *ptr, int expected_count,
    int non_negative_start)
{
    char *token = my_strtok(NULL, " \t");
    int count = 0;
    int value;

    while (token && count < expected_count) {
        if (!is_valid_integer(token)) {
            return 0;
        }
        value = my_atoi(token);
        if (count >= non_negative_start && value < 0) {
            return 0;
        }
        count++;
        token = my_strtok(NULL, " \t");
    }
    return count == expected_count;
}

static int validate_tokens(char *line, char type, int expected_count,
    int non_negative_start)
{
    char *copy = my_strdup(line);
    char *ptr = copy;
    char *token = my_strtok(ptr, " \t");
    int result;

    if (!token || token[0] != type || token[1] != '\0') {
        free(copy);
        return 0;
    }
    result = validate_token_values(ptr, expected_count, non_negative_start);
    free(copy);
    return result;
}

int validate_aircraft_line(char *line)
{
    return validate_tokens(line, 'A', 6, 4);
}

int validate_tower_line(char *line)
{
    return validate_tokens(line, 'T', 3, 2);
}

int validate_line(char *line)
{
    if (line[0] == 'A')
        return validate_aircraft_line(line);
    if (line[0] == 'T')
        return validate_tower_line(line);
    return 0;
}

static int process_line(char *line)
{
    size_t len = my_strlen(line);

    if (len > 0 && line[len - 1] == '\n') {
        line[len - 1] = '\0';
    }
    if (!validate_line(line)) {
        my_put_error("invalid line(s)\n");
        return 84;
    }
    return 0;
}

static int read_lines_from_file(FILE *file)
{
    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    read = getline(&line, &len, file);
    while (read != -1) {
        if (process_line(line) == 84) {
            free(line);
            return 84;
        }
        read = getline(&line, &len, file);
    }
    free(line);
    return 0;
}

int validate_script(const char *filename)
{
    FILE *file = fopen(filename, "r");
    int result;

    if (!file) {
        my_put_error("failed to open script file\n");
        return 84;
    }
    result = read_lines_from_file(file);
    fclose(file);
    return result;
}

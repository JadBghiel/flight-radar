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

int validate_aircraft_line(char *line)
{
    char *token;
    int count = 0;
    int value;

    token = my_strtok(line, " \t");
    if (!token)
        return 0;
    if (token[0] != 'A' || token[1] != '\0')
        return 0;
    token = my_strtok(NULL, " \t");
    while (token) {
        if (!is_valid_integer(token)) {
            return 0;
        }
        value = my_atoi(token);
        count++;
        if (count >= 5 && value < 0)
            return 0;
    }
    return (count == 6);
}

int validate_tower_line(char *line)
{
    char *token;
    int count = 0, value;

    token = my_strtok(line, " \t");
    if (!token || token[0] != 'T' || token[1] != '\0') {
        return 0;
    }
    token = my_strtok(NULL, " \t");
    while (token) {
        if (!is_valid_integer(token))
            return 0;
        value = my_atoi(token);
        if (count == 2 && value < 0)
            return 0;
        count++;
    }
    return count == 3;
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

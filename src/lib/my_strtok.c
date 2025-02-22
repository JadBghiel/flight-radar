/*
** EPITECH PROJECT, 2024
** my_strtok
** File description:
** split a string into tokens
*/
#include "../../include/my.h"

static int is_delim(char c, const char *delim)
{
    int i;

    for (i = 0; delim[i] != '\0'; i++) {
        if (c == delim[i]) {
            return 1;
        }
    }
    return 0;
}

static char *skip_delimiters(char *str, const char *delim)
{
    while (*str && is_delim(*str, delim)) {
        str++;
    }
    return str;
}

static char *find_token_end(char *str, const char *delim)
{
    while (*str) {
        if (is_delim(*str, delim)) {
            *str = '\0';
            return str + 1;
        }
        str++;
    }
    return NULL;
}

char *my_strtok(char *str, const char *delim)
{
    static char *saved_str = NULL;
    char *token;

    if (str != NULL) {
        saved_str = str;
    }
    if (saved_str == NULL || *saved_str == '\0') {
        return NULL;
    }
    saved_str = skip_delimiters(saved_str, delim);
    if (*saved_str == '\0') {
        return NULL;
    }
    token = saved_str;
    saved_str = find_token_end(saved_str, delim);
    return token;
}

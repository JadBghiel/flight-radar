/*
** EPITECH PROJECT, 2024
** my_strdup.c
** File description:
** dup a str
*/
#include "../../include/my.h"

char *my_strdup(const char *src)
{
    char *dup;

    if (!src) {
        return NULL;
    }
    dup = malloc(my_strlen(src) + 1);
    if (!dup)
        return NULL;
    my_strcpy(dup, src);
    return dup;
}

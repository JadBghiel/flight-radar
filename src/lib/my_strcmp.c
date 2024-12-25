/*
** EPITECH PROJECT, 2024
** my_strcmp
** File description:
** compares two strings
*/
#include "../../include/my.h"

int my_strcmp(const char *s1, const char *s2)
{
    int i;

    for (i = 0; s1[i] != '\0' && s2[i] != '\0'; i++) {
        if (s1[i] != s2[i]) {
            return s1[i] - s2[i];
        }
    }
    return s1[i] - s2[i];
}

/*
** EPITECH PROJECT, 2024
** my_strlen
** File description:
** counts and returns the amount of char in a string
*/
#include "../../include/my.h"

int my_strlen(char const *str)
{
    int strLen = 0;

    while (*str != '\0') {
        strLen++;
        str++;
    }
    return strLen;
}

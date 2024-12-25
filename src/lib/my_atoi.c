/*
** EPITECH PROJECT, 2024
** my_atoi
** File description:
** atoi
*/
#include "../../include/my.h"

int my_atoi(const char *str)
{
    int result = 0;
    int sign = 1;
    size_t i = 0;

    while (my_isspace(str[i])) {
        i++;
    }
    if (str[i] == '-') {
        sign = -1;
        i++;
    } else if (str[i] == '+') {
        i++;
    }
    while (str[i] >= '0' && str[i] <= '9') {
        result = result * 10 + (str[i] - '0');
        i++;
    }
    return result * sign;
}

/*
** EPITECH PROJECT, 2024
** my_isspace
** File description:
** isspace
*/
#include "../../include/my.h"

int my_isspace(char c)
{
    return (c == ' ' || c == '\t' || c == '\n' || c == '\r');
}

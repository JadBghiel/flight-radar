/*
** EPITECH PROJECT, 2024
** my_putchar
** File description:
** displays a char
*/
#include "../../include/my.h"

void my_putchar(char c)
{
    write(1, &c, 1);
}

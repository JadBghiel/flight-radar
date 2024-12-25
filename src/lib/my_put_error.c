/*
** EPITECH PROJECT, 2024
** my_put_errroo
** File description:
** disp errors
*/
#include "../../include/my.h"

void my_put_error(const char *error_message)
{
    if (!error_message) {
        return;
    }
    write(2, error_message, my_strlen(error_message));
}

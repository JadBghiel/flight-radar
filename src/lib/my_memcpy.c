/*
** EPITECH PROJECT, 2024
** my_memcpy
** File description:
** cpy mem bloc from src to dest (when the mem blocs dont overlap)
*/
#include "../../include/my.h"

void *my_memcpy(void *dest, const void *src, size_t n)
{
    unsigned char *d = (unsigned char *)dest;
    const unsigned char *s = (const unsigned char *)src;

    for (size_t i = 0; i < n; i++) {
        d[i] = s[i];
    }
    return dest;
}

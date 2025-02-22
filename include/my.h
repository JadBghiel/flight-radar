/*
** EPITECH PROJECT, 2024
** my.h
** File description:
** header file
*/
#ifndef MY_H
    #define MY_H
    #include "common_lib.h"

typedef struct file_buffer_info_s {
    char *file_buffer;
    size_t buffer_size;
    int index;
    int total;
} file_buffer_info_t;

void my_putchar(char c);
char *my_strstr(char *str, char const *to_find);
int my_isneg(int nb);
int my_strcmp(char const *s1, char const *s2);
int my_put_nbr(int nb);
int my_strncmp(char const *s1, char const *s2, int n);
void my_swap(int *a, int *b);
char *my_strupcase(char *str);
int my_putstr(char const *str);
char *my_strlowcase(char *str);
int my_strlen(char const *str);
char *my_strcapitalize(char *str);
int my_getnbr(char const *str);
int my_str_isalpha(char const *str);
void my_sort_int_array(int *tab, int size);
int my_str_isnum(char const *str);
int my_compute_power_rec(int nb, int power);
int my_str_islower(char const *str);
int my_compute_square_root(int nb);
int my_str_isupper(char const *str);
int my_is_prime(int nb);
int my_str_isprintable(char const *str);
int my_find_prime_sup(int nb);
int my_showstr(char const *str);
char *my_strcpy(char *dest, char const *src);
int my_showmem(char const *str, int size);
char *my_strncpy(char *dest, char const *src, int n);
char *my_strcat(char *dest, char const *src);
char *my_revstr(char *str);
char *my_strncat(char *dest, char const *src, int nb);
char my_charswap(char *, char *);
int read_file(const char *file_name);
void write_buffer(const char *buffer, int size);
void my_put_long_unsigned(long unsigned int num);
void my_put_long_int(long int num);
void my_put_unsigned_int(unsigned int num);
char *my_strdup(char const *src);
int my_compute_power_it(int nb, int p);
int my_isdigit(char c);
int my_atoi(const char *str);
void my_put_error(const char *error_message);
int my_isspace(char c);
char *my_fgets(char *buffer, int size, int fd);
void *my_realloc(void *ptr, size_t old_size, size_t new_size);
void *my_memcpy(void *dest, const void *src, size_t n);
char *my_strtok(char *str, const char *delim);
#endif /* MY_H */

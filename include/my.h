/*
** EPITECH PROJECT, 2021
** my_h
** File description:
** proto
*/

#include <stdarg.h>
#include <stdlib.h>

#ifndef MY_H_
    #define MY_H_

void my_swap(int *a, int *b);
void my_putchar(char c);
char *my_strupcase(char *str);
char *my_strstr(char *str, char const *to_find);
char *my_findstr(char *str, char const *to_find, int i);
int my_showstr(char const *str);
int my_showmem(char const *str, int size);
char *my_strncpy(char *dest, char const *src, int n);
int my_strncmp(char const *s1, char const *s2, int n);
char *my_strncat(char *dest, char const *src, int n);
char *my_strlowcase(char *str);
int my_strlen(char const *str);
int my_str_isupper(char const *str);
int my_str_isprintable(char const *str);
int my_str_isnum(char const *str);
int my_str_islower(char const *str);
int my_str_isalpha(char const *str);
char *my_strcpy(char *dest, char const *src);
int my_strcmp(char const *s1, char const *s2);
char *my_strcat(char *dest, char const *src);
char *my_strcapitalize(char *str);
void my_sort_int_array(int *tab, int size);
char *my_revstr(char *str);
int my_putstr(char const *str);
int my_put_nbr(int nb);
void my_print_revalpha(void);
void my_print_digits(void);
void my_print_alpha(void);
int my_is_prime(int nb);
int my_isneg(int n);
int my_getnbr(char const *str);
int my_find_prime_sup(int nb);
int my_compute_square_root(int nb);
int my_compute_power_rec(int nb, int p);
int its_may_prime(int nb, int i);
void display_nbr(int temp, int count);
void my_swap2(char *a, char *b);
int my_show_word_array(char * const *tab);
int count_words(char const *str);
int count_letters(char const *str, int i);
void my_converting_base(char *base, unsigned int nbr);
void my_convert_main(char base, unsigned int nbr);
int my_put_hashtag(char const *str, int i, va_list list);
int len_array(char **array);
int my_print_first(int i, const char *str, va_list list);
char **put_word_in_array(char const *str, char **array, int i);
int add_last_arr(char const *str, char **array, int i);
char **my_str_to_word_array(char *str);
int my_put_hashtag(char const *str, int i, va_list list);
void my_convert_main(char base, unsigned int nbr);
void my_converting_segond(char base, unsigned int nbr);
void free_tab(char **tab);
void move_by_one(char *str, int i);

#endif

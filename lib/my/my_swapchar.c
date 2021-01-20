/*
** EPITECH PROJECT, 2020
** minishell
** File description:
** swap_char
*/

#include "my.h"

void my_swapchar(char *a, char *b)
{
    char int_a = *a;
    *a = *b;
    *b = int_a;
}
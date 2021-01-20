/*
** EPITECH PROJECT, 2020
** minishell
** File description:
** revstr
*/

#include "my.h"

char *my_revstr(char *str)
{
    int lenght = my_strlen(str) - 1;
    int i = 0;

    while (i < lenght) {
        my_swapchar(&(str[i]), &(str[lenght]));
        i += 1;
        lenght -= 1;
    }
    return (str);
}
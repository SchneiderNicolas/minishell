/*
** EPITECH PROJECT, 2020
** minishell
** File description:
** is alphanumeric
*/

#include "my.h"
#include "struct.h"

int my_isalnum(info_t *info)
{
    for (int i = 0; info->tab[1][i]; i++) {
        char c = info->tab[1][i];
        if (c < 48 || (c > 57 && c < 65) || (c > 90 && c < 97) || c > 122)
            return -1;
    }
    return 1;
}
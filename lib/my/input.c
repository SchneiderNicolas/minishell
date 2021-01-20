/*
** EPITECH PROJECT, 2020
** minishell
** File description:
** input
*/

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "my.h"

char **input(char **tab)
{
    char *input = NULL;
    size_t len = 0;
    if (getline(&input, &len, stdin) == -1) {
        my_puterr("exit\n");
        exit (0);
    }
    tab = my_str_to_word_array(input, ' ');
    free(input);
    return tab;
}
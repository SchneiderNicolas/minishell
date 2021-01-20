/*
** EPITECH PROJECT, 2020
** minishell
** File description:
** compare 2 strings until =
*/

#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include "my.h"
#include "struct.h"

int my_strcmp_equal(char *str1, char *str2)
{
    int i = 0;
    for (; str1[i] != '=' && str1[i] != '\0'; i++) {
        if (str1[i] != str2[i])
            return -1;
    }
    if (str2[i] == '\0')
        return 1;
    else
        return -1;
}
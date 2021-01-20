/*
** EPITECH PROJECT, 2020
** minishell
** File description:
** exit
*/

#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include "my.h"
#include "struct.h"

void my_exit(info_t *info)
{
    int len = tab_len(info->tab);
    if (len == 1) {
        my_puterr("exit\n");
        exit (0);
    } else if (len > 2 || is_num(info->tab[1]) != 1) {
        my_puterr("exit: Expression Syntax.\n");
        return;
    } else {
        my_puterr("exit\n");
        exit (my_getnbr(info->tab[1]) % 256);
    }
}
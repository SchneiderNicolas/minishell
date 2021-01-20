/*
** EPITECH PROJECT, 2020
** minishell
** File description:
** get user
*/

#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include "my.h"
#include "struct.h"

char *get_user(info_t *info)
{
    for (char **env = info->envp; *env != 0; env++) {
        char *thisEnv = *env;
        if (thisEnv[0] == 'U' && thisEnv[1] == 'S' && thisEnv[2] == 'E'
        && thisEnv[3] == 'R' && thisEnv[4] == '=') {
            for (int i = 0; i < 5; i++)
                *thisEnv++;
            return thisEnv;
        }
    }
}
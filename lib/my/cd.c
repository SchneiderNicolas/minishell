/*
** EPITECH PROJECT, 2020
** minishell
** File description:
** cd
*/

#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include "my.h"
#include "struct.h"

void cd_error_handling(char **tab)
{
    if (errno == EACCES) {
        my_puterr(tab[1]);
        my_puterr(": Permission denied.\n");
    }
    if (errno == ENOTDIR) {
        my_puterr(tab[1]);
        my_puterr(": Not a directory.\n");
    }
    if (errno == ENOENT) {
        my_puterr(tab[1]);
        my_puterr(": No such file or directory.\n");
    }
}

int specific_cd_case(info_t *info, int len)
{
    if (len == 2 && info->tab[1][0] == '~') {
        chdir(my_strcat("/home/", get_user(info)));
        change_pwd(info);
        return 1;
    }
    if (len == 2 && info->tab[1][0] == '-') {
        chdir(info->old_pwd);
        change_pwd(info);
        return 1;
    }
}

void cd(info_t *info)
{
    int len = tab_len(info->tab);
    if (len > 2) {
        my_puterr(info->tab[0]);
        my_puterr(": Too many arguments.\n");
        return;
    } else if (len == 1) {
        chdir(my_strcat("/home/", get_user(info)));
        change_pwd(info);
        return;
    }
    if (specific_cd_case(info, len) == 1)
        return;
    if (chdir(info->tab[1]) == -1) {
        cd_error_handling(info->tab);
    } else {
        change_pwd(info);
    }
}
/*
** EPITECH PROJECT, 2020
** minishell
** File description:
** main.c
*/

#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include "include/my.h"
#include "include/struct.h"

void my_unsetenv(info_t *info)
{
    if (tab_len(info->tab) == 1) {
        my_puterr("unsetenv: Too few arguments.\n");
        return;
    } else {
        for (int i = 1; i < tab_len(info->tab); i++)
            delete_node(&info->ll_envp, info->tab[i]);
        return;
    }
}

int my_builtins(info_t *info)
{
    info->tab = input(info->tab);
    char *array[] = {"cd", "env", "exit", "setenv", "unsetenv"};
    void (*builtins[])(info_t *info) = {cd, my_env, my_exit, my_setenv,
    my_unsetenv};
    for (int i = 0; i < 5; i++) {
        if (my_strcmp(info->tab[0], array[i]) == 1) {
            builtins[i](info);
            return 1;
        }
    }
    return 0;
}

void shell(info_t *info)
{
    while (1) {
        my_putstr("$> ");
        if (my_builtins(info) != 1) {
            my_exec(info);
        }
    }
}

int main(int argc, char *argv[], char **envp)
{
    if (argc != 1)
        return 84;
    info_t *info = malloc(sizeof(info_t));
    if (info == NULL)
        return 84;
    info->envp = envp;
    info->ll_envp = init_linked_list(envp);
    my_rev_list(&info->ll_envp);
    shell(info);
}
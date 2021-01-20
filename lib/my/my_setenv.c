/*
** EPITECH PROJECT, 2020
** minishell
** File description:
** setenv
*/

#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include "my.h"
#include "struct.h"

int norm(info_t *info, node_t *tmp)
{
    if (tab_len(info->tab) == 2) {
        tmp->data = malloc(sizeof(char) * my_strlen(info->tab[1]) + 2);
        tmp->data = my_strcat(info->tab[1], "=");
        tmp->data[my_strlen(info->tab[1]) + 2] = '\0';
        return 1;
    } else if (tab_len(info->tab) == 3) {
        tmp->data = malloc(sizeof(char) * (my_strlen(info->tab[1]) +
        my_strlen(info->tab[2]) + 2));
        tmp->data = my_strcat(my_strcat(info->tab[1], "="),
        info->tab[2]);
        tmp->data[my_strlen(info->tab[1]) +
        my_strlen(info->tab[2]) + 2] = '\0';
        return 1;
    }
    return 0;
}

int check_and_change_env(info_t *info)
{
    node_t *tmp;
    tmp = info->ll_envp;
    while (tmp != NULL) {
        if (my_strcmp_equal(tmp->data, info->tab[1]) == 1) {
            if (norm(info, tmp) == 1)
                return 1;
        }
        tmp = tmp->next;
    }
}

int setenv_error_handling(info_t *info)
{
    if (is_letter(info->tab[1][0]) == -1) {
        my_puterr("setenv: Variable name must begin with a letter.\n");
        return -1;
    }
    if (my_isalnum(info) == -1) {
        my_puterr("setenv: Variable name must contain ");
        my_puterr("alphanumeric characters.\n");
        return -1;
    }
    if (tab_len(info->tab) > 3) {
        my_puterr("setenv: Too many arguments.\n");
        return -1;
    }
    return 1;
}

void my_setenv(info_t *info)
{
    if (tab_len(info->tab) == 1) {
        print_linked_list(info->ll_envp);
        return;
    }
    if (setenv_error_handling(info) == -1)
        return;
    if (check_and_change_env(info) == 1)
        return;
    if (tab_len(info->tab) == 3)
        insert_node_end(my_strcat(my_strcat(info->tab[1], "="),
        info->tab[2]), info->ll_envp);
    if (tab_len(info->tab) == 2)
        insert_node_end(my_strcat(info->tab[1], "="), info->ll_envp);
}
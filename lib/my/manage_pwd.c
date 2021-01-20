/*
** EPITECH PROJECT, 2020
** minishell
** File description:
** manage_pwd
*/

#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include "my.h"
#include "struct.h"

void get_old_pwd(info_t *info, char * pwd)
{
    for (; pwd[0] != '='; pwd++);
    pwd++;
    info->old_pwd = malloc(sizeof(char) * my_strlen(pwd));
    info->old_pwd = pwd;
}

void change_pwd(info_t *info)
{
    node_t *tmp;
    tmp = info->ll_envp;
    char * new_pwd = my_strcat(my_strcat("PWD", "="), getcwd(NULL, 100));
    while (tmp != NULL) {
        if (my_strcmp_equal(tmp->data, "PWD") == 1) {
            get_old_pwd(info, tmp->data);
            if ((tmp->data = malloc(sizeof(char) * my_strlen(new_pwd) + 1))
            == NULL)
                exit (84);
            tmp->data = new_pwd;
            tmp->data[my_strlen(new_pwd) + 1] = '\0';
            return;
        }
        tmp = tmp->next;
    }
}
/*
** EPITECH PROJECT, 2020
** minishell
** File description:
** exec
*/

#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include "my.h"
#include "struct.h"

int check_slash(char *str)
{
    for (int i = 0; str[i]; i++) {
        if (str[i] == '/')
            return 1;
    }
    return -1;
}

void get_path(info_t *info)
{
    node_t *tmp;
    char *path;
    tmp = info->ll_envp;
    while (tmp != NULL) {
        if (my_strcmp_equal(tmp->data, "PATH") == 1) {
            path = tmp->data;
            for (; path[0] != '='; ++path);
            ++path;
            info->path_tab = my_str_to_word_array(path, ':');
            return;
        }
        tmp = tmp->next;
    }
}

void execve_options(info_t *info)
{
    int i = 0;
    if (check_slash(info->tab[0]) == 1) {
        if ((execve(info->tab[0], info->tab, info->envp)) == -1)
            my_puterr(info->tab[0]);
            my_puterr(": Command not found.\n");
        exit (1);
    } else {
        get_path(info);
        for (; info->path_tab[i] != NULL; i++)
            execve(my_strcat(my_strcat(info->path_tab[i], "/"), info->tab[0]),
            info->tab, info->envp);
        if (info->path_tab[i] == NULL) {
            my_puterr(info->tab[0]);
            my_puterr(": Command not found.\n");
        }
        exit (1);
    }
}

void manage_coredumped(int status)
{
    if (WIFSIGNALED(status) != 0) {
        if (WTERMSIG(status) == 11 && __WCOREDUMP(status) == 0)
            my_puterr("Segmentation fault \n");
        else if (WTERMSIG(status) == 11 && __WCOREDUMP(status) != 0);
            my_puterr("Segmentation fault (core dumped)\n");
    }
}

void my_exec(info_t *info)
{
    pid_t c_pid;
    pid_t pid;
    int status;
    c_pid = fork();
    if (c_pid == 0) {
        execve_options(info);
    } else if (c_pid > 0) {
        if ((pid = wait(&status)) < 0) {
            perror("wait");
            exit (84);
        }
        manage_coredumped(status);
    }
}
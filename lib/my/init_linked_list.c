/*
** EPITECH PROJECT, 2020
** minishell
** File description:
** initialize linked list
*/

#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include "my.h"
#include "struct.h"

node_t *init_linked_list(char **envp)
{
    node_t *list = NULL;
    node_t *new;
    for (int i = 0; envp[i] != NULL; i++) {
        if ((new = malloc(sizeof(node_t))) == NULL)
            exit (84);
        if ((new->data = malloc(sizeof(my_strlen(envp[i])) + 1)) == NULL)
            exit (84);
        new->data = envp[i];
        new->next = list;
        list = new;
    }
    return list;
}
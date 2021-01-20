/*
** EPITECH PROJECT, 2020
** minishell
** File description:
** delete node linked list
*/

#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include "my.h"
#include "struct.h"

void delete_node(node_t **head_ref, char *key)
{
    node_t *tmp = *head_ref;
    node_t *prev;
    if (tmp != NULL && my_strcmp_equal(tmp->data, key) == 1) {
        *head_ref = tmp->next;
        free(tmp);
        return;
    }
    while (tmp != NULL && my_strcmp_equal(tmp->data, key) != 1) {
        prev = tmp;
        tmp = tmp->next;
    }
    if (tmp == NULL)
        return;
    prev->next = tmp->next;
    free(tmp);
}
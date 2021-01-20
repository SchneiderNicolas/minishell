/*
** EPITECH PROJECT, 2020
** minishell
** File description:
** Reverse linked list
*/

#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include "my.h"
#include "struct.h"

void my_rev_list(node_t **begin)
{
    node_t *previous = NULL;
    node_t *next = NULL;
    node_t *current = *begin;

    while (current != NULL) {
        next = current->next;
        current->next = previous;
        previous = current;
        current = next;
    }
    *begin = previous;
}
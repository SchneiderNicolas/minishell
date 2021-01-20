/*
** EPITECH PROJECT, 2020
** minishell
** File description:
** print linked list
*/

#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include "my.h"
#include "struct.h"

void print_linked_list(node_t const *begin)
{
    node_t const *tmp;

    tmp = begin;
    while (tmp != NULL) {
        my_putstr(tmp->data);
        my_putchar('\n');
        tmp = tmp->next;
    }
}
/*
** EPITECH PROJECT, 2020
** minishell
** File description:
** insert node at the end of a linked list
*/

#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include "my.h"
#include "struct.h"

void insert_node_end(char *data, node_t *head)
{
    node_t *newNode;
    node_t *tmp;

    if ((newNode = malloc(sizeof(node_t))) == NULL)
        exit (84);
    if ((newNode->data = malloc(sizeof(char) * my_strlen(data))) == NULL)
        exit (84);
    newNode->data = data;
    newNode->next = NULL;
    tmp = head;
    while (tmp->next != NULL)
        tmp = tmp->next;
    tmp->next = newNode;
}
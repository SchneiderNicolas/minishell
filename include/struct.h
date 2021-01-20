/*
** EPITECH PROJECT, 2020
** minishell
** File description:
** struct.h
*/

#ifndef STRUCT_H
#define STRUCT_H

typedef struct node_s {
    char *data;
    struct node_s *next;
} node_t;

typedef struct info_s {
    char **tab;
    char **envp;
    struct node_s *ll_envp;
    char *old_pwd;
    char **path_tab;
} info_t;

#endif /* !STRUCT_H */
/*
** EPITECH PROJECT, 2020
** minishell
** File description:
** my_env
*/

#include "my.h"
#include "struct.h"

void my_env(info_t *info)
{
    print_linked_list(info->ll_envp);
    return;
}
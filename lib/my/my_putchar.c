/*
** EPITECH PROJECT, 2020
** minishell
** File description:
** my_putchar
*/

#include "my.h"
#include <unistd.h>

void my_putchar(char c)
{
    write(1, &c, 1);
}
/*
** EPITECH PROJECT, 2020
** minishell
** File description:
** is_num
*/

int is_num(char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if ((str[i] < '0' || str[i] > '9') && str[i] != '-')
            return (0);
    }
    return (1);
}
/*
** EPITECH PROJECT, 2020
** minishell
** File description:
** is_letter
*/

int is_letter(char c)
{
    if (c < 65 || (c > 90 && c < 97) || c > 122)
        return -1;
    return 1;
}
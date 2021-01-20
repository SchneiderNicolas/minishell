/*
** EPITECH PROJECT, 2020
** minishell
** File description:
** tab len
*/

int tab_len(char **tab)
{
    int count = 0;
    for (; tab[count]; count++);
    return (count);
}
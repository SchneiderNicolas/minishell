/*
** EPITECH PROJECT, 2019
** minishell
** File description:
** my_intlen
*/

int my_intlen(int nb)
{
    int count = 1;

    if (nb < 1)
        count += 1;
    while (nb / 10 != 0) {
        count += 1;
        nb = nb / 10;
    }
    return (count);
}
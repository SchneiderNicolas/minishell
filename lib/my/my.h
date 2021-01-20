/*
** EPITECH PROJECT, 2020
** minishell
** File description:
** my.h
*/

#include "struct.h"

#ifndef MY_H
    #define MY_H

unsigned int my_strlen(char const *str);
void my_putstr(char const *str);
void my_putchar(char c);
void my_putnbr(long long int nb);
void my_puterr(char const *str);
char *fs_cat_x_bytes(char const *filepath, int *size);
int my_getnbr(char const *str);
int my_intlen(int nb);
char *my_revstr(char *str);
char *my_strcat(char *str1, char *str2);
char *my_strdup(char const *src);
void my_swapchar(char *a, char *b);
char *tab_to_str(int **map, int line, int column);
int my_strncmp(char const *s1, char const *s2, int n);
char **my_str_to_word_array(char *str, char separator);
char **input(char **tab);
int my_strcmp(char *str1, char *str2);
node_t *init_linked_list(char **envp);
int my_strcmp_equal(char *str1, char *str2);
void delete_node(node_t **head_ref, char *key);
void insert_node_end(char *data, node_t *head);
void my_rev_list(node_t **begin);
void print_linked_list(node_t const *begin);
void cd_error_handling(char **tab);
char *get_user(info_t *info);
void change_pwd(info_t *info);
void get_old_pwd(info_t *info, char * pwd);
void cd(info_t *info);
int tab_len(char **tab);
int is_num(char *str);
void my_env(info_t *info);
void my_exit(info_t *info);
int check_and_change_env(info_t *info);
void my_setenv(info_t *info);
int is_letter(char c);
int my_isalnum(info_t *info);
void change_pwd(info_t *info);
void get_old_pwd(info_t *info, char * pwd);
int check_slash(char *str);
void get_path(info_t *info);
void execve_options(info_t *info);
void my_exec(info_t *info);

#endif
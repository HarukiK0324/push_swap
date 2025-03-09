/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haruki <haruki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 21:42:28 by haruki            #+#    #+#             */
/*   Updated: 2025/03/09 21:46:55 by haruki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

typedef struct s_node
{
    int data;
    struct s_node *next;
    struct s_node *prev;
}               t_node;

typedef struct s_stack
{
    int size;
    t_node *top;
    t_node *bottom;
}               t_stack;

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int	ft_strcmp(const char *s1, const char *s2);
int ft_strlen(char *str);
int to_int(char *str);
void error();
int check_error(char *num);
int check_dup(int size,char **arr);
void push_back(t_stack *stack,int data);
void free_stack(t_stack *stack);
t_stack *init_stack();
t_stack *indexing(t_stack *stack);

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haruki <haruki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 21:42:28 by haruki            #+#    #+#             */
/*   Updated: 2025/03/23 12:56:40 by haruki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

typedef struct s_node
{
	int				data;
	struct s_node	*next;
	struct s_node	*prev;
}					t_node;

typedef struct s_stack
{
	int				size;
	t_node			*top;
	t_node			*bottom;
}					t_stack;

# include "../libftprintf/ft_printf.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

int					ft_strcmp(const char *s1, const char *s2);
int					to_int(char *str);
unsigned int		size_of(char const *s);
void				error(void);
int					check_error(char *num);
int					check_dup(int size, char **arr);
void				push_back(t_stack *stack, int data);
void				free_stack(t_stack *stack);
t_stack				*init_stack(void);
t_stack				*indexing(t_stack *stack, int size);
void				swap(t_stack *stack, char c);
void				rotate(t_stack *stack, char c);
void				reverse_rotate(t_stack *stack, char c);
void				push(t_stack *stack_a, t_stack *stack_b, char c);
char				*ft_strdup(const char *s);
int					find_num(t_stack *stack_b, int num);
void				rotate_find(t_stack *stack_a, t_stack *stack_b, int num,
						void (*f)(t_stack *, char));
void				insertion_sort(t_stack *stack_a, t_stack *stack_b);
void				push_to_b(t_stack *stack_a, t_stack *stack_b, int chunk);
void				push_swap(t_stack *stack_a, int size);
void				sort_three(t_stack *stack_a);
void				small_sort(t_stack *stack_a);
void				store_cmd(char *cmd);
void				push_front(t_stack *stack, int data);
void				*init_string(char *str, char *prev_cmd);
int					min(int a, int b);
int					max(int a, int b);
int is_sorted(t_stack *stack);

#endif
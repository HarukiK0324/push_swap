/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haruki <haruki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 21:42:28 by haruki            #+#    #+#             */
/*   Updated: 2025/03/09 21:44:25 by haruki           ###   ########.fr       */
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


#endif
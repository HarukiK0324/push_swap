/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haruki <haruki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 22:00:39 by haruki            #+#    #+#             */
/*   Updated: 2025/03/13 19:33:51 by haruki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void swap(t_stack *stack)
{
    t_node *first;
    t_node *second;

    if(stack->size <= 1)
        return ;
    first = stack->top;
    second = stack->top->next;
    stack->bottom->next = second;
    second->prev = stack->bottom;
    first->next = second->next;
    second->next->prev = first;
    second->next = first;
    first->prev = second;
    stack->top = second;
}

void rotate(t_stack *stack)
{
    if(stack->size <= 1)
        return ;
    stack->bottom = stack->top;
    stack->top = stack->top->next;
}

void reverse_rotate(t_stack *stack)
{
    if(stack->size <= 1)
        return ;
    stack->top = stack->bottom;
    stack->bottom = stack->bottom->prev;
}

void push(t_stack *stack_a,t_stack *stack_b)
{
    t_node *tmp;

    if(stack_a->size == 0)
        return ;
    tmp = stack_a->top;
    if(stack_a->size == 1)
    {
        stack_a->top = NULL;
        stack_a->bottom = NULL;
    }
    else
    {
        stack_a->top = stack_a->top->next;
        stack_a->bottom->next = stack_a->top;
        stack_a->top->prev = stack_a->bottom;
    }
    push_back(stack_b,tmp->data);
    free(tmp);
    stack_a->size--;
    reverse_rotate(stack_b);
}
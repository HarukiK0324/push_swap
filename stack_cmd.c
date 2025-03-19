/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haruki <haruki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 22:00:39 by haruki            #+#    #+#             */
/*   Updated: 2025/03/19 14:59:14 by haruki           ###   ########.fr       */
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
    if(stack->size ==2)
    {
        stack->top = second;
        stack->bottom = first;
        return ;
    }
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
    push_front(stack_b,tmp->data);
    free(tmp);
    stack_a->size--;
}

void push_front(t_stack *stack,int data)
{
    t_node *new_node;

    new_node = (t_node *)malloc(sizeof(t_node));
    new_node->data = data;
    if(stack->size == 0)
    {
        stack->top = new_node;
        stack->bottom = new_node;
        new_node->next = new_node;
        new_node->prev = new_node;
    }
    else
    {
        new_node->next = stack->top;
        new_node->prev = stack->bottom;
        stack->top->prev = new_node;
        stack->bottom->next = new_node;
        stack->top = new_node;
    }
    stack->size++;
}
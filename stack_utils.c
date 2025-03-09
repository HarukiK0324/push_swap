/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haruki <haruki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 21:45:32 by haruki            #+#    #+#             */
/*   Updated: 2025/03/09 21:45:43 by haruki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void push_back(t_stack *stack,int data)
{
    t_node *new_node;

    new_node = (t_node *)malloc(sizeof(t_node));
    new_node->data = data;
    new_node->next = NULL;
    if(stack->size == 0)
    {
        stack->top = new_node;
        stack->bottom = new_node;
    }
    else
    {
        stack->bottom->next = new_node;
        new_node->prev = stack->bottom;
        stack->bottom = new_node;
    }
    stack->size++;
}

void free_stack(t_stack *stack)
{
    t_node *tmp;

    while(stack->top != NULL)
    {
        tmp = stack->top;
        stack->top = stack->top->next;
        free(tmp);
    }
    free(stack);
}

t_stack *init_stack()
{
    t_stack *stack;

    stack = (t_stack *)malloc(sizeof(t_stack));
    stack->size = 0;
    stack->top = NULL;
    stack->bottom = NULL;
    return stack;
}

t_stack *indexing(t_stack *stack)
{
    t_stack *new_stack;
    t_node *tmp;
    t_node *num;
    int count;

    new_stack = init_stack();
    num = stack->top;
    while(num != NULL)
    {
        count = 1;
        tmp = stack->top;
        while(tmp != NULL)
        {
            if(tmp->data < num->data)
                count++;
            tmp = tmp->next;
        }
        push_back(new_stack,count);
        num = num->next;
    }
    tmp = stack->top;
    free_stack(stack);
    return new_stack;
}

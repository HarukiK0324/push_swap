/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haruki <haruki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 21:45:32 by haruki            #+#    #+#             */
/*   Updated: 2025/03/20 19:36:31 by haruki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void push_back(t_stack *stack,int data)
{
    t_node *new_node;

    new_node = (t_node *)malloc(sizeof(t_node));
    new_node->data = data;
    if(stack->size == 0)
    {
        stack->top = new_node;
        stack->bottom = new_node;
        new_node->prev = new_node;
        new_node->next = new_node;
    }
    else
    {
        stack->bottom->next = new_node;
        new_node->prev = stack->bottom;
        new_node->next = stack->top;
        stack->bottom = new_node;
        stack->top->prev = stack->bottom;
    }
    stack->size++;
}

void free_stack(t_stack *stack)
{
    t_node *tmp;

    while(stack->size > 0)
    {
        tmp = stack->top;
        stack->top = stack->top->next;
        stack->size--;
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

t_stack *indexing(t_stack *stack,int size)
{
    t_stack *new_stack;
    t_node *tmp;
    t_node *num;
    int count;

    new_stack = init_stack();
    num = stack->top;
    while(new_stack->size < size)
    {
        count = 1;
        tmp = stack->top;
        while(stack->size > 0)
        {
            if(tmp->data < num->data)
                count++;
            tmp = tmp->next;
            stack->size--;
        }
        push_back(new_stack,count);
        num = num->next;
        stack->size = size;
    }
   free_stack(stack);
    return new_stack;
}

void rotate_find(t_stack *stack_a,t_stack *stack_b,int num, void (*f)(t_stack *,char))
{
    int found;

    found = 0;
    while(stack_b->top->data != num)
    {
        if(stack_b->top->data == num -1)
        {
            push(stack_b,stack_a,'a');
            found = 1;
        }
        else
            f(stack_b,'b');
    }
    push(stack_b,stack_a,'a');
    if(found == 1)
        swap(stack_a,'a');
}

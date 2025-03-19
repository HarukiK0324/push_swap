/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haruki <haruki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 10:26:16 by haruki            #+#    #+#             */
/*   Updated: 2025/03/19 13:17:36 by haruki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void insertion_sort(t_stack *stack_a,t_stack *stack_b)
{
    while(stack_b->size > 0)
    {
        if(find_num(stack_b,stack_b->size) == 1)
            rotate_find(stack_a,stack_b,stack_b->size,&rotate);
        else
            rotate_find(stack_a,stack_b,stack_b->size,&reverse_rotate);
    }
}

void push_to_b(t_stack *stack_a,t_stack *stack_b,int chunk)
{
    int itr;

    itr = 1;
    while(stack_a->size > 0)
    {
        while(stack_b->size < chunk * itr && stack_a->size > 0)
        {
            if(stack_a->top->data <= chunk * itr)
            {
                push(stack_a,stack_b);  
                if(stack_b->top->data <= chunk * itr - chunk/2)
                    rotate(stack_b);
            }
            else
                rotate(stack_a);
        }
        itr++;
    }
}

void push_swap(t_stack *stack_a,int size)
{
    t_stack *stack_b;
    int chunk;

    chunk = size / 8;
    if(chunk == 0)
        chunk = 2;
    stack_b = init_stack();
    push_to_b(stack_a,stack_b,chunk);
    insertion_sort(stack_a,stack_b);
    free_stack(stack_a);
    free_stack(stack_b);
}

void sort_three(t_stack *stack_a)
{
    if(stack_a->top->data > stack_a->top->next->data && stack_a->top->data > stack_a->bottom->data)
            rotate(stack_a);
    else if(stack_a->top->next->data > stack_a->top->data && stack_a->top->next->data > stack_a->bottom->data)
        reverse_rotate(stack_a);
    if(stack_a->top->data > stack_a->top->next->data)
        swap(stack_a);
}

void small_sort(t_stack *stack_a)
{
    t_stack *stack_b;

    if(stack_a->size == 2 && stack_a->top->data == 2)
        swap(stack_a);
    else
    {
        while(stack_a->size > 3)
        {
            stack_b = init_stack();
            if(stack_a->top->data <= 2)
                push(stack_a,stack_b);
            else
                rotate(stack_a);
        }
        sort_three(stack_a);
        push(stack_b,stack_a);
        push(stack_b,stack_a);
        if(stack_a->top->data > stack_a->top->next->data)
            swap(stack_a);
        free_stack(stack_b);
    }
}

int main(int argc, char *argv[])
{
    t_stack *stack_a;
    int i;

    if(argc == 1 || check_dup(argc - 1,argv + 1) == -1)
        error();
    stack_a = init_stack();
    i = 0;
    while(i < argc - 1)
    {
        push_back(stack_a,to_int(argv[i+1]));
        i++;
    }
    stack_a = indexing(stack_a,argc - 1);
    if(stack_a->size < 6)
        small_sort(stack_a);
    else
        push_swap(stack_a,argc - 1);
    free_stack(stack_a);
    return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haruki <haruki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 10:26:16 by haruki            #+#    #+#             */
/*   Updated: 2025/03/09 22:21:54 by haruki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void error()
{
    write(1,"Error\n",6);
    exit(1);
}

int check_error(char *num)
{
    int i;

    i = 0;
    if((num[0] == '-' && ft_strlen(num) > 11) || (num[0] != '-' && ft_strlen(num) > 10))
        return (-1);
    if(num[0] == '-')
    {
        if(ft_strlen(num) == 11 && ft_strcmp(num,"-2147483648") > 0)
            return (-1);
    }
    else
    {
        if(ft_strlen(num) == 10 && ft_strcmp(num,"2147483647") > 0)
            return (-1);
    }
    if(num[0] == '-')
        i++;
    while(num[i] != '\0')
    {
        if(num[i] < '0' || num[i] > '9')
            return (-1);
        i++;
    }
    return (0);
}



int check_dup(int size,char **arr)
{
    int i;
    int j;

    i = 0;
    while(i < size)
    {
        if(check_error(arr[i]) == -1)
            return (-1);
        j = i + 1;
        while(j < size)
        {
            if(ft_strcmp(arr[i],arr[j]) == 0)
                return (-1);
            j++;
        }
        i++;
    }
    return (0);
}

void push_swap(t_stack *stack_a,int size)
{
    t_stack *stack_b;
    int itr;
    int chunk;

    itr = 1;
    chunk = size / 8;
    if(chunk == 0)
        chunk = 2;
    stack_b = init_stack();
    while(stack_a->size > 3)
    {
        if(stack_a->top->data <= chunk * itr)
            push(stack_a,stack_b);
        else
            rotate(stack_a);
    }
}

#include <stdio.h>


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
    stack_a = indexing(stack_a);
    push_swap(stack_a,argc - 1);
    free_stack(stack_a);
    return (0);
}

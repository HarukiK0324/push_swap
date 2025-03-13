/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haruki <haruki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 10:26:16 by haruki            #+#    #+#             */
/*   Updated: 2025/03/13 22:20:58 by haruki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void print_stack(t_stack *stack)
{
    t_node *tmp;
    int i;

    i = 0;
    tmp = stack->top;
    while(i < stack->size)
    {
        printf("%d ",tmp->data);
        tmp = tmp->next;
        i++;
    }
    printf("\n");
}

void error()
{
    write(1,"Error\n",6);
    exit(1);
}

int check_error(char *num)
{
    int i;

    i = 0;
    if((num[0] == '-' && ft_strlen(num) > 11) || (num[0] != '-' && ft_strlen(num) > 10) || num[0] == '\0')
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

int find_num(t_stack *stack_b,int num)
{
    t_node *tmp;
    int i;
    int j;

    i = 1;
    j = 1;
    tmp = stack_b->top;
    while(tmp->data != num)
    {
        tmp = tmp->next;
        i++;
    }
    tmp = stack_b->top;
    while(tmp->data != (num - 1) && stack_b->size >= 2)
    {
        tmp = tmp->next;
        j++;
    }
    if(i < j && (j < stack_b->size - i))
        return 1;
    else if(j < i && (i < stack_b->size - j))
        return 1;
    return 0;
}

void rotate_find(t_stack *stack_a,t_stack *stack_b,int num, void (*f)(t_stack *))
{
    int found;

    found = 0;
    while(stack_b->top->data != num)
    {
        if(stack_b->top->data == num -1)
        {
            push(stack_b,stack_a);
            found = 1;
        }
        else
            f(stack_b);
    }
    push(stack_b,stack_a);
    if(found == 1)
        swap(stack_a);
}

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
    // free_stack(stack_a);
    // free_stack(stack_b);
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
    stack_a = indexing(stack_a,argc - 1);
    push_swap(stack_a,argc - 1);
    return (0);
}

void store_cmd(char *cmd)
{
    static char *prev_cmd;

    if(prev_cmd == NULL)
    {
        if(cmd != NULL)
            prev_cmd = ft_strdup(cmd);
    }
    else
    {
        if((ft_strcmp(prev_cmd,"ra") == 0 && ft_strcmp(cmd,"rb") == 0)||(ft_strcmp(prev_cmd,"rb") == 0 && ft_strcmp(cmd,"ra") == 0))
            write(1,"rr\n",3);
        else if((ft_strcmp(prev_cmd,"rra") == 0 && ft_strcmp(cmd,"rrb") == 0)||(ft_strcmp(prev_cmd,"rrb") == 0 && ft_strcmp(cmd,"rra") == 0))
            write(1,"rrr\n",4);
        else
        {
            ft_printf("%s\n",prev_cmd);
            free(prev_cmd);
            prev_cmd = ft_strdup(cmd);
        }
    }
}

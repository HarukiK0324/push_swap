/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haruki <haruki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 16:07:08 by haruki            #+#    #+#             */
/*   Updated: 2025/03/20 20:08:18 by haruki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
int check_error(char *num)
{
    int i;

    i = 0;
    if((num[0] == '-' && ft_strlen(num) > 11) || (num[0] != '-' && ft_strlen(num) > 10) || num[0] == '\0')
        return (-1);
    if(num[0] == '-')
    {
        if((ft_strlen(num) == 11 && ft_strcmp(num,"-2147483648") > 0) || ft_strcmp(num,"-") == 0)
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
            if(to_int(arr[i]) == to_int(arr[j]))
                return (-1);
            j++;
        }
        i++;
    }
    return (0);
}

void store_cmd(char *cmd)
{
    static char *prev_cmd;

    if(prev_cmd == NULL && cmd != NULL)
        prev_cmd = ft_strdup(cmd);
    else
    {
        if((ft_strcmp(prev_cmd,"ra") == 0 && ft_strcmp(cmd,"rb") == 0)||(ft_strcmp(prev_cmd,"rb") == 0 && ft_strcmp(cmd,"ra") == 0))
            prev_cmd = init_string("rr\n",prev_cmd);
        else if((ft_strcmp(prev_cmd,"rra") == 0 && ft_strcmp(cmd,"rrb") == 0)||(ft_strcmp(prev_cmd,"rrb") == 0 && ft_strcmp(cmd,"rra") == 0))
            prev_cmd = init_string("rrr\n",prev_cmd);
        else
        {
            ft_printf("%s\n",prev_cmd);
            free(prev_cmd);
            if(cmd != NULL)
                prev_cmd = ft_strdup(cmd);
        }
    }
}

void *init_string(char *str,char *prev_cmd)
{
    write(1,str,ft_strlen(str));
    free(prev_cmd);
    return NULL;
}

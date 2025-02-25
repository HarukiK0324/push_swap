/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haruki <haruki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 10:26:16 by haruki            #+#    #+#             */
/*   Updated: 2025/02/26 02:30:19 by haruki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 != '\0' && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}

int ft_strlen(char *str)
{
    int i;

    i = 0;
    while(str[i] != '\0')
        i++;
    return (i);
}

void to_int(int *num,char *str)
{
    int i;
    int itr;

    i = 0;
    itr = 1;
    if(str[0] == '-')
    {
        itr = -1;
        i++;
    }
    while(str[i] != '\0')
    {
        *num = *num * 10 + itr * (str[i] - '0');
        i++;
    }
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

int *indexing(int *arr,int size)
{
    int i;
    int j;
    int count;
    int *new_arr;

    new_arr = (int *)malloc(sizeof(int) * size);
    i = 0;
    while(i < size)
    {
        count = 1;
        j = 0;
        while(j < size)
        {
            if(arr[i] > arr[j])
                count++;
            j++;
        }
        new_arr[i] = count;
        i++;
    }
    free(arr);
    return (new_arr);
}

int check_dup(int size,char **arr)
{
    int i;
    int j;

    i = 1;
    while(i < size)
    {
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

void sort(int *arr,int size)
{
    
}

int main(int argc, char *argv[])
{
    int *arr;
    int i;

    if(argc == 1 || check_dup(argc - 1,argv + 1) == -1)
        error();
    i = 1;
    while(i < argc)
    {
        if(check_error(argv[i]) == -1)
            error();
        i++;
    }
    arr = (int *)malloc(sizeof(int) * (argc - 1));
    i = 0;
    while(i < argc - 1)
    {
        to_int(&(arr[i]),argv[i+1]);
        i++;
    }
    arr = indexing(arr,argc - 1);
    sort(arr,argc - 1);
    free(arr);
    return (0);
}

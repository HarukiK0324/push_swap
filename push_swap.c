/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haruki <haruki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 10:26:16 by haruki            #+#    #+#             */
/*   Updated: 2025/02/25 21:41:35 by haruki           ###   ########.fr       */
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

int main(int argc, char *argv[])
{
    int *arr;
    int i;

    if(argc == 1)
        error();
    i = 1;
    while(i < argc)
    {
        if(check_error(argv[i]) == -1)
            error();
        i++;
    }
    arr = (int *)malloc(sizeof(int) * (argc - 1));
    while(i < argc)
    {
        to_int(&arr[i],argv[i]);
        i++;
    }
    i = 0;
    while(i < argc)
    {
        printf("%d\n",arr[i]);
        i++;
    }
    return (0);
}

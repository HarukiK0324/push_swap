/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haruki <haruki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 21:44:34 by haruki            #+#    #+#             */
/*   Updated: 2025/03/19 13:19:00 by haruki           ###   ########.fr       */
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

int to_int(char *str)
{
    int i;
    int itr;
    int num;

    num = 0;
    i = 0;
    itr = 1;
    if(str[0] == '-')
    {
        itr = -1;
        i++;
    }
    while(str[i] != '\0')
    {
        num = num * 10 + itr * (str[i] - '0');
        i++;
    }
    return (num);
}

unsigned int	size_of(char const *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strdup(const char *s)
{
	char	*ptr;
	int		i;

	ptr = malloc(size_of(s) + 1);
	i = 0;
	if (ptr == (void *)0)
		return ((void *)0);
	while (s[i] != '\0')
	{
		ptr[i] = s[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

void error()
{
    write(1,"Error\n",6);
    exit(1);
}

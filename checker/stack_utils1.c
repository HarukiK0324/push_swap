/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haruki <haruki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 16:07:08 by hkasamat          #+#    #+#             */
/*   Updated: 2025/03/31 15:08:00 by haruki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_num(t_stack *stack_b, int num)
{
	t_node	*tmp;
	int		i;
	int		j;

	i = 1;
	j = 1;
	tmp = stack_b->top;
	while (tmp->data != num)
	{
		tmp = tmp->next;
		i++;
	}
	tmp = stack_b->top;
	while (tmp->data != (num - 1) && j < stack_b->size)
	{
		tmp = tmp->next;
		j++;
	}
	if (i < stack_b->size - i)
		return (1);
	return (0);
}

int	check_error(char *num)
{
	int	i;

	i = 0;
	if ((num[0] == '-' && ft_strlen(num) > 11) || (num[0] != '-'
			&& ft_strlen(num) > 10) || num[0] == '\0')
		return (-1);
	if (num[0] == '-')
	{
		if ((ft_strlen(num) == 11 && ft_strcmp(num, "-2147483648") > 0)
			|| ft_strcmp(num, "-") == 0)
			return (-1);
		i++;
	}
	else
	{
		if (ft_strlen(num) == 10 && ft_strcmp(num, "2147483647") > 0)
			return (-1);
	}
	while (num[i] != '\0')
	{
		if (num[i] < '0' || num[i] > '9')
			return (-1);
		i++;
	}
	return (0);
}

int	check_dup(int size, char **arr)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		if (check_error(arr[i]) == -1)
			return (-1);
		j = i + 1;
		while (j < size)
		{
			if (to_int(arr[i]) == to_int(arr[j]))
				return (-1);
			j++;
		}
		i++;
	}
	return (0);
}

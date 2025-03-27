/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkasamat <hkasamat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 23:46:46 by hkasamat          #+#    #+#             */
/*   Updated: 2025/03/27 18:06:27 by hkasamat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	min(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

int	max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

int	is_sorted(t_stack *stack)
{
	t_node	*tmp;
	int		i;

	i = 0;
	tmp = stack->top;
	while (i < stack->size)
	{
		if (tmp->data != i + 1)
			return (0);
		tmp = tmp->next;
		i++;
	}
	return (1);
}

void	insertion_sort(t_stack *stack_a, t_stack *stack_b)
{
	while (stack_b->size > 0)
	{
		if (find_num(stack_b, stack_b->size) == 1)
			rotate_find(stack_a, stack_b, stack_b->size, &rotate);
		else
			rotate_find(stack_a, stack_b, stack_b->size, &reverse_rotate);
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haruki <haruki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 15:41:28 by hkasamat          #+#    #+#             */
/*   Updated: 2025/03/31 16:07:17 by haruki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void print_stack(t_stack *stack)
{
	t_node *current;
	current = stack->top;
	int i;
	i = 0;
	while(i < stack->size)
	{
		printf("%d ", current->data);
		current = current->next;
		i++;
	}
}

int	check_cmd(char *str)
{
	if (!ft_strncmp(str, "sa\n", 3) || !ft_strncmp(str, "sb\n", 3)
		|| !ft_strncmp(str, "ss\n", 3) || !ft_strncmp(str, "pa\n", 3)
		|| !ft_strncmp(str, "pb\n", 3) || !ft_strncmp(str, "ra\n", 3)
		|| !ft_strncmp(str, "rb\n", 3) || !ft_strncmp(str, "rr\n", 3)
		|| !ft_strncmp(str, "rra\n", 4) || !ft_strncmp(str, "rrb\n", 4)
		|| !ft_strncmp(str, "rrr\n", 4))
		return (1);
	return (0);
}

void	free_cmd(char **cmd, int i)
{
	int	j;

	j = 0;
	while (j < i)
	{
		free(cmd[j]);
		j++;
	}
	free(cmd);
}

void	exec_cmd(char **cmd, int i, t_stack *stack_a, t_stack *stack_b)
{
	int	j;

	j = 0;
	while (j < i)
	{
		if (!ft_strncmp(cmd[j], "sa\n", 3) || !ft_strncmp(cmd[j], "ss\n", 3))
			swap(stack_a);
		if (!ft_strncmp(cmd[j], "sb\n", 3) || !ft_strncmp(cmd[j], "ss\n", 3))
			swap(stack_b);
		if (!ft_strncmp(cmd[j], "pa\n", 3))
			push(stack_b, stack_a);
		if (!ft_strncmp(cmd[j], "pb\n", 3))
			push(stack_a, stack_b);
		if (!ft_strncmp(cmd[j], "ra\n", 3) || !ft_strncmp(cmd[j], "rr", 3))
			rotate(stack_a);
		if (!ft_strncmp(cmd[j], "rb\n", 3) || !ft_strncmp(cmd[j], "rr\n", 3))
			rotate(stack_b);
		if (!ft_strncmp(cmd[j], "rra\n", 4) || !ft_strncmp(cmd[j], "rrr\n", 4))
			reverse_rotate(stack_a);
		if (!ft_strncmp(cmd[j], "rrb\n", 4) || !ft_strncmp(cmd[j], "rrr\n", 4))
			reverse_rotate(stack_b);
		j++;
	}
}

void	check_sorted(t_stack *stack_a, t_stack *stack_b)
{
	char	**cmd;
	char	*str;
	int		i;

	i = 0;
	cmd = (char **)malloc(sizeof(char *) * 10000);
    str = get_next_line(0);
	while (str)
	{
		if(ft_strncmp(str, "EOF\n", 4) == 0)
		{
			free(str);
			break ;
		}
		if(check_cmd(str) == 0)
			return (free(str),free_cmd(cmd, i), error());
		cmd[i++] = str;
        str = get_next_line(0);
	}
	exec_cmd(cmd, i, stack_a, stack_b);
	if (is_sorted(stack_a) == 1 && stack_b->size == 0)
		write(2, "OK\n", 3);
	else
		write(2, "KO\n", 3);
	free_cmd(cmd, i);
}

int	main(int argc, char *argv[])
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		i;

	if (argc == 1)
		return (0);
	else if (check_dup(argc - 1, argv + 1) == -1)
		error();
	stack_a = init_stack();
	i = 0;
	while (i < argc - 1)
	{
		push_back(stack_a, to_int(argv[i + 1]));
		i++;
	}
	stack_a = indexing(stack_a, argc - 1);
	stack_b = init_stack();
	check_sorted(stack_a, stack_b);
    free_stack(stack_a);
	free_stack(stack_b);
	return (0);
}

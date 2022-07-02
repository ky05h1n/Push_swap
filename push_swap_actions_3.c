/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_actions_3.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enja <enja@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 19:24:44 by enja              #+#    #+#             */
/*   Updated: 2022/07/03 00:15:10 by enja             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	**check_stack_b(int **stack_b, int mid)
{
	if (stack_b[0][0] > mid && stack_b[1] != NULL)
	{
		stack_b = stack_rotate_2(stack_b);
		write(1, "rb\n", 3);
		return (stack_b);
	}
	else
		return (stack_b);
}

void	down_b(int ***stack_a, int ***stack_b)
{
	if (stack_b[0][0][0] < stack_a[0][0][0]
		&& stack_b[0][0][0] > stack_a[0][tdm(*stack_a) - 1][0])
	{
		*stack_a = stack_push_2(*stack_a, *stack_b);
		*stack_b = stack_pop_2(*stack_b);
		write(1, "pa\n", 3);
		*stack_a = stack_rotate_2(*stack_a);
		write(1, "ra\n", 3);
	}
	else
	{
		*stack_b = stack_rotate_2(*stack_b);
		write(1, "rb\n", 3);
	}
}

void	up_b(int ***stack_a, int ***stack_b)
{	
	if (stack_b[0][0][0] < stack_a[0][0][0]
		&& stack_b[0][0][0] > stack_a[0][tdm(*stack_a) - 1][0])
	{
		*stack_a = stack_push_2(*stack_a, *stack_b);
		*stack_b = stack_pop_2(*stack_b);
		write(1, "pa\n", 3);
		*stack_a = stack_rotate_2(*stack_a);
		write(1, "ra\n", 3);
	}
	else
	{
		*stack_b = stack_reverse_rotate_2(*stack_b);
		write(1, "rrb\n", 4);
	}
}

int	**check_up_or_down(int **stack, int i)
{
	int	var;

	var = stack[i][0];
	if (i > tdm(stack) / 2)
	{
		while (stack[0][0] != var)
		{
			stack = stack_reverse_rotate_2(stack);
			write(1, "rra\n", 4);
		}
	}
	else if (i <= tdm(stack) / 2)
	{
		while (stack[0][0] != var)
		{
			stack = stack_rotate_2(stack);
			write(1, "ra\n", 3);
		}
	}
	return (stack);
}

int	check_min_max(int **stack, int min, int max)
{
	int	a;

	a = 0;
	while (stack[a] != NULL)
	{
		if (stack[a][0] >= min && stack[a][0] <= max)
			return (0);
		a++;
	}
	return (1);
}

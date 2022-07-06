/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_actions_1.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zy0tsh1 <zy0tsh1@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 05:56:39 by enja              #+#    #+#             */
/*   Updated: 2022/07/06 20:26:20 by zy0tsh1          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_headers/push_swap.h"

int	**sort_action_3_num(int **stack)
{
	int	i;
	int	n;

	n = 0;
	i = tdm(stack) - 1;
	if (finished_check(stack) == 0)
		return (stack);
	if (stack[n][n] > stack[i - 1][n] && stack[n][n] < stack[i][n])
		stack_swap(stack, 0);
	else if ((stack[n][n] > stack[i - 1][n] && stack[n][n] > stack[i][n])
		&& (stack[i - 1][n] > stack[i][n]))
	{
		stack_swap(stack, 0);
		stack = stack_reverse_rotate(stack, 6);
	}
	else if (stack[n][n] > stack[i - 1][n] && stack[n][n] > stack[i][n])
		stack = stack_rotate(stack, 2);
	else if (stack[n][n] < stack[i - 1][n] && stack[n][n] < stack[i][n])
	{
		stack_swap(stack, 0);
		stack = stack_rotate(stack, 2);
	}
	else if (stack[n][n] < stack[i - 1][n] && stack[n][n] > stack[i][n])
		stack = stack_reverse_rotate(stack, 6);
	return (stack);
}

int	**sort_actions_for_4(int **stack_a, int **stack_b)
{
	int	a;

	a = -1;
	while (stack_a[++a] != NULL)
	{
		if (stack_a[a][0] == 0)
		{
			if (a > 2)
				while (stack_a[0][0] != 0)
					stack_a = stack_reverse_rotate(stack_a, 6);
			else if (a <= 2)
				while (stack_a[0][0] != 0)
					stack_a = stack_rotate(stack_a, 2);
		}
	}
	stack_b = stack_push(stack_b, stack_a);
	stack_a = stack_pop(stack_a, 5);
	stack_a = sort_action_3_num(stack_a);
	stack_a = stack_push(stack_a, stack_b);
	stack_b = stack_pop(stack_b, 4);
	free(stack_b);
	return (stack_a);
}

int	smalest(int **stack)
{
	int	n;
	int	i;

	n = 0;
	i = 1;
	while (stack[n] && stack[i])
	{
		if (stack[n][0] < stack[i][0])
			i++;
		else
		{
			n++;
			i = n + 1;
		}
		if (stack[n + 1] == NULL)
			return (stack[n][0]);
	}
	return (stack[n][0]);
}

int	**sort_actions_for_5(int **stack_a, int **stack_b)
{
	t_data3	pt;

	pt.count = 0;
	pt.a = -1;
	pt.num = smalest(stack_a);
	while (pt.count != 2 && stack_a[++pt.a] != NULL)
	{
		if (stack_a[pt.a][0] == pt.num)
		{
			pt.count++;
			if (pt.a > 2)
				while (stack_a[0][0] != pt.num)
					stack_a = stack_reverse_rotate(stack_a, 6);
			else if (pt.a <= 2)
				while (stack_a[0][0] != pt.num)
					stack_a = stack_rotate(stack_a, 2);
			stack_b = stack_push(stack_b, stack_a);
			stack_a = stack_pop(stack_a, 5);
			pt.num = smalest(stack_a);
			pt.a = -1;
		}
	}
	stack_a = sort_action_3_num(stack_a);
	stack_a = sort_action_5_num(stack_a, stack_b);
	return (stack_a);
}

int	**sort_action_5_num(int **stack_a, int **stack_b)
{
	if (stack_b[0][0] < stack_b[1][0])
		stack_swap(stack_b, 1);
	stack_a = stack_push(stack_a, stack_b);
	stack_b = stack_pop(stack_b, 4);
	stack_a = stack_push(stack_a, stack_b);
	stack_b = stack_pop(stack_b, 4);
	free(stack_b);
	return (stack_a);
}

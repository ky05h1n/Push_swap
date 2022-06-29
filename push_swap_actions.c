/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_actions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enja <enja@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 05:56:39 by enja              #+#    #+#             */
/*   Updated: 2022/06/28 23:42:16 by enja             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	**sort_action_3_num(int **stack)
{
	int	i;
	int	n;

	n = 0;
	i = tdm_arr_len(stack) - 1;
	if (finished_check(stack) == 0)
		return (stack);
	if (stack[n][n] > stack[i - 1][n] && stack[n][n] < stack[i][n])
		stack_swap(stack, 0);
	else if ((stack[n][n] > stack[i - 1][n] && stack[n][n] > stack[i][n]) &&
	(stack[i - 1][n] > stack[i][n]))
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
	return (stack_a);
}

int	**sort_actions_for_5(int **stack_a, int **stack_b)
{
	int	a;
	int	num;
	int	count;

	count = 0;
	a = -1;
	num = 0;
	while (stack_a[++a] != NULL)
	{
		if (stack_a[a][0] == num)
		{
			count++;
			if (a > 2)
				while (stack_a[0][0] != num)
					stack_a = stack_reverse_rotate(stack_a, 6);		
			else if (a <= 2)
				while (stack_a[0][0] != num)
					stack_a = stack_rotate(stack_a, 2);
			stack_b = stack_push(stack_b, stack_a);
			stack_a = stack_pop(stack_a, 5);
			num = 1;
			a = -1;
		}
		if (count == 2)
			break ;
	}
	stack_a = sort_action_3_num(stack_a);
	stack_a = sort_action_5_num(stack_a, stack_b);
	return (stack_a);
}

int	**sort_action_5_num(int **stack_a, int **stack_b)
{
	if (stack_b[0][0] == 0)
		stack_swap(stack_b, 1);
	stack_a = stack_push(stack_a, stack_b);
	stack_b = stack_pop(stack_b, 4);
	stack_a = stack_push(stack_a, stack_b);
	stack_b = stack_pop(stack_b, 4);
	return (stack_a);
}


 
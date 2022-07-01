/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_actions_3.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enja <enja@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 19:24:44 by enja              #+#    #+#             */
/*   Updated: 2022/06/30 20:04:03 by enja             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	**rotate_up(int **stack, int i, int sign)
{
	int	var;

	var = stack[i][0];
	while (stack[0][0] != var)
		stack = stack_rotate(stack, sign);
	return (stack);
}

int	**rotate_down(int **stack, int i, int sign)
{
	int	var;

	var = stack[i][0];
	while (stack[0][0] != var)
		stack = stack_reverse_rotate(stack, sign);
	return (stack);
}

int	**check_stack_b(int **stack_b, int mid)
{
	if (stack_b[0][0] > mid && stack_b[1] != NULL)
		stack_b = stack_rotate(stack_b, 3);
	return (stack_b);
}

int	**check_up_or_down(int **stack, int i)
{
	if (i >= tdm_arr_len(stack) / 2)
		stack = rotate_down(stack, i, 6);
	else if (i < tdm_arr_len(stack) / 2)
		stack = rotate_up(stack, i, 2);
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

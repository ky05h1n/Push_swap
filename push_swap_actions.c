/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_actions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enja <enja@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 05:56:39 by enja              #+#    #+#             */
/*   Updated: 2022/06/27 09:22:46 by enja             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	**sort_action_3_num(int **stack_a, int **stack_b)
{
	stack_b = stack_push(stack_b, stack_a)
}


int	**sort_action_3_num(int **stack)
{
	int	i;
	int	n;

	n = 0;
	i = tdm_arr_len(stack) - 1;
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
	{
		stack = stack_reverse_rotate(stack, 6);
	}
	return (stack);
}

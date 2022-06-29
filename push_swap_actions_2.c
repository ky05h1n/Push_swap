/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_actions_2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enja <enja@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 19:00:32 by enja              #+#    #+#             */
/*   Updated: 2022/06/29 23:09:11 by enja             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	**rotate_up(int **stack_a, int i)
{
	int	var;

	var = stack_a[i][0];
	while (stack_a[0][0] != var)
		stack_a = stack_rotate(stack_a, 2);
	return (stack_a);
}

int	**rotate_down(int **stack_a, int i)
{
	int	var;

	var = stack_a[i][0];
	while (stack_a[0][0] != var)
		stack_a = stack_reverse_rotate(stack_a, 6);
	return (stack_a);
}

int	**check_stack_b(int **stack_b, int mid)
{
	if (stack_b[0][0] > mid && stack_b[1] != NULL)
		stack_b = stack_rotate(stack_b, 3);
	return (stack_b);
}

int	**sort_stack(int **stack_a, int **stack_b)
{
	int	min;
	int	max;
	int	mid;
	int	i;

	min = 0;
	max = (tdm_arr_len(stack_a) - 5) / 4 + 1;
	mid = (min + max) / 2;
	printf("--> %d\n", max);
	while (tdm_arr_len(stack_a) > 5)
	{
		i = 0;
		while (stack_a[i] != NULL)
		{
			if (stack_a[i][0] >= min && stack_a[i][0] <= max)
			{
				printf("first --> %d\n", stack_a[i][0]);
				exit(1);
				if (i <= tdm_arr_len(stack_a) / 2)
					stack_a = rotate_up(stack_a, i);
				if (i > tdm_arr_len(stack_a) / 2)
					stack_a = rotate_down(stack_a, i);
				stack_b = stack_push(stack_b, stack_a);
				stack_a = stack_pop(stack_a, 5);
				stack_b = check_stack_b(stack_b, mid);
			}
			i++;
		}
		update_range(stack_a, &max, &min, &mid);
	}
	stack_a = sort_action_5_num(stack_a, stack_b);
	// stack_a = sort_stack_comp(stack_a, stack_b);
	while (stack_a[i] != NULL)
	{
		printf("%d ", stack_a[i][0]);
		i++;
	}
	exit(1);
}

// int **sort_stack_comp(int **stack_a, int **stack_b)
// {
	
// }
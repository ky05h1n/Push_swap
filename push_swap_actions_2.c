/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_actions_2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enja <enja@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 19:00:32 by enja              #+#    #+#             */
/*   Updated: 2022/07/01 13:07:34 by enja             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	**check_up_or_down_b(int **stack, int i)
{
	if (i >= tdm_arr_len(stack) / 2)
		stack = rotate_down(stack, i, 3);
	else if (i < tdm_arr_len(stack) / 2)
		stack = rotate_up(stack, i, 7);
	return (stack);
}

int	**sort_action_all(int **stack_a, int **stack_b)
{
	int	n;

	n = 0;
	// printf("%d", stack_a[m][0] + 1);
	// exit(1);
	// while (stack_b[n] != NULL)
	// {
	// 	printf("%d ", stack_b[n][0]);
	// 	n++;
	// }
	// printf ("\n");
	// n = 0;
	// while (stack_a[n] != NULL)
	// {
	// 	printf("%d ", stack_a[n][0]);
	// 	n++;
	// }
	// exit(1);
	while (stack_b[n] != NULL)
	{
		if (stack_a[0][0] + 1 == stack_b[n][0])
		{
			stack_b = check_up_or_down_b(stack_b, n);
			stack_a = stack_push(stack_a, stack_b);
			stack_b = stack_pop(stack_b, 4);
			exit(1);
		}
		if (stack_b[n] == NULL && stack_b[0] != NULL)
			n = 0;
		n++;
	}
	return (stack_a);
}

int **first_move_check(int **stack, int min, int max)
{
	int i;

	i = 0;
	while (stack)
}

int	**sort_stack(int **stack_a, int **stack_b, int **stack_hold)
{
	int	min;
	int	max;
	int	mid;
	int	count;
	int	i = 0;

	(void)stack_hold;
	count = 0;
	min = 0;
	max = ((tdm_arr_len(stack_a) - 5) / 5) + 1;
	mid = (min + max) / 2;
	while (tdm_arr_len(stack_a) > 5)
	{
		i = i % tdm_arr_len(stack_a);
		if (stack_a[i][0] >= min && stack_a[i][0] <= max)
		{
			stack_a = first_move_check(stack_a, min, max);
			stack_b = stack_push(stack_b, stack_a);
			stack_a = stack_pop(stack_a, 5);
			stack_b = check_stack_b(stack_b, mid);
			i = 0;
		}
		if (check_min_max(stack_a, min, max) == 1)
		{
			// printf("min = %d | max = %d\n", min, max);
			update_range(stack_a, &max, &min, &mid);
			i = 0;
		}
		i++;
	}
	i = 0;
	stack_a = sort_actions_for_5(stack_a, stack_hold);
	stack_a = sort_action_all(stack_a, stack_b);
	// while (stack_b[i] != NULL)
	// {
	// 	printf("%d ", stack_b[i][0]);
	// 	i++;
	// }
	return (stack_a);
}
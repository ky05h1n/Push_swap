/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_actions_2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enja <enja@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 19:00:32 by enja              #+#    #+#             */
/*   Updated: 2022/07/02 23:52:30 by enja             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	bigest(int **stack)
{
	int	n;
	int	i;

	n = 0;
	i = 1;
	while (stack[n] && stack[i])
	{
		if (stack[n][0] > stack[i][0])
			i++;
		else
		{
			n++;
			i = n + 1;
		}
		if (stack[n + 1] == NULL)
			return (n);
	}
	return (n);
}

int	searsh_for_num(int **stack_a, int **stack_b)
{
	int	var;
	int	i;

	i = 0;
	var = stack_a[0][0] - 1;
	while (stack_b[i] != NULL)
	{
		if (stack_b[i][0] == var)
			return (1);
		i++;
	}
	return (0);
}

void	test(int ***stack_a, int ***stack_b)
{
	(void)stack_b;
	*stack_a = stack_reverse_rotate_2(*stack_a);
}

int	**sort_action_all(int **stack_a, int **stack_b)
{
	int	i;
	int n;
	// int num1;
	// int num2;
	// int num3;
	i = stack_a[tdm_arr_len(stack_a) - 1][0];
	stack_a[tdm_arr_len(stack_a) - 1][0] = -1;
	n = 0;
	while (stack_b[0] || finished_check(stack_a) == 1)
	{
		while (stack_b[n] && stack_a[0][0] - 1 != stack_b[n][0])
			n++;
		if (searsh_for_num(stack_a, stack_b) == 0)
		{
			stack_a = stack_reverse_rotate_2(stack_a);
			write(1, "rra\n", 4);
		}
		if (stack_b[n] && n > tdm_arr_len(stack_b) / 2 && stack_a[0][0] - 1 == stack_b[n][0])
		{
			while(stack_a[0][0] - 1 != stack_b[0][0])
				up_b(&stack_a, &stack_b);
			stack_a = stack_push_2(stack_a, stack_b);
			stack_b = stack_pop_2(stack_b);
			write(1, "pa\n", 3);
		}
		else if (stack_b[n] && n <= tdm_arr_len(stack_b) / 2 && stack_a[0][0] - 1 == stack_b[n][0])
		{
			while(stack_a[0][0] - 1 != stack_b[0][0])
				down_b(&stack_a, &stack_b);
			stack_a = stack_push_2(stack_a, stack_b);
			stack_b = stack_pop_2(stack_b);
			write(1, "pa\n", 3);
		}
		n = 0;
	}
	// printf("%d\n", stack_a[tdm_arr_len(stack_a) - 1][0]);
	// while (stack_b[0])
	// {
	// 	if (stack_a)
	// }
	return (stack_a);
}

int	**first_move_check(int **stack, int min, int max)
{
	int	i;
	int	count;
	int	size;

	i = 0;
	size = tdm_arr_len(stack) - 1;
	count = 0;
	while (1)
	{
		if (stack[i][0] >= min && stack[i][0] <= max)
			break ;
		i++;
	}
	while (1)
	{	
		if (stack[size][0] >= min && stack[size][0] <= max)
			break ;
		else
		{
			size--;
			count++;
		}
	}
	if (i == count || stack[i][0] == stack[size][0])
		stack = check_up_or_down(stack, i);
	else if (i < count)
		stack = check_up_or_down(stack, i);
	else if (count < i)
		stack = check_up_or_down(stack, size);
	return (stack);
}

int	**sort_stack(int **stack_a, int **stack_b, int **stack_hold)
{
	int	min;
	int	max;
	int	mid;
	int	count;
	// int	i = 0;
	// int size;

	(void)stack_hold;
	count = 0;
	min = 0;
	max = ((tdm_arr_len(stack_a) - 5) / 2) + 1;
	mid = (min + max) / 2;
	while (tdm_arr_len(stack_a) > 5)
	{
		if (check_min_max(stack_a, min, max) == 0)
		{
			stack_a = first_move_check(stack_a, min, max);
			stack_b = stack_push_2(stack_b, stack_a);
			stack_a = stack_pop_2(stack_a);
			write(1, "pb\n", 3);
			stack_b = check_stack_b(stack_b, mid);
		}
		else if (check_min_max(stack_a, min, max) == 1)
		{
			update_range(stack_a, &max, &min, &mid);
		}
	}
	stack_a = sort_actions_for_5(stack_a, stack_hold);
	stack_a = sort_action_all(stack_a, stack_b);
	// i = 0;
	// while (stack_a[i] != NULL)
	// {
	// 	printf("%d ", stack_a[i][0]);
	// 	i++;
	// }
	// printf("\n");
	// i = 0;
	// while (stack_b[i] != NULL)
	// {
	// 	printf("%d ", stack_b[i][0]);
	// 	i++;
	// }
	// size = tdm_arr_len(stack_b);
	// printf("%d", size);
	// exit(1);
	return (stack_a);
}
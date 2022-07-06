/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_actions_2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zy0tsh1 <zy0tsh1@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 19:00:32 by enja              #+#    #+#             */
/*   Updated: 2022/07/06 20:26:24 by zy0tsh1          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_headers/push_swap.h"

int	last_finished_check(int **stack, int ***stack_b)
{
	int	ndx;
	int	idx;

	ndx = 0;
	idx = 1;
	while (stack[idx] != NULL)
	{
		if (stack[ndx][0] < stack[idx++][0])
			ndx++;
		else
			return (1);
	}
	free(*stack_b);
	return (0);
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

int	**sort_action_all(int **st_a, int **st_b)
{
	int	n;

	st_a[tdm(st_a) - 1][0] = -1;
	n = 0;
	while (st_b[0] || last_finished_check(st_a, &st_b) == 1)
	{
		while (st_b[n] && st_a[0][0] - 1 != st_b[n][0])
			n++;
		if (searsh_for_num(st_a, st_b) == 0)
			instruction_rra(&st_a);
		if (st_b[n] && n > tdm(st_b) / 2 && st_a[0][0] - 1 == st_b[n][0])
		{
			while (st_a[0][0] - 1 != st_b[0][0])
				up_b(&st_a, &st_b);
			instruction_pa(&st_a, &st_b);
		}
		else if (st_b[n] && n <= tdm(st_b) / 2 && st_a[0][0] - 1 == st_b[n][0])
		{
			while (st_a[0][0] - 1 != st_b[0][0])
				down_b(&st_a, &st_b);
			instruction_pa_2(&st_a, &st_b);
		}
		n = 0;
	}
	return (st_a);
}

int	**first_move_check(int **stack, int min, int max)
{
	int	i;
	int	count;
	int	size;

	i = 0;
	size = tdm(stack) - 1;
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
		size--;
		count++;
	}
	if (i <= count)
		stack = check_up_or_down(stack, i);
	else if (count < i)
		stack = check_up_or_down(stack, size);
	return (stack);
}

int	**sort_stack_for_100(int **stack_a, int **stack_b, int **stack_hold)
{
	int	min;
	int	max;
	int	mid;

	min = 0;
	max = ((tdm(stack_a) - 5) / 2) + 1;
	mid = (min + max) / 2;
	while (tdm(stack_a) > 5)
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
			update_range_for_100(stack_a, &max, &min, &mid);
	}
	stack_a = sort_actions_for_5(stack_a, stack_hold);
	stack_a = sort_action_all(stack_a, stack_b);
	stack_a = stack_rotate_2(stack_a);
	write(1, "ra\n", 3);
	return (stack_a);
}

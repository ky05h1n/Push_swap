/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_actions_4.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zy0tsh1 <zy0tsh1@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 21:40:38 by enja              #+#    #+#             */
/*   Updated: 2022/07/06 20:26:36 by zy0tsh1          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_headers/push_swap.h"

int	**sort_stack_for_500(int **stack_a, int **stack_b, int **stack_hold)
{
	int	min;
	int	max;
	int	mid;

	min = 0;
	max = ((tdm(stack_a) - 5) / 4) + 1;
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
			update_range_for_500(stack_a, &max, &min, &mid);
	}
	stack_a = sort_actions_for_5(stack_a, stack_hold);
	stack_a = sort_action_all(stack_a, stack_b);
	stack_a = stack_rotate_2(stack_a);
	write(1, "ra\n", 3);
	return (stack_a);
}

void	instruction_pa(int ***st_a, int ***st_b)
{
	*st_a = stack_push_2(*st_a, *st_b);
	*st_b = stack_pop_2(*st_b);
	write(1, "pa\n", 3);
}

void	instruction_pa_2(int ***st_a, int ***st_b)
{
	*st_a = stack_push_2(*st_a, *st_b);
	*st_b = stack_pop_2(*st_b);
	write(1, "pa\n", 3);
}

void	instruction_rra(int ***st_a)
{
	*st_a = stack_reverse_rotate_2(*st_a);
	write(1, "rra\n", 4);
}

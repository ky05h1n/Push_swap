/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_actions_0.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enja <enja@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 01:45:16 by enja              #+#    #+#             */
/*   Updated: 2022/07/03 02:15:39 by enja             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error_msg(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

void	update_range_for_100(int **stack_a, int *max, int *min, int *mid)
{
	*min = *max;
	*max += ((tdm(stack_a) - 5) / 2) + 1;
	*mid = (*min + *max) / 2;
}

void	update_range_for_500(int **stack_a, int *max, int *min, int *mid)
{
	*min = *max;
	*max += ((tdm(stack_a) - 5) / 4) + 1;
	*mid = (*min + *max) / 2;
}

int	**first_action(int **stack_a, int **stack_b, int **stack_hold, int ac)
{
	if (ac == 3)
		stack_swap(stack_a, 0);
	else if (ac == 4)
		stack_a = sort_action_3_num(stack_a);
	else if (ac == 5)
		stack_a = sort_actions_for_4(stack_a, stack_b);
	else if (ac == 6)
		stack_a = sort_actions_for_5(stack_a, stack_b);
	else if (ac < 150)
		stack_a = sort_stack_for_100(stack_a, stack_b, stack_hold);
	else
		stack_a = sort_stack_for_500(stack_a, stack_b, stack_hold);
	return (stack_a);
}

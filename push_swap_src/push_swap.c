/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zy0tsh1 <zy0tsh1@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 22:41:20 by enja              #+#    #+#             */
/*   Updated: 2022/07/06 20:26:55 by zy0tsh1          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_headers/push_swap.h"

int	**sort_args(int **stack, int ac)
{
	int	i;
	int	j;
	int	n;

	i = 0;
	while (i < ac - 2)
	{
		j = 0;
		while (j < ac - i - 2)
		{
			if (stack[j][0] > stack[j + 1][0])
			{
				n = stack[j][0];
				stack[j][0] = stack[j + 1][0];
				stack[j + 1][0] = n;
			}
			j++;
		}
		i++;
	}
	return (stack);
}

int	**switching_args(int **stack_a, int **srt_stack, int ac)
{
	int	i;
	int	n;
	int	*new_stack;

	i = 0;
	new_stack = malloc((ac - 1) * sizeof(int));
	while (srt_stack[i])
	{
		n = 0;
		while (srt_stack[i] && stack_a[n])
		{
			if (srt_stack[i][0] == stack_a[n][0])
				new_stack[n] = i++;
			n++;
		}
	}
	i = 0;
	while (i < ac - 1)
	{
		stack_a[i] = &new_stack[i];
		i++;
	}
	return (stack_a);
}

int	main(int ac, char **av)
{
	int	*bloc;
	int	**stack_a;
	int	**stack_b;
	int	**srt_stack;
	int	**stack_hold;

	if (ac > 1)
	{
		bloc = arguments_scanner(ac, av);
		check_for_sorted(bloc, ac);
		srt_stack = arg_arr(bloc, ac);
		srt_stack = sort_args(srt_stack, ac);
		bloc = arguments_scanner(ac, av);
		stack_a = arg_arr(bloc, ac);
		stack_a = switching_args(stack_a, srt_stack, ac);
		stack_b = malloc(1 * sizeof(int *));
		stack_b[0] = NULL;
		stack_hold = malloc(1 * sizeof(int *));
		stack_hold[0] = NULL;
		stack_a = first_action(stack_a, stack_b, stack_hold, ac);
	}
	return (0);
}

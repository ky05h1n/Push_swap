/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enja <enja@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 22:41:20 by enja              #+#    #+#             */
/*   Updated: 2022/07/02 23:52:35 by enja             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error_msg(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

void	update_range(int **stack_a, int *max, int *min, int *mid)
{
	*min = *max;
	*max += ((tdm_arr_len(stack_a) - 5) / 2) + 1;
	*mid = (*min + *max) / 2;
}

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
	int **stack_hold;
	// int	n;

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
		// if (ac == 3)
		// 	stack_swap(stack_a, 0);
		// if (ac == 4)
		// 	stack_a = sort_action_3_num(stack_a);
		// if (ac == 5)
		// 	stack_a = sort_actions_for_4(stack_a, stack_b);
		// if (ac == 6)
		// 	stack_a = sort_actions_for_5(stack_a, stack_b);


		// / dont forget the 7 and 6 numbers=====++++++++

		
		if (ac > 6)
		{
			stack_a = sort_stack(stack_a, stack_b, stack_hold);
			stack_a = stack_rotate_2(stack_a);
			write(1, "ra\n", 3);
		}
			
	////////////////////////////////////// --for test---
		// while (stack_a[n] != NULL)
		// {
		// 	stack_b = stack_push(stack_b, stack_a);
		// 	stack_a = stack_pop(stack_a, 5);
		// }
		// n = 0;
		// while (stack_b[n] != NULL)
		// {
		// 	printf("%d ", stack_b[n][0]);
		// 	n++;
		// }
		// n = 0;
		// printf("\n");
		// while (stack_b[n] != NULL)
		// {
		// 	stack_a = stack_push(stack_a, stack_b);
		// 	stack_b = stack_pop(stack_b, 4);
		// // }
		// n = 0;
		// // // // // // // printf("%d ", srt_stack[2][0]);
		// while (stack_a[n] != NULL)
		// {
		// 	printf("%d ", stack_a[n][0]);
		// 	n++;
		// }
		// system("leaks push_swap");
		// while (1)
		// 	;
	 }
	return (0);
}
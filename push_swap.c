/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enja <enja@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 22:41:20 by enja              #+#    #+#             */
/*   Updated: 2022/06/27 09:21:29 by enja             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	int	*bloc;
	int	**stack_a;
	int	**stack_b;
	// int	n = 0;

	(void)stack_b;
	if (ac > 1)
	{
		bloc = arguments_scanner(ac, av);
		check_for_sorted(bloc, ac);
		stack_a = arg_arr(bloc, ac);
		stack_b = malloc(1 * sizeof(int *));
		stack_b[0] = NULL;
		if (ac == 3)
			stack_swap(stack_a, 0);
		if (ac == 4)
			stack_a = sort_action_3_num(stack_a);
		if (ac == 6)
			stack_a = sort_action_5_num(stack_a, stack_b);
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
		// }
		// n = 0;
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
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enja <enja@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 22:41:20 by enja              #+#    #+#             */
/*   Updated: 2022/06/26 07:49:40 by enja             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	bloc_free(int **bloc)
{
	int	a;

	a = 0;
	while (bloc[a] != NULL)
		free(bloc[a++]);
	free(bloc);
}

int	main(int ac, char **av)
{
	int	*bloc;
	int	**stack_a;
	int	**stack_b;
	int	n = 0;

	(void)stack_b;
	if (ac > 1)
	{
		bloc = arguments_scanner(ac, av);
		check_for_sorted(bloc, ac);
		stack_a = arg_arr(bloc, ac);
		stack_b = malloc(1 * sizeof(int *));
		stack_b[0] = NULL;
		// if (ac == 3)
		// // stack_a = stack_rotate(stack_a, 1);
		while (stack_a[n] != NULL)
		{
			stack_b = take_push(stack_b, stack_a);
			stack_a = pop_stack(stack_a);
		}
		n = 0;
		while (stack_b[n] != NULL)
		{
			printf("%d ", stack_b[n][0]);
			n++;
		}
		n = 0;
		printf("\n");
		while (stack_b[n] != NULL)
		{
			stack_a = take_push(stack_a, stack_b);
			stack_b = pop_stack(stack_b);
		}
		n = 0;
		while (stack_a[n] != NULL)
		{
			printf("%d ", stack_a[n][0]);
			n++;
		}
		// system("leaks push_swap");
		// while (1)
		// 	;
	}
	return (0);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enja <enja@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 22:41:20 by enja              #+#    #+#             */
/*   Updated: 2022/06/24 05:45:37 by enja             ###   ########.fr       */
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
	int	**full_bloc;

	if (ac > 1)
	{
		bloc = arguments_scanner(ac, av);
		check_for_sorted(bloc, ac);
		full_bloc = arg_arr(bloc, ac);
		if (ac == 3)
		{
			stack_swap_sa(full_bloc);
			exit(1);
			free(bloc);
		}
		// full_bloc = stack_swap_ra(full_bloc);
		// free(bloc);
		// bloc_free(full_bloc);
		while (1)
			;
	}
	return (0);
}

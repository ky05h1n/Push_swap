/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enja <enja@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 22:41:20 by enja              #+#    #+#             */
/*   Updated: 2022/06/22 04:53:27 by enja             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	int	*bloc;
	int	a;

	(void)ac;
	(void)av;
	a = 0;
	if (ac != 2)
	{
		bloc = arguments_scanner(ac, av);
		check_for_sorted(bloc, ac);
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_instructions.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enja <enja@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 03:59:31 by enja              #+#    #+#             */
/*   Updated: 2022/06/24 05:10:57 by enja             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_swap_sa(int **bloc_stack)
{
	int		idx;
	int		*ptr;

	idx = 0;
	ptr = bloc_stack[idx];
	bloc_stack[idx] = bloc_stack[idx + 1];
	bloc_stack[idx + 1] = ptr;
	write(1, "sa\n", 3);
}

int	**stack_swap_ra(int **bloc_stack)
{
	int		**handl_stack;
	int		idx;
	int		size;

	idx = 1;
	size = tdm_arr_len(bloc_stack) + 1;
	handl_stack = malloc(size * sizeof(int *));
	size = 0;
	while (bloc_stack[idx] != NULL)
	{
		handl_stack[size] = bloc_stack[idx];
		idx++;
		size++;
	}
	handl_stack[idx] = NULL;
	handl_stack[idx - 1] = bloc_stack[0];
	bloc_stack = handl_stack;
	write(1, "ra\n", 3);
	return (bloc_stack);
}

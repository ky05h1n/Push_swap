/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_instructions.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enja <enja@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 03:59:31 by enja              #+#    #+#             */
/*   Updated: 2022/06/26 07:44:37 by enja             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	**take_push(int **stack1, int **stack2)
{
	int	**new_stack;
	int	size;
	int	idx;
	int	ndx;

	ndx = 0;
	idx = 0;
	size = tdm_arr_len(stack1) + 2;
	new_stack = malloc(size * sizeof(int *));
	new_stack[size - 1] = NULL;
	new_stack[idx] = stack2[idx];
	if (tdm_arr_len(stack1) == 0)
	{
		free(stack1);
		stack1 = new_stack;
		return (stack1);
	}
	idx++;
	while (idx < size - 1)
		new_stack[idx++] = stack1[ndx++];
	new_stack[idx] = NULL;
	free(stack1);
	stack1 = new_stack;
	return (stack1);
}

int	**pop_stack(int **stack)
{
	int	a;
	int	size;
	int	**stack_pop;
	int	m;

	a = 0;
	m = 1;
	size = tdm_arr_len(stack);
	if (size == 0)
	{
		free(stack);
		stack = malloc(1 * sizeof(int *));
		stack[0] = NULL;
		return (stack);
	}
	stack_pop = malloc(size * sizeof(int *));
	while (a < size)
		stack_pop[a++] = stack[m++];
	free(stack);
	stack = stack_pop;
	return (stack);
}

void	stack_swap(int **stack)
{
	int		idx;
	int		*ptr;

	idx = 0;
	ptr = stack[idx];
	stack[idx] = stack[idx + 1];
	stack[idx + 1] = ptr;
}

int	**stack_rotate(int **stack)
{
	int		**handl_stack;
	int		idx;
	int		size;

	idx = 1;
	size = tdm_arr_len(stack) + 1;
	handl_stack = malloc(size * sizeof(int *));
	size = 0;
	while (stack[idx] != NULL)
	{
		handl_stack[size] = stack[idx];
		idx++;
		size++;
	}
	handl_stack[idx] = NULL;
	handl_stack[idx - 1] = stack[0];
	free(stack);
	stack = handl_stack;
	return (stack);
}

int	**reverse_rotate(int	**stack)
{
	int		**handl_stack;
	int		idx;
	int		ndx;
	int		size;

	idx = 1;
	ndx = 0;
	size = tdm_arr_len(stack) + 1;
	handl_stack = malloc(size * sizeof(int *));
	while (idx < size - 1)
	{
		handl_stack[idx] = stack[ndx];
		idx++;
		ndx++;
	}
	handl_stack[idx] = NULL;
	handl_stack[0] = stack[idx - 1];
	free(stack);
	stack = handl_stack;
	return (stack);
}

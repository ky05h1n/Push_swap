/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_instructions_2.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zy0tsh1 <zy0tsh1@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 19:12:20 by enja              #+#    #+#             */
/*   Updated: 2022/07/06 20:26:47 by zy0tsh1          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_headers/push_swap.h"

int	**stack_push_2(int **stack1, int **stack2)
{
	t_data2	dt;
	t_data2	*ptr;

	ptr = &dt;
	ptr->ndx = 0;
	ptr->idx = 0;
	ptr->size = tdm(stack1) + 2;
	ptr->new_stack = malloc(ptr->size * sizeof(int *));
	ptr->new_stack[ptr->size - 1] = NULL;
	ptr->new_stack[ptr->idx] = stack2[ptr->idx];
	if (tdm(stack1) == 0)
	{
		free(stack1);
		stack1 = ptr->new_stack;
		return (stack1);
	}
	ptr->idx++;
	while (ptr->idx < ptr->size - 1)
		ptr->new_stack[ptr->idx++] = stack1[ptr->ndx++];
	ptr->new_stack[ptr->idx] = NULL;
	free(stack1);
	stack1 = ptr->new_stack;
	return (stack1);
}

int	**stack_pop_2(int **stack)
{
	int	a;
	int	size;
	int	**stack_pop;
	int	m;

	a = 0;
	m = 1;
	size = tdm(stack);
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

int	**stack_rotate_2(int **stack)
{
	int		**handl_stack;
	int		idx;
	int		size;

	idx = 1;
	size = tdm(stack) + 1;
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

int	**stack_reverse_rotate_2(int **stack)
{
	int		**handl_stack;
	int		idx;
	int		ndx;
	int		size;

	idx = 1;
	ndx = 0;
	size = tdm(stack) + 1;
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

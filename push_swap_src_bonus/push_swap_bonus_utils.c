/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zy0tsh1 <zy0tsh1@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 15:22:38 by enja              #+#    #+#             */
/*   Updated: 2022/07/06 20:27:30 by zy0tsh1          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_headers/push_swap_bonus.h"

int	string_comp_no_digits(char *str)
{
	int	ndx;

	ndx = 0;
	if (str[ndx] == '\0')
		return (-1);
	while (str[ndx])
	{
		if (ndx == 0 && (str[ndx] == '-' || str[ndx] == '+'))
			ndx++;
		if ((str[ndx] >= '0' && str[ndx] <= '9'))
			ndx++;
		else
			return (-1);
	}
	return (1);
}

int	*arguments_scanner(int ac, char **ar)
{
	t_data	fcl;
	t_data	*ptr;

	ptr = &fcl;
	ptr->r = 2;
	ptr->f = 1;
	ptr->m = 0;
	ptr->arr = malloc(ac * sizeof(int));
	while (ar[ptr->f] != NULL)
	{
		if (string_comp_no_digits(ar[ptr->f]) != 1)
			error_msg();
		if (((ar[ptr->r]) != NULL) && (string_comp_no_digits(ar[ptr->r]) != 1))
			error_msg();
		while (ar[ptr->r] != NULL)
		{
			if (string_comp(ar[ptr->f], ar[ptr->r]) != 1)
				error_msg();
			ptr->r++;
		}
		ptr->arr[ptr->m++] = my_atoi(ar[ptr->f++]);
		ptr->r = ptr->f + 1;
	}
	return (ptr->arr);
}

int	**arg_arr(int *bloc, int ac)
{
	t_lmk	data;
	t_lmk	*ptr;

	ptr = &data;
	ptr->idx = 0;
	ptr->bloc2 = malloc(ac * sizeof(int *));
	while (ptr->idx < ac - 1)
	{
		ptr->bloc2[ptr->idx] = &bloc[ptr->idx];
		ptr->idx++;
	}
	ptr->bloc2[ptr->idx] = NULL;
	return (ptr->bloc2);
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

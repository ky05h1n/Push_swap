/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enja <enja@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 22:31:49 by enja              #+#    #+#             */
/*   Updated: 2022/07/03 01:37:05 by enja             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_instractions(int sign)
{
	if (sign == 0)
		write(1, "sa\n", 3);
	else if (sign == 1)
		write(1, "sb\n", 3);
	else if (sign == 2)
		write(1, "ra\n", 3);
	else if (sign == 3)
		write(1, "rb\n", 3);
	else if (sign == 4)
		write(1, "pa\n", 3);
	else if (sign == 5)
		write(1, "pb\n", 3);
	else if (sign == 6)
		write(1, "rra\n", 4);
	else if (sign == 7)
		write(1, "rrb\n", 4);
}

int	finished_check(int **stack)
{
	int	ndx;
	int	idx;

	ndx = 0;
	idx = 1;
	while (stack[idx] != NULL)
	{
		if (stack[ndx][0] < stack[idx++][0])
			ndx++;
		else
			return (1);
	}
	return (0);
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

int	tdm(int **arr)
{
	int	a;

	if (!arr[0])
		return (0);
	a = 0;
	while (arr[a] != NULL)
		a++;
	return (a);
}

int	my_atoi(char *str)
{
	int		sign;
	long	value;
	int		range;

	sign = 1;
	value = 0;
	range = 0;
	while ((*str == ' ' || *str == '\f') || (*str == '\n' || *str == '\r')
		|| (*str == '\t' || *str == '\v'))
		str++;
	if (*str == '-')
		sign = -1;
	if (*str == '-' || *str == '+')
		++str;
	while (*str >= '0' && *str <= '9')
	{
		value = value * 10 + (*str - '0');
		str++;
		range++;
	}
	if (value * sign > 2147483647 || value * sign < -2147483648)
		error_msg();
	return (value * sign);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enja <enja@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 22:31:49 by enja              #+#    #+#             */
/*   Updated: 2022/06/24 05:15:36 by enja             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int	string_len(char *str)
{
	int	idx;

	idx = 0;
	while (str[idx])
		idx++;
	return (idx);
}

int	tdm_arr_len(int **arr)
{
	int	a;

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

void	error_msg(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

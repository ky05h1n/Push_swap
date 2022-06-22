/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arguments_checker.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enja <enja@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 14:26:00 by enja              #+#    #+#             */
/*   Updated: 2022/06/22 04:15:20 by enja             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int	string_comp_no_digits(char *str)
{
	int	ndx;
	int	s;

	s = 0;
	ndx = 0;
	if (str[ndx] == '\0')
		return (-1);
	while (str[ndx])
	{
		if (ndx == 0 && (str[ndx] == '-' || str[ndx] == '+'))
			ndx++;
		else if ((str[ndx] >= '0' && str[ndx] <= '9'))
			ndx++;
		else
			return (-1);
	}
	return (1);
}

int	string_comp(char *str1, char *str2)
{
	int	a;
	int	bloc1;
	int	bloc2;

	a = 0;
	bloc1 = my_atoi(str1);
	bloc2 = my_atoi(str2);
	if (bloc1 == bloc2)
		return (-1);
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

void	check_for_sorted(int *bloc, int ac)
{
	int idx;
	int	adx;

	idx = 0;
	adx = 1;
	while (adx < ac - 1)
	{
		if (bloc[idx] < bloc[adx++])
			idx++;
		else
			return ;
	}
	msg_sort();
}
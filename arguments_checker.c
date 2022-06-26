/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arguments_checker.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enja <enja@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 14:26:00 by enja              #+#    #+#             */
/*   Updated: 2022/06/24 23:46:36 by enja             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
		if ((str[ndx] >= '0' && str[ndx] <= '9'))
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
	int	idx;
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
	exit(1);
}

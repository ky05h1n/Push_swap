/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus_utils_2.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enja <enja@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 22:06:31 by enja              #+#    #+#             */
/*   Updated: 2022/07/04 00:09:34 by enja             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	finished_check(int **stack)
{
	int	ndx;
	int	idx;

	ndx = 0;
	idx = 1;
	if (stack[0] == NULL)
		return (0);
	while (stack[idx] != NULL)
	{
		if (stack[ndx][0] < stack[idx++][0])
			ndx++;
		else
			return (1);
	}
	return (0);
}

int	string_cmp(char *s1, char *s2)
{
	int		idx;

	idx = 0;
	while (s1[idx] && s2[idx])
	{
		if (s1[idx] == s2[idx])
				idx++;
		else
			return (1);
	}
	return (0);
}

void	msg_ok(void)
{
	write(1, "OK\n", 3);
	exit(1);
}

void	msg_ko(void)
{
	write(1, "KO\n", 3);
	exit(1);
}

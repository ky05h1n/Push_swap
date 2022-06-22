/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enja <enja@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 22:31:49 by enja              #+#    #+#             */
/*   Updated: 2022/06/22 04:33:10 by enja             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	string_len(char *str)
{
	int	idx;

	idx = 0;
	while (str[idx])
		idx++;
	return (idx);
}

void	error_msg(void)
{
	write(2, "\033[0;31mError\n", 13);
	exit(1);
}

void	msg_sort(void)
{
	write(1, "\033[0;31mThe numbers are already sorted\n", 39);
	exit(1);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enja <enja@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 14:56:34 by enja              #+#    #+#             */
/*   Updated: 2022/07/04 01:20:39 by enja             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

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

int	string_comp(char *str1, char *str2)
{
	int	bloc1;
	int	bloc2;

	bloc1 = my_atoi(str1);
	bloc2 = my_atoi(str2);
	if (bloc1 == bloc2)
		return (-1);
	return (1);
}

void	error_msg(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

int	main(int ac, char **av)
{
	int	*bloc;
	int	**stack_a;
	int	**stack_b;
	int	**srt_stack;
	int	**stack_hold;

	if (ac > 1)
	{
		bloc = arguments_scanner(ac, av);
		srt_stack = arg_arr(bloc, ac);
		srt_stack = sort_args(srt_stack, ac);
		bloc = arguments_scanner(ac, av);
		stack_a = arg_arr(bloc, ac);
		stack_a = switching_args(stack_a, srt_stack, ac);
		stack_b = malloc(1 * sizeof(int *));
		stack_b[0] = NULL;
		stack_hold = malloc(1 * sizeof(int *));
		stack_hold[0] = NULL;
		read_args(stack_a, stack_b);
		return (0);
	}
}	

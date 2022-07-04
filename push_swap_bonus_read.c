/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus_read.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enja <enja@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 17:25:32 by enja              #+#    #+#             */
/*   Updated: 2022/07/04 01:20:35 by enja             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	instructions_check_1(char *buff, int ***stack_a, int ***stack_b)
{
	if (string_cmp(buff, "rrr\n") == 0)
	{
		if (stack_a[0][0] != NULL)
			*stack_a = stack_reverse_rotate_2(*stack_a);
		if (stack_b[0][0] != NULL)
			*stack_b = stack_reverse_rotate_2(*stack_b);
		return (0);
	}
	else if (string_cmp(buff, "ss\n") == 0)
	{
		if (stack_a[0][0] != NULL && stack_a[0][1] != NULL)
			stack_swap_2(*stack_a);
		if (stack_b[0][0] != NULL && stack_b[0][1] != NULL)
			stack_swap_2(*stack_b);
		return (0);
	}
	else
		return (1);
}

int	instructions_check_2(char *buff, int ***stack_a, int ***stack_b)
{
	if (string_cmp(buff, "rr\n") == 0)
	{
		if (stack_a[0][0] != NULL)
			*stack_a = stack_rotate_2(*stack_a);
		if (stack_b[0][0] != NULL)
			*stack_b = stack_rotate_2(*stack_b);
		return (0);
	}
	else if (string_cmp(buff, "sa\n") == 0)
	{
		if (stack_a[0][0] != NULL && stack_a[0][1] != NULL)
			stack_swap_2(*stack_a);
		return (0);
	}
	else if (string_cmp(buff, "rra\n") == 0)
	{
		if (stack_a[0][0] != NULL)
			*stack_a = stack_reverse_rotate_2(*stack_a);
		return (0);
	}
	else
		return (1);
}

int	instructions_check_3(char *buff, int ***stack_a, int ***stack_b)
{
	if (string_cmp(buff, "pa\n") == 0)
	{
		if (stack_b[0][0] != NULL)
		{
			*stack_a = stack_push_2(*stack_a, *stack_b);
			*stack_b = stack_pop_2(*stack_b);
		}
		return (0);
	}
	else if (string_cmp(buff, "rrb\n") == 0)
	{
		if (stack_a[0][0] != NULL)
			*stack_b = stack_reverse_rotate_2(*stack_b);
		return (0);
	}
	else if (string_cmp(buff, "pb\n") == 0)
	{
		if (stack_a[0][0] != NULL)
		{
			*stack_b = stack_push_2(*stack_b, *stack_a);
			*stack_a = stack_pop_2(*stack_a);
		}
		return (0);
	}
	return (1);
}

void	instructions_check_4(char *buff, int ***stack_a, int ***stack_b)
{
	if (string_cmp(buff, "ra\n") == 0)
	{
		if (stack_a[0][0] != NULL)
			*stack_a = stack_rotate_2(*stack_a);
		return ;
	}
	else if (string_cmp(buff, "rb\n") == 0)
	{
		if (stack_b[0][0] != NULL)
			*stack_b = stack_rotate_2(*stack_b);
		return ;
	}
	else if (string_cmp(buff, "sb\n") == 0)
	{
		if (stack_b[0][0] != NULL && stack_b[0][1] != NULL)
			stack_swap_2(*stack_b);
		return ;
	}
	else
	{
		write(2, "Error\n", 6);
		exit(1);
	}
}

void	read_args(int **stack_a, int **stack_b)
{	
	char	*str;
	int		sign;

	while (1)
	{
		str = get_next_line(0);
		if (str == NULL)
			break ;
		sign = instructions_check_1(str, &stack_a, &stack_b);
		if (sign == 1)
			sign = instructions_check_2(str, &stack_a, &stack_b);
		if (sign == 1)
			sign = instructions_check_3(str, &stack_a, &stack_b);
		if (sign == 1)
			instructions_check_4(str, &stack_a, &stack_b);
		free(str);
	}
	if (finished_check(stack_a) == 0 && stack_b[0] == NULL)
		msg_ok();
	else
		msg_ko();
}

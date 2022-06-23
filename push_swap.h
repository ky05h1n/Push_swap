/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enja <enja@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 22:26:37 by enja              #+#    #+#             */
/*   Updated: 2022/06/23 07:52:42 by enja             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct t_data{
	int	r;
	int	f;
	int	*arr;
	int	m;
}	t_data;

// typedef struct t_node{
// 	int		data;
// 	int		index;
// 	t_node	next;
// }t_node;

int		*arguments_scanner(int ac, char **ar);
void	error_msg(void);
int		string_comp_no_digits(char *str);
int		my_atoi(char *str);
int		string_len(char *str);
void	check_for_sorted(int *bloc, int ac);
// void	stack_swap1(int *bloc_stack, int ac);
#endif
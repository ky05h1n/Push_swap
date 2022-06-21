/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enja <enja@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 22:26:37 by enja              #+#    #+#             */
/*   Updated: 2022/06/22 00:24:43 by enja             ###   ########.fr       */
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

int		*arguments_scanner(int ac, char **ar);
void	error_msg(void);
int		string_comp_no_digits(char *str);
int		my_atoi(char *str);
int		string_len(char *str);
#endif
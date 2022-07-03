/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enja <enja@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 14:57:23 by enja              #+#    #+#             */
/*   Updated: 2022/07/04 00:10:54 by enja             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include "get_next_line.h"

typedef struct t_data{
	int	r;
	int	f;
	int	*arr;
	int	m;
}t_data;

typedef struct t_lmk{
	int	idx;
	int	ndx;
	int	**bloc2;
}t_lmk;

typedef struct t_data2{
	int	**new_stack;
	int	size;
	int	idx;
	int	ndx;
}t_data2;

int		**first_action(int **stack_a, int **stack_b, int **stack_hold, int ac);
int		*arguments_scanner(int ac, char **ar);
int		**arg_arr(int *bloc, int ac);
int		**sort_args(int **stack, int ac);
int		**switching_args(int **stack_a, int **srt_stack, int ac);
void	error_msg(void);
int		string_comp_no_digits(char *str);
int		my_atoi(char *str);
int		string_comp(char *str1, char *str2);
void	instructions_check(char *buff, int ***stack_a, int ***stack_b);
void	read_args(int **stack_a, int **stack_b);
int		string_cmp(char *s1, char *s2);
int		**stack_push_2(int **stack1, int **stack2);
int		**stack_pop_2(int **stack);
int		**stack_rotate_2(int **stack);
int		**stack_reverse_rotate_2(int **stack);
void	stack_swap_2(int **stack);
int		tdm(int **arr);
int		instructions_check_1(char *buff, int ***stack_a, int ***stack_b);
int		instructions_check_2(char *buff, int ***stack_a, int ***stack_b);
int		instructions_check_3(char *buff, int ***stack_a, int ***stack_b);
void	instructions_check_4(char *buff, int ***stack_a, int ***stack_b);
int		finished_check(int **stack);
void	msg_ko(void);
void	msg_ok(void);

#endif
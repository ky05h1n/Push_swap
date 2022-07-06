/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zy0tsh1 <zy0tsh1@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 00:26:49 by enja              #+#    #+#             */
/*   Updated: 2022/07/06 20:29:06 by zy0tsh1          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_headers/get_next_line.h"

int	check_n(char *last)
{
	int	a;

	a = 0;
	if (!last)
		return (-1);
	while (last[a])
	{
		if (last[a] == '\n')
			return (a);
		a++;
	}
	return (-1);
}

char	*check_befor_n(char	*str)
{
	int		n;
	char	*exclude_n;

	n = 0;
	exclude_n = malloc(ft_strlen(str) + 1);
	while (str[n] && str[n] != '\n')
	{
			exclude_n[n] = str[n];
			n++;
	}
	exclude_n[n] = str[n];
	n++;
	exclude_n[n] = '\0';
	return (exclude_n);
}

char	*ft_strdup(char	*str)
{
	char	*dest;
	int		a;
	int		len;

	a = 0;
	len = ft_strlen(str);
	dest = malloc(len + 1 * sizeof(char));
	if (!dest)
		return (NULL);
	while (str[a])
	{
		dest[a] = str[a];
		a++;
	}
	dest[a] = '\0';
	return (dest);
}

char	*check_after_n(char *str, int len)
{
	char	*ret;

	ret = ft_strdup(str + len);
	free(str);
	return (ret);
}

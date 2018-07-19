/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_filler.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsharipo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/15 14:20:38 by rsharipo          #+#    #+#             */
/*   Updated: 2018/07/18 17:01:45 by rsharipo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdlib.h>

void	calc_shift(char *tet, t_stack *elem)
{
	int	i;
	int	j;
	int	min;

	i = 0;
	j = 0;
	min = 22;
	while (i < 20)
	{
		if (tet[i] == '#')
		{
			*(elem->coor + j) = i;
			*(elem->shift + j) = i % 5;
			j++;
		}
		i++;
	}
	i = -1;
	while (++i < 4)
		min = (*(elem->shift + i) < min) ? *(elem->shift + i) : min;
	while (--i >= 0)
		*(elem->shift + i) = *(elem->shift + i) - min;
}

int		ft_solver(t_list *data, t_stack *elem)
{
	int		i;

	i = 0;
	if (stack_len(elem) == data->num)
		return (1);
	while (i < data->num)
	{
		if (!check_elem(elem, i) && ++i)
			continue ;
		elem = add_elem(elem, i);
		if (!push_to_board(data, elem, i++))
		{
			pop_elem(&elem);
			return (0);
		}
		else
		{
			if (ft_solver(data, elem))
				return (1);
			erase_from_board(data->board, elem->change);
			pop_elem(&elem);
		}
	}
	return (0);
}

char	*ft_filler(char **input, int num)
{
	t_list	*data;
	t_stack	*elem;

	elem = NULL;
	if (!(data = malloc(sizeof(t_list)))
			|| (!(data->board = (char *)malloc(2551)) || num == 0))
		return ("Error");
	(data->board)[2550] = 0;
	data->input = input;
	data->size = sq_rt(num) * 2;
	data->num = num;
	fill_board(data);
	while (!ft_solver(data, elem))
	{
		data->size = data->size + 1;
		fill_board(data);
	}
	return (data->board);
}

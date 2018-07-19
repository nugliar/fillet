/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_board.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsharipo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/18 16:28:03 by rsharipo          #+#    #+#             */
/*   Updated: 2018/07/18 16:57:49 by rsharipo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	fill_board(t_list *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < 50)
	{
		while (j < 50)
		{
			if (i < data->size && j < data->size)
				(data->board)[i * 51 + j++] = '.';
			else
				(data->board)[i * 51 + j++] = '*';
		}
		(data->board)[i * 51 + j] = '\n';
		j = 0;
		i++;
	}
	(data->board)[i * 51] = 0;
}

int		change_board(char *board, int *change, char c)
{
	int	j;

	j = 0;
	if (!change)
		return (0);
	while (j < 4)
		board[change[j++]] = 'A' + c;
	return (1);
}

int		push_to_board(t_list *data, t_stack *elem, char x)
{
	int	i;
	int	j;
	int	line;

	i = 0;
	line = 0;
	calc_shift(*(data->input + x), elem);
	while (i / 51 < data->size)
	{
		j = 0;
		line = 0;
		while (j < 4)
		{
			if (j != 0 && (elem->coor)[j] / 5 > (elem->coor)[j - 1] / 5)
				line = line + 51;
			if ((data->board)[i + line + (elem->shift)[j]] != '.')
				break ;
			(elem->change)[j] = i + line + (elem->shift)[j];
			if (j++ == 3 && change_board(data->board, elem->change, x))
				return (1);
		}
		if (++i % 51 >= data->size)
			i = i - data->size + 51;
	}
	return (0);
}

void	erase_from_board(char *board, int *change)
{
	int	i;

	i = 0;
	while (i < 4)
		board[change[i++]] = '.';
}

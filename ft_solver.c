/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solver.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsharipo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/19 18:04:52 by rsharipo          #+#    #+#             */
/*   Updated: 2018/07/21 15:40:02 by rsharipo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

void	create_board(t_list *data)
{
	char	*new;
	int		i;

	i = 0;
	if ((new = (char *)malloc(data->size * data->size + 1)))
	{
		while (i < (data->size * data->size))
			new[i++] = '.';
		new[i] = 0;
		data->board = new;
	}
}

int		change_board(char *board, int *change, int c)
{
	int	j;

	j = 0;
	if (!change)
		return (0);
	while (j < 4)
		board[change[j++]] = 'A' + c;
	return (1);
}


void	erase_from_board(t_list *data, t_stack *elem)
{
	int	i;

	i = 0;
//	printf("...erasing %c from board\n\n", elem->name + 'A');
//	printf("%s\n", *(data->input + x));
//	calc_shift(*(data->input + x), elem);
//	i = 0;
	while (i < 4)
		(data->board)[(elem->change)[i++]] = '.';
//	print_board(data->board, data->size);
//	printf("\n");
//	usleep(50);
}

int		push_to_board(t_list *data, t_stack *elem, int x, int shift)
{
	int		j;
	int		line;

	j = 0;
	line = 0;
//	printf("...pushing %c to board: ", x + 'A');
	calc_shift(*(data->input + x), elem);
	while (j < 4)
	{
		if (j != 0 && (elem->coor)[j] / 5 > (elem->coor)[j - 1] / 5)
			line = line + data->size;
		if (shift + line + (elem->shift)[j] >= data->size * data->size)
			break ;
		if ((shift + line) % data->size + (elem->shift)[j] >= data->size)
			break ;
		if ((data->board)[shift + line + (elem->shift)[j]] != '.')
			break ;
		(elem->change)[j] = shift + line + (elem->shift)[j];
		if (j++ == 3 && change_board(data->board, elem->change, x))
		{
//			printf("pushed\n\n");
//			print_board(data->board, data->size);
//			printf("\n");
//			usleep(500000);
			return (1);
		}
	}
//	printf("FAIL\n");
	return (0);
}

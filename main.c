/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsharipo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/14 20:25:14 by rsharipo          #+#    #+#             */
/*   Updated: 2018/07/20 10:29:39 by rsharipo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <fcntl.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <stdlib.h>
#define BUF_SIZE	21

void	print_board(char *board, int size)
{
	int	i;

	i = 0;
	while (board[i] != 0)
	{
		if (i != 0 && i % size == 0)
			write(1, "\n", 1);
		write(1, (board + i), 1);
		i++;
	}
	write(1, "\n", 1);
}

char	**get_input(char *file, int fd, char *buf, int num)
{
	int		i;
	int		j;
	char	**input;

	i = 0;
	j = 0;
	fd = open(file, O_RDONLY);
	if (!(input = (char **)malloc(21 * num + 1)))
		return (0);
	while (i < num)
	{
		buf[read(fd, buf, 21) - 1] = 0;
		input[i] = (char *)malloc(21);
		while (buf[j] != 0)
		{
			input[i][j] = buf[j];
			j++;
		}
		input[i][j] = 0;
		j = 0;
		i++;
	}
	close(fd);
	return (input);
}

int		main(int ac, char **av)
{
	int		fd;
	int		num;
	t_list	*data;
	char	**input;
	char	buf[BUF_SIZE + 1];

	num = 0;
	data = NULL;
	if (ac != 2)
	{
		ft_putendl("usage: fillit input_file");
		return (0);
	}
	else if ((fd = open(av[1], O_RDONLY)) == -1)
		ft_putendl("error");
	else if (!(num = ft_isvalid(fd, buf)))
		ft_putendl("error");
	else if (!(data = (t_list *)malloc(sizeof(*data))))
		ft_putendl("error");
	else
	{
		input = get_input(av[1], fd, buf, num);
		print_board(ft_filler(data, input, num), data->size);
	}
	return (0);
}

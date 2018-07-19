/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsharipo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/14 20:25:14 by rsharipo          #+#    #+#             */
/*   Updated: 2018/07/18 16:57:36 by rsharipo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <fcntl.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <stdlib.h>
#define BUF_SIZE	21

void	print_board(char *board)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (board[i * 51] != '*')
	{
		while (board[i * 51 + j] != '*')
			write(1, (board + i * 51 + j++), 1);
		write(1, "\n", 1);
		j = 0;
		i++;
	}
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
	char	**input;
	char	buf[BUF_SIZE + 1];

	num = 0;
	if (ac != 2)
	{
		ft_putendl("Usage");
		return (0);
	}
	else if ((fd = open(av[1], O_RDONLY)) == -1)
		ft_putendl("File open error");
	else if (!(num = ft_isvalid(fd, buf)))
		ft_putendl("Invalid input");
	else
	{
		input = get_input(av[1], fd, buf, num);
		print_board(ft_filler(input, num));
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isvalid.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsharipo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/14 20:59:42 by rsharipo          #+#    #+#             */
/*   Updated: 2018/07/18 16:48:49 by rsharipo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <unistd.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <fcntl.h>
#include <stdio.h>

int	check_tet(char *buf, int i)
{
	if (!(i % 5 == 0) && buf[i - 1] == '#')
		return (1);
	else if (!((i + 3) % 5 == 0) && buf[i + 1] == '#')
		return (1);
	else if (!(i < 5) && buf[i - 5] == '#')
		return (1);
	else if (!(i >= 15 && i <= 19) && buf[i + 5] == '#')
		return (1);
	else
		return (0);
}

int	check_block(char *buf)
{
	int	i;
	int tet_blocks;

	i = 0;
	tet_blocks = 0;
	while (buf[i] != 0)
	{
		if (buf[i] == '#')
			tet_blocks++;
		if (!(buf[i] == '.' || buf[i] == '#'
					|| buf[i] == '\n' || tet_blocks > 4))
			return (0);
		if (i != 0 && ((i + 1) % 5 == 0 || i == 20) && buf[i] != '\n')
			return (0);
		if (buf[i] == '#' && !(check_tet(buf, i)))
			return (0);
		i++;
	}
	return (1);
}

int	ft_isvalid(int fd, char *buf)
{
	int	ret;
	int i;

	i = 0;
	ret = -1;
	buf[i] = 0;
	while (i + 1)
	{
		if ((ret = read(fd, buf, 21)) != -1)
		{
			if (ret == 0 && ft_strlen(buf) != 20)
				return (0);
			buf[ret] = 0;
		}
		else
			return (0);
		if (i > 25 || (ret > 0 && ret < 20)
					|| (ret == 21 && buf[ret - 1] != '\n')
					|| !(check_block(buf)))
			return (0);
		if (ret == 0)
			break ;
		i++;
	}
	return (i);
}

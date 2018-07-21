/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsharipo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/18 15:51:47 by rsharipo          #+#    #+#             */
/*   Updated: 2018/07/21 13:42:59 by rsharipo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdlib.h>
#include <stdio.h>

int		stack_len(t_stack *elem)
{
	int		len;

	len = 0;
	while (elem)
	{
		len++;
		elem = elem->next;
	}
	return (len);
}

t_stack	*add_elem(t_stack *elem, int name)
{
	t_stack	*new;

	if (!(new = (t_stack *)malloc(sizeof(t_stack))))
		return (NULL);
	new->name = name;
	if (elem)
		new->next = elem;
	else
		new->next = NULL;
	return (new);
}

void	pop_elem(t_stack **elem)
{
	t_stack	*temp;

	if (*elem != NULL)
	{
		temp = *elem;
		*elem = (*elem)->next;
		temp->next = NULL;
		free(temp);
	}
}

int		check_elem(t_list *data, t_stack *elem, int name)
{
	if (name >= data->num)
		return (0);
	if (!elem)
		return (1);
	while (elem)
	{
		if (elem->name == name)
			return (0);
		elem = elem->next;
	}
	return (1);
}

int		get_elem(t_list *data, t_stack *elem)
{
	int		i;

	i = 0;
	while (i < data->num)
	{
		if (check_elem(data, elem, i))
			return (i);
		i++;
	}
	return (-1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsharipo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/15 09:19:36 by rsharipo          #+#    #+#             */
/*   Updated: 2018/07/18 17:00:55 by rsharipo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <string.h>

typedef struct		s_stack
{
	int				name;
	int				coor[4];
	int				shift[4];
	int				change[4];
	struct s_stack	*next;
}					t_stack;

typedef struct		s_list
{
	int				size;
	int				num;
	char			*board;
	char			**input;
}					t_list;

void				*ft_memset(char *b, int c, size_t len);
int					ft_isalpha(int c);
size_t				ft_strlen(void const *s);
void				ft_putstr(void const *s);
void				ft_putendl(void const *s);
int					ft_isvalid(int fd, char *buf);
char				*ft_filler(char **input, int num);
int					sq_rt(int nb);
void				fill_board(t_list *data);
void				calc_shift(char *tet, t_stack *elem);
int					change_board(char *board, int *change, char c);
int					push_to_board(t_list *data, t_stack *elem, char x);
t_stack				*add_elem(t_stack *elem, int name);
void				pop_elem(t_stack **elem);
int					check_elem(t_stack *elem, int name);
void				erase_from_board(char *board, int *change);
int					stack_len(t_stack *elem);
int					ft_solver(t_list *data, t_stack *elem);
char				*ft_filler(char **input, int num);

#endif

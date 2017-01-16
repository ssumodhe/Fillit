/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssumodhe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 15:35:19 by ssumodhe          #+#    #+#             */
/*   Updated: 2017/01/16 14:44:46 by ssumodhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>
# include "libft.h"

typedef	struct		s_fillit
{
	char			*str;
	char			alpha;
	int				use;
	struct s_fillit	*next;
}					t_fillit;

/*
** main.c
*/

void				ft_print_tab(char **tab);
void				ft_fillit_tetri(t_fillit *alst);
void				ft_start(char *buff, int size);
char				*ft_read(char *argv);

/*
** algo 1
*/

void				ft_del_letter(char **map, t_fillit *alst);
int					*ft_locate_piece(t_fillit *alst);
void				ft_check_coord(char **map, int *a, int *b, int coord);
int					ft_check_if_place(t_fillit *alst, char **map, int a, int b);

/*
** algo 2
*/

char				**ft_create_map(int sqr);
void				ft_increase(char **map, int *a, int *b);
int					ft_fillit(char **map, t_fillit *alst, int a, int b);

/*
** listes
*/

t_fillit			*ft_create_lst(char *str, int stock_i);
void				ft_lstalpha(t_fillit *alst);
size_t				ft_lstcount(t_fillit *alst);
void				ft_lstadd_tab(t_fillit **alst, t_fillit *new);
t_fillit			*ft_lstnew_tab(char *cpy);

/*
** check
*/

void				ft_puterror(void);
t_fillit			*ft_check_link(char *str, int stock_i, int block, int i);
t_fillit			*ft_check_file_tetri(char *str, int size);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssumodhe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 15:35:19 by ssumodhe          #+#    #+#             */
/*   Updated: 2017/01/13 17:13:25 by ssumodhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <ctype.h>
# include <fcntl.h>
# include <string.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <unistd.h>
# include "libft.h"

# define DEFAULT   "\033[0m"
# define HIGHLIGHT "\033[1m"
# define UNDERLINE "\033[4m"
# define BLINK     "\033[5m"
# define BLACK     "\033[30m"
# define RED       "\033[31m"
# define GREEN     "\033[32m"
# define YELLOW    "\033[33m"
# define BLUE      "\033[34m"
# define PURPLE    "\033[35m"
# define CYAN      "\033[36m"
# define WHITE     "\033[37m"

typedef	struct		s_fillit
{
	char			*str;
	char			alpha;
	int				use;
	struct s_fillit	*next;
}					t_fillit;

/*t_fillit				*ft_lstnew_tab(char *cpy);
size_t				ft_lstcount(t_fillit *alst);
void				ft_lstalpha(t_fillit *alst);
void				ft_lstadd_tab(t_fillit **alst, t_fillit *new);
void				ft_fillit_tetri(t_fillit *alst);
t_fillit			*ft_check_link(char *str, int stock_i, int block, int i);

size_t				ft_lstcount(t_fillit *alst); // ATTENTION PAS DANS LIBFT*/

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

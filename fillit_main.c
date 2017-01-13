/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_fillit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssumodhe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 12:21:23 by ssumodhe          #+#    #+#             */
/*   Updated: 2017/01/13 17:18:52 by ssumodhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		ft_print_tab(char **tab)
{
	int		a;

	a = 0;
	while (tab[a] != NULL)
	{
		ft_putstr(tab[a]);
		ft_putchar('\n');
		a++;
	}
}

void		ft_fillit_tetri(t_fillit *alst)
{
	int		nb_tetri;
	int		sqr;
	char	**map;

	nb_tetri = ft_lstcount(alst);
	nb_tetri = nb_tetri * 4;
	sqr = 0;
	while (sqr * sqr < nb_tetri)
		sqr++;
	map = ft_create_map(sqr);
	while (ft_fillit(map, alst, 0, 0) == 0)
		map = ft_create_map(++sqr);
	ft_print_tab(map);
}

void		ft_start(char *buff, int size)
{
	int			i;
	t_fillit	*alst;

	i = 0;
	while (buff[i] != '\0')
	{
		if (buff[i] != '.' && buff[i] != '#' && buff[i] != '\n')
			ft_puterror();
		i++;
	}
	alst = ft_check_file_tetri(buff, size);
	ft_lstalpha(alst);
	ft_fillit_tetri(alst);
}

char		*ft_read(char *argv)
{
	int		fd;
	char	buff[2];
	char	*buff_stock;

	if ((fd = open(argv, O_RDWR)) < 0)
	{
		ft_putstr("error\n");
		return (NULL);
	}
	buff[1] = '\0';
	if ((buff_stock = (char *)malloc(sizeof(char) * 1)) == NULL)
		return (NULL);
	while (read(fd, buff, 1) != 0)
		buff_stock = ft_strjoin(buff_stock, buff);
	if (close(fd) < 0)
	{
		ft_putstr("error\n");
		return (NULL);
	}
	return (buff_stock);
}

int			main(int argc, char **argv)
{
	char	*buff_stock;

	if (argc != 2)
	{
		ft_putstr("usage: ./fillit file\n");
		return (1);
	}
	if ((buff_stock = ft_read(argv[1])) == NULL)
		return (1);
	ft_start(buff_stock, ft_strlen(buff_stock));
	return (0);
}

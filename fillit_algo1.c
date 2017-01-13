/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit_algo1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssumodhe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/13 16:49:08 by ssumodhe          #+#    #+#             */
/*   Updated: 2017/01/13 17:14:34 by ssumodhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_del_letter(char **map, t_fillit *alst)
{
	int		a;
	int		b;

	a = 0;
	while (map[a] != NULL)
	{
		b = 0;
		while (map[a][b] != '\0')
		{
			if (map[a][b] == alst->alpha)
				map[a][b] = '.';
			b++;
		}
		a++;
	}
}

int		*ft_locate_piece(t_fillit *alst)
{
	int		i;
	int		a;
	int		*stock_coord;

	if ((stock_coord = (int *)malloc(sizeof(int) * 4)) == NULL)
		return (NULL);
	i = 0;
	a = 0;
	while (alst->str[a] != '\0')
	{
		while (alst->str[a] && (alst->str[a] == '.' || alst->str[a] == '\n'))
			a++;
		if (alst->str[a] == '#')
		{
			stock_coord[i] = a;
			i++;
		}
		a++;
	}
	return (stock_coord);
}

void	ft_check_coord(char **map, int *a, int *b, int coord)
{
	if (coord > 1 && map[*a + 1])
	{
		(*a)++;
		coord == 3 ? (*b = *b - 2) : 0;
		coord == 4 ? (*b = *b - 1) : 0;
	}
	if (coord == 1 && map[*a][*b + 1])
		(*b)++;
}

int		ft_check_if_place(t_fillit *alst, char **map, int a, int b)
{
	int		*stock_coord;
	int		coord;
	int		ok;
	int		i;

	i = 1;
	ok = 1;
	if (map[a][b] != '.')
		return (0);
	map[a][b] = alst->alpha;
	stock_coord = ft_locate_piece(alst);
	while (i < 4 && map[a] && map[a][b])
	{
		coord = stock_coord[i] - stock_coord[i - 1];
		ft_check_coord(map, &a, &b, coord);
		if (map[a][b] == '.')
		{
			map[a][b] = alst->alpha;
			ok++;
		}
		i++;
	}
	return ((ok == 4) ? 1 : 0);
}

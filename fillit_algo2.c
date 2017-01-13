/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit_5.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssumodhe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 10:24:41 by ssumodhe          #+#    #+#             */
/*   Updated: 2017/01/13 17:15:26 by ssumodhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**ft_create_map(int sqr)
{
	char	**tab;
	int		a;
	int		b;

	if ((tab = (char **)malloc(sizeof(char *) * (sqr + 1))) == NULL)
		exit(EXIT_FAILURE);
	a = 0;
	while (a < sqr)
	{
		if ((tab[a] = (char *)malloc(sizeof(char) * (sqr + 1))) == NULL)
			exit(EXIT_FAILURE);
		a++;
	}
	a = 0;
	while (a < sqr)
	{
		b = -1;
		while (++b < sqr)
			tab[a][b] = '.';
		tab[a][b] = '\0';
		a++;
	}
	tab[a] = NULL;
	return (tab);
}

void	ft_increase(char **map, int *a, int *b)
{
	(*b)++;
	if (map[*a][*b] == '\0')
	{
		(*a)++;
		*b = 0;
	}
}

int		ft_fillit(char **map, t_fillit *alst, int a, int b)
{
	t_fillit	*tmp;

	tmp = alst;
	while (tmp != NULL && tmp->use == 1)
		tmp = tmp->next;
	if (tmp == NULL)
		return (1);
	while (tmp != NULL)
	{
		while (tmp && tmp->use == 0 && map[a] && map[a][b])
		{
			if (ft_check_if_place(tmp, map, a, b) == 1)
			{
				tmp->use = 1;
				if (ft_fillit(map, alst, 0, 0) == 1)
					return (1);
			}
			ft_increase(map, &a, &b);
			tmp->use = 0;
			ft_del_letter(map, tmp);
		}
		tmp = tmp->next;
	}
	return (0);
}

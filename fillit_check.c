/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssumodhe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/13 16:44:09 by ssumodhe          #+#    #+#             */
/*   Updated: 2017/01/13 16:45:28 by ssumodhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		ft_puterror(void)
{
	ft_putstr("error\n");
	exit(EXIT_FAILURE);
}

t_fillit	*ft_check_link(char *str, int stock_i, int block, int i)
{
	int				link;
	int				count_hash;
	t_fillit		*list;

	count_hash = 0;
	link = 0;
	list = NULL;
	while (i < block && str[i] != '\0')
	{
		if (str[i] == '#')
		{
			count_hash++;
			(str[i - 1] == '#' && i >= 1) ? link++ : 0;
			str[i + 1] == '#' ? link++ : 0;
			(str[i - 5] == '#' && (i - 5) >= stock_i) ? link++ : 0;
			(str[i + 5] == '#' && (i + 5) < block) ? link++ : 0;
		}
		i++;
	}
	if ((link == 6 || link == 8) && count_hash == 4)
		list = ft_create_lst(str, stock_i);
	if ((link != 6 && link != 8) || count_hash != 4)
		ft_puterror();
	return (list);
}

t_fillit	*ft_check_file_tetri(char *str, int size)
{
	int			i;
	int			block;
	int			stock_i;
	int			count_block;
	t_fillit	*alst;

	alst = NULL;
	i = size - 20;
	block = size;
	count_block = 1;
	while (str[i] != '\0' && i > -1)
	{
		stock_i = i;
		if (str[stock_i] == '\n' || (str[block] != '\n' && str[block] != '\0'))
			ft_puterror();
		ft_lstadd_tab(&alst, ft_check_link(str, stock_i, block, i));
		block = block - 21;
		i = block - 20;
		count_block++;
	}
	if (stock_i != 0)
		ft_puterror();
	if (count_block > 26)
		ft_puterror();
	return (alst);
}

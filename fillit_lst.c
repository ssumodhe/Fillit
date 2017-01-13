/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit_lst.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssumodhe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 15:16:07 by ssumodhe          #+#    #+#             */
/*   Updated: 2017/01/13 17:11:13 by ssumodhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_fillit	*ft_create_lst(char *str, int stock_i)
{
	char		*cpy;
	t_fillit	*list;

	if ((cpy = (char *)malloc(sizeof(char) * 20)) == NULL)
		ft_puterror();
	cpy = ft_strncpy(cpy, (str + stock_i), 20);
	cpy[20] = '\0';
	list = ft_lstnew_tab(cpy);
	return (list);
}

void		ft_lstalpha(t_fillit *alst)
{
	char	alpha;

	alpha = 65;
	if (alst != NULL)
	{
		while (alst != NULL)
		{
			alst->alpha = alpha++;
			alst = alst->next;
		}
	}
}

size_t		ft_lstcount(t_fillit *alst)
{
	size_t	count;

	count = 0;
	if (alst == NULL)
		return (0);
	while (alst != NULL)
	{
		count++;
		alst = alst->next;
	}
	return (count);
}

void		ft_lstadd_tab(t_fillit **alst, t_fillit *new)
{
	if (new != NULL && alst)
	{
		new->next = *alst;
		*alst = new;
	}
}

t_fillit	*ft_lstnew_tab(char *cpy)
{
	t_fillit	*list;

	if ((list = (t_fillit *)malloc(sizeof(*list))) == NULL)
		return (NULL);
	list->use = 0;
	list->alpha = 0;
	list->str = ft_strdup(cpy);
	return (list);
}

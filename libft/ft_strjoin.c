/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssumodhe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 12:18:04 by ssumodhe          #+#    #+#             */
/*   Updated: 2016/11/26 16:16:00 by ssumodhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		n;
	int		m;
	char	*join;

	if ((s1 == 0) || (s2 == 0))
		return (NULL);
	n = ft_strlen(s1);
	m = ft_strlen(s2);
	if ((join = (char *)malloc(sizeof(char) * (n + m + 1))) == NULL)
		return (NULL);
	n = 0;
	while (s1[n] != '\0')
	{
		join[n] = s1[n];
		n++;
	}
	m = 0;
	while (s2[m] != '\0')
	{
		join[n] = s2[m];
		n++;
		m++;
	}
	join[n] = '\0';
	return (join);
}

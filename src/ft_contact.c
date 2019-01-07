/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_contact.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblaudez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 17:37:00 by tblaudez          #+#    #+#             */
/*   Updated: 2018/04/19 23:06:06 by sgalasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	ft_links(char *file, int i, int j, int c)
{
	while (file[++i])
	{
		if (file[i] == '#')
		{
			if (file[i + 1] == '#')
				c++;
			if (file[i - 1] == '#')
				c++;
			if (file[i + 5] == '#')
				c++;
			if (file[i - 5] == '#')
				c++;
			j++;
		}
		if (j == 4)
		{
			if (c < 6)
				return (0);
			j = 0;
			c = 0;
		}
	}
	return (1);
}

int			ft_contact(char *file)
{
	int i;
	int j;
	int c;

	i = -1;
	j = 0;
	c = 0;
	if (!(ft_links(file, i, j, c)))
		return (0);
	return (1);
}

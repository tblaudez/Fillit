/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_trimhori.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblaudez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/12 17:48:25 by tblaudez          #+#    #+#             */
/*   Updated: 2018/04/19 23:19:57 by sgalasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

char	*ft_trimhori(char *map)
{
	int i;
	int j;

	j = 0;
	while (j < 3)
	{
		i = -1;
		if (ft_charnsrc(map, '#', 4) < 0)
		{
			while (map[++i])
				if (map[i] == '#')
				{
					map[i - 4] = '#';
					map[i] = '.';
				}
		}
		j++;
	}
	return (map);
}

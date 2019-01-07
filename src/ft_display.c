/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgalasso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/15 23:13:01 by sgalasso          #+#    #+#             */
/*   Updated: 2018/04/20 00:41:50 by sgalasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_display(char *map)
{
	int	mapsize;
	int i;
	int j;

	mapsize = ft_sqrt(ft_strlen(map));
	i = 0;
	j = 1;
	while (map[i])
	{
		if (j == mapsize)
		{
			ft_putchar(map[i]);
			ft_putchar('\n');
			j = 1;
		}
		else
		{
			ft_putchar(map[i]);
			j++;
		}
		i++;
	}
}

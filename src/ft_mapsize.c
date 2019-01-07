/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mapsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgalasso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 17:23:56 by sgalasso          #+#    #+#             */
/*   Updated: 2018/04/19 21:31:22 by sgalasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_mapsize(char *map)
{
	int mapsize;

	mapsize = 0;
	while (map[mapsize])
		mapsize++;
	return (mapsize);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgalasso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 17:16:51 by sgalasso          #+#    #+#             */
/*   Updated: 2018/04/19 21:30:02 by sgalasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*ft_create_map(int mapsize)
{
	char	*map;

	if (!(map = (char *)(malloc(sizeof(char) * (mapsize + 1)))))
		exit(EXIT_FAILURE);
	ft_fill_dot(map, mapsize);
	return (map);
}

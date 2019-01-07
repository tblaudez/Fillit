/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resolve.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgalasso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 19:13:13 by sgalasso          #+#    #+#             */
/*   Updated: 2018/04/20 15:56:44 by sgalasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static char		*ft_add_bloc(t_struct *bloc, char *map, int x, int mapsize)
{
	int i;
	int j;

	j = 0;
	i = 0;
	while (bloc->content[i])
	{
		if (bloc->content[i] == '#' || (bloc->content[i] >= 'A' &&
		bloc->content[i] <= 'Z'))
			map[x] = bloc->alpha;
		if (j == 3)
		{
			x = x + (ft_sqrt(mapsize) - 4) + 1;
			j = 0;
			i++;
		}
		else
		{
			j++;
			x++;
			i++;
		}
	}
	return (map);
}

static char		*ft_try_bloc(t_struct *bloc, char *map, int x, int mapsize)
{
	int		i;
	int		j;

	j = 0;
	i = 0;
	while (bloc->content[i])
	{
		if ((bloc->content[i] == '#' || (bloc->content[i] >= 'A' &&
		bloc->content[i] <= 'Z')) && ((map[x] == '#') || (map[x] >= 'A' &&
		map[x] <= 'Z')))
			return (0);
		if (j == 3)
		{
			x = x + (ft_sqrt(mapsize) - 4) + 1;
			j = 0;
			i++;
		}
		else
		{
			j++;
			x++;
			i++;
		}
	}
	return (map);
}

static char		*ft_del_bloc(char *map, char a)
{
	int i;

	i = 0;
	while (map[i])
	{
		if (map[i] == a)
			map[i] = '.';
		i++;
	}
	return (map);
}

static char		*ft_res_rec(t_struct **blocs, char *map, int i, int x)
{
	int mapsize;

	mapsize = ft_mapsize(map);
	if (!blocs[i])
		return (map);
	while (x < mapsize - (ft_sqrt(mapsize) * (blocs[i]->h - 1) +
	(blocs[i]->w - 1)))
	{
		if ((x / ft_sqrt(mapsize)) == ((x + (blocs[i]->w - 1)) /
		ft_sqrt(mapsize)))
		{
			if (ft_try_bloc(blocs[i], map, x, mapsize))
			{
				map = ft_add_bloc(blocs[i], map, x, mapsize);
				if (!(ft_res_rec(blocs, map, ++i, 0)))
					ft_del_bloc(map, blocs[--i]->alpha);
				else
					return (map);
			}
		}
		x++;
	}
	return (0);
}

char			*ft_resolve(t_struct **blocs)
{
	char	*map;
	int		mapsize;

	mapsize = 4;
	if (!(map = ft_create_map(mapsize)))
		exit(EXIT_FAILURE);
	while (!(map = ft_res_rec(blocs, map, 0, 0)))
	{
		mapsize = mapsize + (ft_sqrt(mapsize) * 2 + 1);
		free(map);
		if (!(map = (char *)(malloc(sizeof(char) * (mapsize)))))
			exit(EXIT_FAILURE);
		ft_fill_dot(map, mapsize);
	}
	return (map);
}

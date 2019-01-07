/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_s_blocs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgalasso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/20 01:48:28 by sgalasso          #+#    #+#             */
/*   Updated: 2018/04/20 15:55:48 by sgalasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			ft_get_height(char *bloc)
{
	int i;
	int start;
	int	end;
	int c;

	i = 0;
	c = 0;
	start = -1;
	end = -1;
	while (bloc[i])
	{
		if (bloc[i] == '#' && start == -1)
			start = i;
		if (bloc[i] == '#' && bloc[i + 1] != '#')
			end = i;
		i++;
	}
	return (end / 4 - start / 4 + 1);
}

int			ft_get_width(char *bloc)
{
	int i;
	int j;
	int temp;

	i = 0;
	j = 1;
	temp = 0;
	while (bloc[i])
	{
		if (bloc[i] == '#' && j > temp)
			temp = j;
		if (j % 4 == 0)
			j = 0;
		j++;
		i++;
	}
	return (temp);
}

t_struct	**ft_s_blocs(char **blocs, char *file)
{
	t_struct	**s_blocs;
	char		alpha;
	int			i;
	int			j;

	alpha = 'A';
	i = -1;
	if (!(s_blocs = (t_struct **)(malloc(sizeof(t_struct *) *
	(ft_nb_bloc(file) + 1)))))
		return (0);
	while (blocs[++i])
	{
		if (alpha > 'Z')
			return (0);
		if (!(s_blocs[i] = (t_struct *)(malloc(sizeof(t_struct)))))
			return (0);
		j = 0;
		if (!(s_blocs[i]->content = ft_strdup(blocs[i])))
			return (0);
		s_blocs[i]->alpha = alpha++;
		s_blocs[i]->h = ft_get_height(blocs[i]);
		s_blocs[i]->w = ft_get_width(blocs[i]);
	}
	s_blocs[i] = 0;
	return (s_blocs);
}

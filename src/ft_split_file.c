/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgalasso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 00:46:52 by sgalasso          #+#    #+#             */
/*   Updated: 2018/04/19 23:15:09 by sgalasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

int		ft_create_bloc(char **blocs, int index)
{
	if (!(blocs[index] = (char *)(malloc(sizeof(char) * (17)))))
	{
		free(blocs);
		return (0);
	}
	return (1);
}

char	**ft_split_file(char *file)
{
	char	**blocs;
	int		index;
	int		i;
	int		j;

	i = 0;
	index = 0;
	if (!(blocs = (char **)(malloc(sizeof(char *) * (ft_nb_bloc(file) + 1)))))
		return (0);
	while (index < ft_nb_bloc(file))
	{
		if (!(ft_create_bloc(blocs, index)))
			return (0);
		j = 0;
		while (file[i] && !(file[i] == '\n' && file[i - 1] == '\n'))
		{
			if (file[i] != '\n')
				blocs[index][j++] = file[i];
			i++;
		}
		blocs[index++][j] = '\0';
		i++;
	}
	blocs[index] = 0;
	return (blocs);
}

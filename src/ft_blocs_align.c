/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_blocs_align.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgalasso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 16:30:55 by sgalasso          #+#    #+#             */
/*   Updated: 2018/04/20 15:48:18 by sgalasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

t_struct	**ft_blocs_align(char **blocs, char *file)
{
	int			index;
	t_struct	**s_blocs;

	index = 0;
	while (blocs[index])
	{
		if (!(blocs[index] = ft_trimhori(blocs[index])))
			return (0);
		if (!(blocs[index] = ft_trimvert(blocs[index])))
			return (0);
		index++;
	}
	if (!(s_blocs = ft_s_blocs(blocs, file)))
		return (0);
	return (s_blocs);
}

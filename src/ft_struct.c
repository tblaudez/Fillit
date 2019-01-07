/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_struct.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgalasso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 15:53:51 by sgalasso          #+#    #+#             */
/*   Updated: 2018/04/20 16:06:11 by sgalasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_struct	**ft_struct(char *file)
{
	t_struct	**s_blocs;
	char		**blocs;

	if (!(blocs = ft_split_file(file)))
	{
		ft_putendl("error");
		exit(EXIT_FAILURE);
	}
	if (!(s_blocs = ft_blocs_align(blocs, file)))
	{
		ft_putendl("error");
		exit(EXIT_FAILURE);
	}
	free(file);
	return (s_blocs);
}

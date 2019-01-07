/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgalasso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/07 10:28:46 by sgalasso          #+#    #+#             */
/*   Updated: 2018/04/20 16:05:51 by sgalasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int argc, char **argv)
{
	int			i;
	char		*file;
	t_struct	**s_blocs;
	char		*map;

	if (argc == 2)
	{
		file = ft_import(argv);
		ft_checks(file);
		s_blocs = ft_struct(file);
		if (!(map = ft_resolve(s_blocs)))
		{
			write(1, "error\n", 6);
			exit(EXIT_FAILURE);
		}
		i = -1;
		while (s_blocs[++i])
			free(s_blocs[i]);
		free(s_blocs);
		ft_display(map);
		free(map);
	}
	else
		write(1, "usage : ./fillit [file]\n", 24);
	return (0);
}

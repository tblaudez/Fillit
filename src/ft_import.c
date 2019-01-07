/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_import.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgalasso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 15:44:18 by sgalasso          #+#    #+#             */
/*   Updated: 2018/04/19 23:03:33 by sgalasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*ft_import(char **argv)
{
	char	*file;
	int		fd;

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		ft_putendl("error");
		exit(EXIT_FAILURE);
	}
	if (!(file = ft_get_file(fd)))
	{
		ft_putendl("error");
		exit(EXIT_FAILURE);
	}
	if (close(fd) == -1)
	{
		ft_putendl("error");
		exit(EXIT_FAILURE);
	}
	return (file);
}

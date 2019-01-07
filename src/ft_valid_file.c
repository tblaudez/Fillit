/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_valid_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgalasso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 17:54:16 by sgalasso          #+#    #+#             */
/*   Updated: 2018/04/19 23:05:42 by sgalasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	ft_ischar(char c)
{
	return (c == '.' || c == '#' || c == '\n');
}

static int	ft_nb_char(char *file)
{
	int i;
	int c;

	i = 0;
	c = 0;
	while (file[i])
	{
		if (file[i] == '\n' && c != 4 && file[i - 1] != '\n')
			return (0);
		if (file[i] == '\n')
			c = -1;
		i++;
		c++;
	}
	return (1);
}

static int	ft_nb_line(char *file)
{
	int i;
	int c;

	i = 0;
	c = 0;
	while (file[i])
	{
		if (file[i] == '\n' && file[i - 1] != '\n')
			c++;
		if ((file[i] == '\n' && file[i - 1] == '\n') || file[i + 1] == 0)
		{
			if (c != 4)
				return (0);
			else
				c = 0;
		}
		i++;
	}
	return (1);
}

int			ft_valid_file(char *file)
{
	int		i;

	i = 0;
	while (file[i])
	{
		if (!(ft_ischar(file[i])))
			return (0);
		i++;
	}
	if (!(ft_nb_char(file)))
		return (0);
	if (!(ft_nb_line(file)))
		return (0);
	return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_file.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgalasso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/16 12:00:42 by sgalasso          #+#    #+#             */
/*   Updated: 2018/04/19 23:03:24 by sgalasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char			*ft_get_file(int fd)
{
	char	*file;
	char	*buff;
	int		i;

	i = 0;
	if (!(buff = ft_strnew(700)))
		return (0);
	read(fd, buff, 700);
	if (!(file = ft_strnew(ft_strlen(buff) + 1)))
		return (0);
	while (buff[i])
	{
		file[i] = buff[i];
		i++;
	}
	file[i] = '\0';
	ft_strdel(&buff);
	return (file);
}

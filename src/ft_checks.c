/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgalasso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 15:31:05 by sgalasso          #+#    #+#             */
/*   Updated: 2018/04/19 23:06:11 by sgalasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_checks(char *file)
{
	if (*file == 0)
	{
		ft_putendl("error");
		exit(EXIT_FAILURE);
	}
	if (!(ft_valid_file(file)))
	{
		ft_putendl("error");
		exit(EXIT_FAILURE);
	}
	if (!(ft_isfour(file)))
	{
		ft_putendl("error");
		exit(EXIT_FAILURE);
	}
	if (!(ft_contact(file)))
	{
		ft_putendl("error");
		exit(EXIT_FAILURE);
	}
	return (1);
}

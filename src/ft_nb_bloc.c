/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nb_bloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgalasso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 19:17:15 by sgalasso          #+#    #+#             */
/*   Updated: 2018/04/19 21:02:31 by sgalasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_nb_bloc(char *file)
{
	int i;
	int c;

	i = 0;
	c = 0;
	while (file[i])
	{
		if (file[i] == '\n' && (file[i + 1] == '\n' || file[i + 1] == '\0'))
			c++;
		i++;
	}
	return (c);
}

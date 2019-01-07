/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgalasso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 17:37:48 by sgalasso          #+#    #+#             */
/*   Updated: 2018/08/09 20:27:42 by tblaudez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdio.h>
# include "libft.h"

typedef struct	s_struct
{
	char	*content;
	char	alpha;
	int		h;
	int		w;
}				t_struct;

int				ft_sqrt(int nb);
int				ft_contact(char *file);
int				ft_isfour(char *file);
char			*ft_get_file(int fd);
char			*ft_import(char **argv);
int				ft_valid_file(char *file);
int				ft_checks(char *file);
int				ft_nb_bloc(char *file);
char			**ft_split_file(char *file);
char			*ft_trimhori(char *bloc);
char			*ft_trimvert(char *bloc);
t_struct		**ft_s_blocs(char **blocs, char *file);
t_struct		**ft_blocs_align(char **blocs, char *file);
t_struct		**ft_struct(char *file);
int				ft_mapsize(char *map);
void			ft_fill_dot(char *map, int mapsize);
char			*ft_create_map(int mapsize);
char			*ft_resolve(t_struct **s_blocs);
void			ft_display(char *map);

#endif

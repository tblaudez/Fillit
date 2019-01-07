# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tblaudez <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/04/05 15:48:20 by tblaudez          #+#    #+#              #
#    Updated: 2018/08/09 18:58:17 by tblaudez         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := fillit
SRC := src/ft_blocs_align.c src/ft_display.c src/ft_isfour.c src/ft_s_blocs.c src/ft_trimhori.c src/ft_checks.c \
src/ft_fill_dot.c src/ft_mapsize.c src/ft_split_file.c src/ft_trimvert.c src/ft_contact.c src/ft_get_file.c src/ft_nb_bloc.c \
src/ft_sqrt.c src/ft_valid_file.c src/ft_create_map.c src/ft_import.c src/ft_resolve.c src/ft_struct.c src/main.c
OBJ := $(SRC:.c=.o)
INCLUDES := includes/
FLAGS := -Wall -Wextra -Werror

all : $(NAME)

$(NAME) : lib $(OBJ) $(INCLUDES)
	@printf "\e[1;34mCréation du binaire \e[0m- %s\n" $(NAME)
	@gcc $(FLAGS) -I $(INCLUDES) $(OBJ) libft/libft.a -o $(NAME)

%.o : %.c
	@gcc $(FLAGS) -I $(INCLUDES) -o $@ -c $<

lib:
	@make -C libft/

clean :
	@rm -f $(OBJ) && \
	make -C libft/ clean

fclean : clean
	@rm -f $(NAME) && \
	make -C libft/ fclean

re : fclean all

.PHONY : all lib clean fclean re

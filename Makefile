# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wwallas- <wwallas-@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/29 16:09:22 by wwallas-          #+#    #+#              #
#    Updated: 2022/11/29 16:56:48 by wwallas-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	cub3D

LIBFT		=	./libft/libft.a
MLX			=	mlx/libmlx.a

LIBS		=	$(LIBFT) $(MLX)

INCLUDES	=	./includes

SOURCES		=

OBJS_DIR	=	objects
OBJECTS		=	$(patsubst %.c, $(OBJS_DIR)%.o, $(SOURCES))

CC			=	gcc
CFLAGS		=	-g3 -Wall -Wextra -Werror
RM			=	rm -rf

$(OBJS_DIR)%.o:	%.c

all:		$(NAME)

$(NAME):	$(LIBFT) $(MLX) $(OBJS_DIR) $(OBJECTS)
				gcc main.c $(LIBS) -o $@
$(OBJS_DIR):
			mkdir -p objects

$(LIBFT):
			$(MAKE) -C libft

$(MLX):
			$(MAKE) -C mlx

clean:
			$(MAKE) -C libft clean
			$(MAKE) -C mlx clean

fclean:		clean
			$(MAKE) -C libft fclean
			$(RM) $(NAME)

re:			fclean all

.PHONY:	fclean clean re

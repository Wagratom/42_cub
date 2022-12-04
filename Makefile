# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wwallas- <wwallas-@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/29 16:09:22 by wwallas-          #+#    #+#              #
#    Updated: 2022/12/03 22:34:01 by wwallas-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	cub3D

LIBFT		=	./libft/libft.a
MLX			=	mlx/libmlx.a
LIBS		=	$(LIBFT) $(MLX)

INCLUDE		=	-I./libft	\
				-I./mlx		\
				-I./include

SOURCES		=	verify_extension.c open_file.c valid_map.c valid_chars.c valid_chars_ults.c verify_exit.c \
				alloc_map.c draw_map.c\


OBJS_DIR	=	object
OBJECTS		=	$(patsubst %.c, $(OBJS_DIR)/%.o, $(SOURCES))

CC			=	gcc -g3
CFLAGS		=	-Wall -Wextra -Werror
RM			=	rm -rf

VPATH		=	. ./sources

$(OBJS_DIR)/%.o:	%.c
			$(CC) -c $< -o $@ $(INCLUDE)

all:		$(NAME)

$(NAME):	$(LIBFT) $(MLX) $(OBJS_DIR) $(OBJECTS)
				$(CC) main.c $(OBJECTS) $(LIBS) -o $@ $(INCLUDE)

$(OBJS_DIR):
			mkdir -p $@

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

norm:
	@echo "\n			INCLUDES\n" && norminette include
	@echo "\n			SOURCES\n" && norminette sources

re_mandatory:
		$(RM) $(OBJS_DIR)
		make

################################################################################
#									TEST
################################################################################

TST_PATH		=	./test

FILE_TST		=	$(TST_PATH)/$(t).c
OJBS_TST		=	$(patsubst %.c, %.out, $(FILE_TST))

FILE_TSTS		=	$(wildcard $(TST_PATH)/**/*.c);
OJBS_TSTS		=	$(patsubst %.c, %.out, $(FILE_TSTS))

%.out:	%.c
		@$(CC) $< $(OBJECTS) $(LIBS) -o $@ $(INCLUDE)
		@./$@
		@$(RM) $@

test: re_mandatory $(OJBS_TST)

tests: re_mandatory $(OJBS_TSTS)

################################################################################
#									TESTVG
################################################################################

TST_PATH		=	./test

VG_FILE_TST		=	$(TST_PATH)/$(t).c
VG_OJBS_TST		=	$(patsubst %.c, %.vg.out, $(VG_FILE_TST))

VG_FILE_TSTS		=	$(wildcard $(TST_PATH)/**/*.c)
VG_OJBS_TSTS		=	$(patsubst %.c, %.vg.out, $(VG_FILE_TSTS))

%.vg.out:	%.c
		@$(CC) $< $(OBJECTS) $(LIBS) -o $@ $(INCLUDE)
		@valgrind --leak-check=full ./$@
		@$(RM) $@

vgtest: re_mandatory $(VG_OJBS_TST)

vgtests: re_mandatory $(VG_OJBS_TSTS)

.PHONY:	fclean clean re

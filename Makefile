# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wwalas- <wwallas-@student.42sp.org.br>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/29 16:09:22 by wwallas-          #+#    #+#              #
#    Updated: 2023/02/01 23:03:37 by wwalas-          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	cub3D

LIBFT		=	./libft/libft.a
MLX			=	mlx/libmlx.a
LIBS		=	$(LIBFT) $(MLX)

INCLUDE		=	-I./libft	\
				-I./mlx		\
				-I./include

SOURCES		=	verify_extension.c open_file.c valid_map.c valid_chars.c valid_chars_ults.c verify_exit.c	\
				alloc_map.c draw_map.c init_data.c init_img.c init_windows.c draw_map_debug.c	\
				print_larger_pixel.c save_x.c filter_keyboard.c updates.c  control.c \
				start_program.c raycast.c calculetePixel.c positionMap.c radiusCalculation.c screen.c		\
				is_valid_position.c move_up.c move_down.c move_right.c move_left.c cleanup_program.c \
				jump_next_square.c look_left.c look_right.c debug.c debug_ready_msgs.c set_direction.c \
				get_first_word.c compare_strings.c extract_colors.c extract_data.c texture.c \
				fill_collor.c

OBJS_DIR	=	object
OBJECTS		=	$(patsubst %.c, $(OBJS_DIR)/%.o, $(SOURCES))

CC			=	cc -g3
CFLAGS		=	-Wall -Wextra -Werror  -fsanitize=leak
FLAGS_MLX	=	-fPIE -Imlx_linux -lXext -lX11 -lm -lz -o

RM			=	rm -rf

VPATH		=	.						\
				./sources				\
				./sources/control		\
				./sources/parser		\
				./sources/map 			\
				./sources/initialize	\
				./sources/draw_map		\
				./sources/program		\
				./sources/raycast

$(OBJS_DIR)/%.o:	%.c
			$(CC) -c $< -o $@ $(INCLUDE)

all:		$(NAME)

$(NAME):	$(LIBFT) $(MLX) $(OBJS_DIR) $(OBJECTS)
				$(CC) ./sources/main.c $(OBJECTS) $(LIBS) $(FLAGS_MLX) $@ $(INCLUDE)

$(OBJS_DIR):
			mkdir -p $@

$(LIBFT):
			$(MAKE) -C libft

$(MLX):
			$(MAKE) -C mlx

clean:
			$(MAKE) -C libft clean
			$(MAKE) -C mlx clean
			$(RM) $(OBJS_DIR)

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

textured:
	$(CC) 01_untextured_raycast.c $(LIBS) $(FLAGS_MLX) teste $(INCLUDE)

################################################################################
#									TEST
################################################################################

TST_PATH		=	./test

FILE_TST		=	$(TST_PATH)/$(t).c
OJBS_TST		=	$(patsubst %.c, %.out, $(FILE_TST))

FILE_TSTS		=	$(wildcard $(TST_PATH)/**/*.c);
OJBS_TSTS		=	$(patsubst %.c, %.out, $(FILE_TSTS))

%.out:	%.c
		@$(CC) $< $(OBJECTS) $(LIBS) $(FLAGS_MLX) $@ $(INCLUDE)
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
		@$(CC) $< $(OBJECTS) $(LIBS) $(FLAGS_MLX) $@ $(INCLUDE)
		@valgrind --leak-check=full --show-leak-kinds=all ./$@
		@$(RM) $@

vgtest: re_mandatory $(VG_OJBS_TST)

vgtests: re_mandatory $(VG_OJBS_TSTS)

.PHONY:	fclean clean re

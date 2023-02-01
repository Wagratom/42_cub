/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwalas- <wwallas-@student.42sp.org.br>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 13:32:06 by wwallas-          #+#    #+#             */
/*   Updated: 2023/02/01 10:31:56 by wwalas-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <libft.h>
# include <mlx.h>
# include <structs.h>
# include <math.h>


# include <stdio.h>

# define VALID_CHARS "01NSEW\n\t "
# define ESPECIAL_CHARS "NSEW"


# define RGB_RED 0x00FF0000
# define RGB_MAROON 0x00800000
# define RGB_WHITE 0x00FFFFFF

# define P_Y 0
# define P_X 1

# define PRESS_KEY 2
# define EXIT 17

#define WIDTH 640
#define HEIGHT 480

# define MOD_DEBUG "\tDEBUG MODE ON\n\n"
# define INVALID_ARGC "Invalid number of argument\n"
# define INVALID_ARGV "Invalid arguments passed\n"
# define NULL_ARGV "Invalid flag passed\n"

# define MLX_NULL "Error: Not init mlx\n"

/******************************************************************************/
/*								KEYBOARD									  */
/******************************************************************************/

# define KEY_ESQ 65307

# define KEY_W 119
# define KEY_D 100
# define KEY_S 115
# define KEY_A 97

# define ARROW_UP 65362
# define ARROW_RIGHT 65363
# define ARROW_DOWN 65364
# define ARROW_LEFT 65361

/******************************************************************************/
/*							VALIDACION MAP									  */
/******************************************************************************/

t_bool		verify_extension(char *file_name);

t_bool		open_file_status(t_map *data);

t_bool		valid_map(t_data *data);
t_bool		valid_chars_or_die(t_map *data);
t_bool		valid_chars_line(t_map *data, char *line);
t_bool		interactor_chars_or_die(t_map *data, char _char);
void		save_position_player(t_map *data, int position_x, char _char);
t_bool		verify_exit_status(t_map *data);

t_bool		alloc_map_status(t_map *data);
void		delete_map(char **map);

/*							ULTS											  */

char		*get_line(t_map *data, char **line);
t_bool		interactor_chars(t_map *data, char _char);
t_bool		is_special_char(char _char);
t_bool		valid_char_or_die(char _char);

/******************************************************************************/
/*							INITIALIZE										  */
/******************************************************************************/

void		init_data(t_data *data, char *file_name);
t_bool		init_windows_or_die(t_data *data);
t_bool		init_img(t_data *data);

/******************************************************************************/
/*							DRAW_MAP										  */
/******************************************************************************/

int			draw_map_or_die(t_data *data);
int			draw_map(t_data *data);

void		print_larger_pixel(t_data *data, int x, int y, int color);
void		my_mlx_pixel_put(t_img *img, int x, int y, int color);

void		save_value_x(int nbr);
int			get_save_x(void);

int			get_size_y(int nbr);

/******************************************************************************/
/*							PROGRAM											  */
/******************************************************************************/

void		start_game(t_data *data);

int			filter_keyboard(int key, t_data *data);
void		map_move_up(t_map *map);
void		map_move_right(t_map *map);
void		map_move_left(t_map *map);
void		map_move_down(t_map *map);
void		update_p_char(t_map *map, int x, int y);
void		update_p_player(t_map *map, double position_y, double position_x);

void		draw_mapingD(char **map);
// void		testes(t_data *data);

// void		creat_img(t_data *data);
double		player_p_x(t_data *data);
double		player_p_y(t_data *data);

int			is_direction(char c);
void		set_direction_player(t_map *data, char c);


/******************************************************************************/
/*								RAYCAST										  */
/******************************************************************************/

void		raycast(t_data *data);
void		calculate_ray_position_direction(t_raycast *itens, int x);
void		position_player_map(t_raycast *itens, t_data *data);
void		length_ray(t_raycast *itens);
void		length_ray_next_x_y(t_raycast *itens, t_data *data);
void		jump_next_square_and_verify_hit_wall(t_raycast *itens, t_data *data);
void		calculate_height_line(t_raycast *itens, t_data *data);
void		calculate_pixel(t_raycast *itens, t_data *data);

int			is_valid_position(t_map *map, double x, double y);
int			cleanup_program(t_data *data);


void		map_look_right(t_map *map);
void		map_look_left(t_map *map);

t_bool		*flag(void);
void		set_flag(t_bool _flag);
t_bool		has_flag(void);

void		debug_print(t_bool mod_debug, char *prefix, char *msg);

void		exit_msg(char *msg);
void		clean_conections(t_data *data);

void		wrong_write_line(int position, char *line);
void		write_info_save(int position_x, int position_y, char _char);
void		exit_msg(char *msg);
void		delete_map(char **map);

t_bool		compare_strings(char *first_word, char *coordinate);
char		*firts_number(char *str);
char		*first_word(char *str);

t_bool		cpy_int_valid(char **dst, char *data);

char		*data_in_line(char *str);

t_bool		extract_colors(int dst[], char *numbers);
int			coordinates(char *line);

int			open_texture(int coordinates, char *path_file, t_parse *data);
int			open_file_parser(int *dst, char *path_file);

int			fill_collor(int collor, char *numbers, t_parse *data);
int			collor_rgb(char *line);

t_bool		extract_data(t_parse *data, char **full_map);

#endif

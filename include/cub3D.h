/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwalas- <wwallas-@student.42sp.org.br>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 13:32:06 by wwallas-          #+#    #+#             */
/*   Updated: 2023/02/11 13:26:35 by wwalas-          ###   ########.fr       */
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

# define RED 0x00FF0000
# define RGB_MAROON 0x00800000
# define RGB_WHITE 0x00FFFFFF
# define FLOOT_COLOR 0x8B4513
# define SKY_COLOR 0x87CEEB


# define P_Y 0
# define P_X 1

# define PRESS_KEY 2
# define EXIT 17

#define WIDTH 640
#define HEIGHT 480


#define MINI_MAP_ERR "Pointer full map is NULL, Not creat mini map"
#define INIT_MINI_MAP_ERR "The start of the mini map is bigger than the size of the full map"
# define MOD_DEBUG "\tDEBUG MODE ON\n"
# define INVALID_ARGC "Invalid number of argument\n"
# define INVALID_ARGV "Invalid arguments passed\n"
# define NULL_ARGV "Invalid flag passed\n"

# define MLX_NULL "Error: Not init mlx\n"


# define NOT_COMPATIBLE 0
# define NEW_LINE 1
# define END_READ 2
# define INVALID_DATA -1

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

t_bool		open_file_status(int *dst, char *path_file);

t_bool		manipulating_map(t_data *data);
t_bool		valid_chars_or_die(t_map *data);
t_bool		valid_chars_line(t_map *data, char *line);
t_bool		interactor_chars_status(char _char);
t_bool		save_position_player(t_map *data, int position_x, char _char);
t_bool		set_direction_player(t_map *data, char c);

t_bool		alloc_map_status(t_map *data, int fd);
t_bool		get_valid_line(char **dst, int fd);
void		remove_char_of_player(t_map *data);
t_bool		check_parameters(t_map *data, int fd);

t_bool		verify_exit_status(t_map *data);
t_bool		val_move_right(char **map, int *posi_x, int posi_y);
t_bool		val_move_down(char **map, int posi_x, int *posi_y);
t_bool		val_move_left(char **map, int *posi_x, int posi_y);
t_bool		val_move_up(char **map, int posi_x, int *posi_y);
t_bool		verify_not_close(char **map, int x, int y, t_bool *status);


void		delete_map(char **map);

/*							ULTS											  */

char		*get_line(t_map *data, char **line);
t_bool		interactor_chars(t_map *data, char _char);
t_bool		is_special_char(char _char);
t_bool		valid_char_or_die(char _char);

/******************************************************************************/
/*							INITIALIZE										  */
/******************************************************************************/

void		init_data_or_die(t_data *data, char *file_name);
t_bool		init_mlx_status(t_data *data);
t_bool		init_windows_or_die(t_data *data);
t_bool		init_img(t_data *data);


t_bool		init_texture(t_data *data);

/******************************************************************************/
/*							DRAW_MAP										  */
/******************************************************************************/

t_bool		draw_map_status(t_data *data);
void		draw_map(t_data *data);

void		print_larger_pixel(t_data *data, int x, int y, int color);
void		my_mlx_pixel_put(t_img *img, int x, int y, int color);

void		render_background(t_data *data);
void		draw_mini_map(t_data *data);

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
void		update_p_player(t_map *map, double position_y, double position_x);

void		draw_mapingd(char **map);

double		player_p_x(t_data *data);
double		player_p_y(t_data *data);

/******************************************************************************/
/*								RAYCAST										  */
/******************************************************************************/

void		raycast(t_data *data);
void		calculate_ray_position_direction(t_raycast *itens, int x);
void		position_player_map(t_raycast *itens, t_data *data);
void		length_ray(t_raycast *itens);
void		length_ray_next_x_y(t_raycast *itens, t_data *data);
void		jump_next_square_and_verify_hit_wall(t_raycast *itens, t_data *data);
void		calculate_height_line(t_raycast *itens);
void		calculate_pixel(t_raycast *itens);

int			is_valid_position(t_map *map, double x, double y);
int			cleanup_program(t_data *data);


void		map_look_right(t_map *map);
void		map_look_left(t_map *map);

/******************************************************************************/
/*								CONTROL/DEBUG								  */
/******************************************************************************/
t_bool		*flag(void);
void		set_flag(t_bool _flag);
t_bool		has_flag(void);

t_bool		debug_printc(t_bool mod_debug, char *prefix, char *msg);
t_bool		debug_printi(t_bool mod_debug, char *prefix, int number);
t_bool		msg_and_error(char *prefix, char *msg);
void		wrong_write_line(int position, char *line);

void		write_info_save(int position_x, int position_y, char _char);
void		exit_msg(char *msg);
void		delete_map(char **map);


/******************************************************************************/
/*								PARSER										  */
/******************************************************************************/
t_bool		extract_data_status(t_data *data, int fd);
int			extract_data_map(t_parse *data, int fd);
int			extract_data_line(t_parse *data, char *line);
char		*data_in_line(char *line);
int			open_texture_is_clear_path(int *dst, char *path_file);
char		*get_line_p(char **line, int fd);
void		interact_size_d_map(t_parse *data);
t_bool		all_coordinates_valid(t_parse *data);

int			extract_colors_status(int dst[], char *numbers);
int			extract_rgb(int dst[], char *data_line);
void		avance_is_check_end(char **data_line, char *number);
char		*firts_number(char *str);
t_bool		get_int_valid(char **dst, char *data_line);

t_bool		compare_strings(char *first_word, char *coordinate);
char		*data_in_line(char *str);

char		*first_word(char *str);

int			coordinates(char *line);
int			open_texture(t_parse *data, int coordinates, char *path_file);

int			fill_collor(t_parse *data, int collor, char *numbers);
int			collor_rgb(char *line);



void		exit_msg(char *msg);
void		clean_connections(t_data *data);
#endif

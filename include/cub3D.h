/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwalas- <wwallas-@student.42sp.org.br>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 13:32:06 by wwallas-          #+#    #+#             */
/*   Updated: 2023/01/27 12:01:57 by wwalas-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <libft.h>
# include <mlx.h>
# include <structs.h>
# include <math.h>


# include <stdio.h>

# define VALID_CHARS "01NSEW\n"


# define RGB_RED 0x00FF0000
# define RGB_MAROON 0x00800000
# define RGB_WHITE 0x00FFFFFF

# define P_Y 0
# define P_X 1

# define PRESS_KEY 2
# define EXIT 17

#define WIDTH 640
#define HEIGHT 480

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

t_bool		open_file_or_die(t_map *data);

t_bool		valid_map(t_data *data);
t_bool		valid_chars_or_die(t_map *data);
t_bool		valid_chars_line(t_map *data, char *line);
t_bool		interactor_chars_or_die(t_map *data, char _char);
void		save_position_player(t_map *data, int position_x, char _char);
t_bool		verify_exit_or_die(t_map *data);

t_bool		alloc_map_status(t_map *data);
void		delete_map(char **map);

/*							ULTS											  */

char		*get_line(t_map *data, char **line);
t_bool		interactor_chars(t_map *data, char _char);
t_bool		is_special_char(char _char);
t_bool		valid_char_or_die(char letter);

/******************************************************************************/
/*							INITIALIZE										  */
/******************************************************************************/

void		init_data(t_data *data, char *file_name);
t_bool		init_mlx_or_die(t_data *data);
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

void		draw_map_debug(char **map);
void		testes(t_data *data);

void		creat_img(t_data *data);
void		get_addr_img(t_img *img);
double		player_p_x(t_data *data);
double		player_p_y(t_data *data);


/******************************************************************************/
/*								RAYCAST										  */
/******************************************************************************/

void	raycast(t_data *data);
void	calculate_ray_position_direction(t_raycast *itens, int x);
void	position_player_map(t_raycast *itens, t_data *data);
void	length_ray(t_raycast *itens);
void	length_ray_next_x_y(t_raycast *itens, t_data *data);
void	jump_next_square_and_verify_hit_wall(t_raycast *itens, t_data *data);
void	calculate_height_line(t_raycast *itens, t_data *data);
void	calculate_pixel(t_raycast *itens, t_data *data);

int		is_valid_poosition(t_map *map, double x, double y);
int		cleanup_program(t_data *data);

#endif

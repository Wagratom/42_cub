/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwalas- <wwallas-@student.42sp.org.br>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 13:58:56 by wwallas-          #+#    #+#             */
/*   Updated: 2023/02/13 22:52:11 by wwalas-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

t_bool	check_mod_debug(char *flag)
{
	if (flag == NULL)
		return (FALSE);
	if (!ft_str_eq(flag, "-D"))
		return (FALSE);
	set_flag(TRUE);
	debug_printc(has_flag(), R, MOD_DEBUG);
	return (TRUE);
}

t_bool	check_extencion(char *file_name)
{
	char	*extencion;

	if (file_name == NULL)
		return (FALSE);
	extencion = ft_strchr(file_name, '.');
	if (!ft_str_eq(extencion, ".cub"))
		return (FALSE);
	return (TRUE);
}

void	valid_arguments(int argc, char *argv[])
{
	debug_printc(has_flag(), C, "\tValid arguments...");
	if (argc <= 1 || argc >= 4)
		exit_msg(INVALID_ARGC);
	if (argv == NULL || *argv == NULL)
		exit_msg(INVALID_ARGV);
	if (!check_extencion(argv[0]))
		exit_msg(INVALID_EXTENCION);
	if (argv[1] != NULL && !ft_str_eq(argv[1], "-D"))
		exit_msg(INVALID_FLAG);
	debug_printc(has_flag(), "Arguments: ", "OK\n");
}

int	main(int argc, char *argv[])
{
	t_data	data;

	check_mod_debug(argv[2]);
	valid_arguments(argc, &argv[1]);
	init_data_or_die(&data, argv[1]);
	manipulating_map(&data);
	init_windows_or_die(&data);
	start_game(&data);
	mlx_loop(data.mlx);
}

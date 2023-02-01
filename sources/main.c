/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwalas- <wwallas-@student.42sp.org.br>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 13:58:56 by wwallas-          #+#    #+#             */
/*   Updated: 2023/02/01 13:58:29 by wwalas-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

t_bool	check_mod_debug(char *flag)
{
	if (!ft_str_eq(flag, "-D"))
		return (FALSE);
	set_flag(TRUE);
	write(1, MOD_DEBUG, ft_strlen(MOD_DEBUG));
	return (TRUE);
}

void	valid_arguments(int argc, char *argv[])
{
	debug_printC(has_flag(), NULL, "\tValid arguments...");
	if (argc <= 1 || argc >= 4)
		exit_msg(INVALID_ARGC);
	if (argv == NULL || *argv == NULL)
		exit_msg(INVALID_ARGV);
	if (argv[1] != NULL && !ft_str_eq(argv[1], "-D"))
		exit_msg(NULL_ARGV);
	debug_printC(has_flag(), "Arguments: ", "OK\n");
}

int	main(int argc, char *argv[])
{
	t_data	data;
	int		dst[10];

	int teste;
	open_file_is_clear_path(&teste, "./texture/north");
	printf("teste = %d\n", teste);
	// check_mod_debug(argv[2]);
	// valid_arguments(argc, &argv[1]);
	// init_data(&data, argv[1]);
	// valid_map(&data);
	// init_windows_or_die(&data);
	// start_game(&data);
	// mlx_loop(data.mlx);
}

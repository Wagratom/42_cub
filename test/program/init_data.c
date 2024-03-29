/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwalas- <wwallas-@student.42sp.org.br>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 09:15:40 by wwallas-          #+#    #+#             */
/*   Updated: 2023/02/11 10:43:37 by wwalas-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../minunit.h"

void	test_setup(void)
{
}

void	test_teardown(void)
{
}

MU_TEST(init_data_tst)
{
	t_data	data;

	ft_bzero(&data, sizeof(data));
	init_data_or_die(&data, "irrelevante");
	mu_check(data.mlx != NULL);
	mu_check(data.img.img != NULL);
	mu_check(data.img.addr != NULL);
	clean_connections(&data);
}

MU_TEST(mlx_null)
{
	t_data	data;

	ft_bzero(&data, sizeof(data));
	data.mlx = NULL;
	mu_assert_int_eq(init_img(&data), FALSE);
	mu_check(data.mlx == NULL);
	mu_check(data.img.img == NULL);
	mu_check(data.img.addr == NULL);
}



MU_TEST_SUITE(test_suite)
{
	MU_SUITE_CONFIGURE(&test_setup, &test_teardown);

	MU_RUN_TEST(init_data_tst);
	MU_RUN_TEST(mlx_null);
}

MU_MAIN
{
	MU_DIVIDER;
	MU_RUN_SUITE(test_suite);
	MU_REPORT();
	argc = argc;
	argv = argv;
	envp = envp;
	return (MU_EXIT_CODE);
}

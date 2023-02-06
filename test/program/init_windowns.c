/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_windowns.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwalas- <wwallas-@student.42sp.org.br>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 09:15:40 by wwallas-          #+#    #+#             */
/*   Updated: 2023/02/01 23:43:56 by wwalas-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../minunit.h"

t_data data;

void	test_setup(void)
{
	set_flag(FALSE);
}

void	test_teardown(void)
{
}

MU_TEST(init_wondows_tst)
{
	int index;

	bzero(&data, sizeof(t_data));
	mu_assert_int_eq(init_windows_or_die(&data), FALSE);

	init_mlx_status(&data);
	mu_assert_int_eq(init_windows_or_die(&data), TRUE);
	clean_conections(&data);
}


MU_TEST_SUITE(test_suite)
{
	MU_SUITE_CONFIGURE(&test_setup, &test_teardown);

	MU_RUN_TEST(init_wondows_tst);
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

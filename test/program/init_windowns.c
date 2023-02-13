/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_windowns.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwalas- <wwallas-@student.42sp.org.br>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 09:15:40 by wwallas-          #+#    #+#             */
/*   Updated: 2023/02/13 16:01:35 by wwalas-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../minunit.h"

void	test_setup(void)
{
	set_flag(FALSE);
}

void	test_teardown(void)
{
}

MU_TEST(init_wondows_tst)
{
	t_data data;

	bzero(&data, sizeof(t_data));
	mu_assert_int_eq(init_windows_or_die(&data), FALSE);
	if (init_mlx_status(&data))
		return ;
	mu_assert_int_eq(init_windows_or_die(&data), TRUE);
	clean_connections(&data);
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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_windowns.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwallas- <wwallas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 09:15:40 by wwallas-          #+#    #+#             */
/*   Updated: 2022/11/11 11:13:14 by wwallas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../minunit.h"

t_data data;

void	test_setup(void)
{
	init_windows_or_die(&data);
}

void	test_teardown(void)
{
}

MU_TEST(init_wondows_tst)
{
	int index;

	bzero(&data, sizeof(t_data));
	mu_assert_int_eq(init_windows_or_die(&data), FALSE);

	init_mlx_or_die(&data);
	mu_assert_int_eq(init_windows_or_die(&data), TRUE);
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

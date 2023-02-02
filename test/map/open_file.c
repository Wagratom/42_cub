/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwalas- <wwallas-@student.42sp.org.br>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 16:59:18 by lpaulo-m          #+#    #+#             */
/*   Updated: 2023/02/02 16:28:36 by wwalas-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minunit.h"

t_map	data;

void	test_setup(void)
{
	set_flag(FALSE);
}
void	test_teardown(void)
{
}

MU_TEST(open_invalid_file_tst)
{
	ft_bzero(&data, sizeof(t_map));

	mu_assert_int_eq(open_file_status(&data.fd, "./map/map.c"), FALSE);
	mu_assert_int_eq(open_file_status(&data.fd, "./map/map.cu"), FALSE);
	mu_assert_int_eq(open_file_status(&data.fd, "./map/map.cubb"), FALSE);
}

MU_TEST(open_file_tst)
{
	ft_bzero(&data, sizeof(t_map));

	mu_assert_int_eq(open_file_status(&data.fd, "./map/map.cub"), TRUE);
}

MU_TEST_SUITE(open_file_suite)
{
	MU_SUITE_CONFIGURE(&test_setup, &test_teardown);

	MU_RUN_TEST(open_invalid_file_tst);
	MU_RUN_TEST(open_file_tst);
}

MU_MAIN
{
	MU_DIVIDER;
	MU_RUN_SUITE(open_file_suite);
	MU_REPORT();
	return (MU_EXIT_CODE);
}

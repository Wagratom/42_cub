/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_close.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwalas- <wwallas-@student.42sp.org.br>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 16:59:18 by lpaulo-m          #+#    #+#             */
/*   Updated: 2023/01/30 15:32:45 by wwalas-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minunit.h"
#include "../ults.h"

t_map	data;

void	test_setup(void)
{

}
void	test_teardown(void)
{
}

MU_TEST(map_closed_tst)
{
	fake_alloc_map(&data, 8, 3, 8, "map/test1.cub");
	mu_assert_int_eq(verify_exit_status(&data), TRUE);
	delete_map(data.map);
}

MU_TEST(not_closed_tst)
{

	fake_alloc_map(&data, 8, 3, 8, "map/not_closed.cub");
	mu_assert_int_eq(verify_exit_status(&data), FALSE);
	delete_map(data.map);
}

MU_TEST(map_closed_1_tst)
{
	fake_alloc_map(&data, 8, 3, 8, "map/map_closed_1.cub");
	mu_assert_int_eq(verify_exit_status(&data), TRUE);
	delete_map(data.map);
}

MU_TEST(map_closed_2_tst)
{
	fake_alloc_map(&data, 8, 3, 8, "map/map_closed_2.cub");
	mu_assert_int_eq(verify_exit_status(&data), TRUE);
	delete_map(data.map);
}

MU_TEST_SUITE(verify_close_suite)
{
	MU_SUITE_CONFIGURE(&test_setup, &test_teardown);

	MU_RUN_TEST(map_closed_tst);
	MU_RUN_TEST(not_closed_tst);
	MU_RUN_TEST(map_closed_1_tst);
	MU_RUN_TEST(map_closed_2_tst);
}

MU_MAIN
{
	MU_DIVIDER;
	MU_RUN_SUITE(verify_close_suite);
	MU_REPORT();
	return (MU_EXIT_CODE);
}

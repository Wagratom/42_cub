/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_close.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwallas- <wwallas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 16:59:18 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/12/04 13:52:25 by wwallas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minunit.h"

t_map	data;

void	test_setup(void)
{
}
void	test_teardown(void)
{
}

MU_TEST(map_closed_tst)
{
	ft_bzero(&data, sizeof(t_data));
	data.size_y = 8;
	data.p_player[P_X] = 8;
	data.p_player[P_Y] = 3;
	data.file_name = "map/map.cub";
	alloc_map_or_die(&data);
	mu_assert_int_eq(verify_exit_or_die(&data), TRUE);
}

MU_TEST(not_closed_tst)
{
	ft_bzero(&data, sizeof(t_data));
	data.size_y = 8;
	data.p_player[P_X] = 8;
	data.p_player[P_Y] = 3;
	data.file_name = "map/not_closed.cub";
	alloc_map_or_die(&data);
	mu_assert_int_eq(verify_exit_or_die(&data), FALSE);
}

MU_TEST(map_closed_1_tst)
{
	ft_bzero(&data, sizeof(t_data));
	data.size_y = 8;
	data.p_player[P_X] = 8;
	data.p_player[P_Y] = 3;
	data.file_name = "map/map_closed_1.cub";
	alloc_map_or_die(&data);
	mu_assert_int_eq(verify_exit_or_die(&data), TRUE);
}

MU_TEST(map_closed_2_tst)
{
	ft_bzero(&data, sizeof(t_data));
	data.size_y = 8;
	data.p_player[P_X] = 8;
	data.p_player[P_Y] = 3;
	data.file_name = "map/map_closed_2.cub";
	alloc_map_or_die(&data);
	printf("c = %c\n", data.map[data.p_player[P_Y]][data.p_player[P_X]]);
	mu_assert_int_eq(verify_exit_or_die(&data), TRUE);
}

MU_TEST_SUITE(verify_close_suite)
{
	MU_SUITE_CONFIGURE(&test_setup, &test_teardown);

	//MU_RUN_TEST(map_closed_tst);
	//MU_RUN_TEST(not_closed_tst);
	//MU_RUN_TEST(map_closed_1_tst);
	MU_RUN_TEST(map_closed_2_tst);
}

MU_MAIN
{
	MU_DIVIDER;
	MU_RUN_SUITE(verify_close_suite);
	MU_REPORT();
	return (MU_EXIT_CODE);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_close.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwallas- <wwallas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 16:59:18 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/12/03 17:53:46 by wwallas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minunit.h"

t_data	data;
int		test = 0;

void	test_setup(void)
{
	ft_bzero(&data, sizeof(t_data));
	data.map.size_y = 8;
	data.map.p_player[P_X] = 7;
	data.map.p_player[P_Y] = 3;
	data.map.file_name = "map/map.cub";
	alloc_map_or_die(&data.map);
}
void	test_teardown(void)
{
}

MU_TEST(alloc_map_tst)
{
	verify_is_closed(&data.map, data.map.p_player[P_X], data.map.p_player[P_Y], &test);
	mu_assert_int_eq(test, 0);
}

MU_TEST_SUITE(map)
{
	MU_SUITE_CONFIGURE(&test_setup, &test_teardown);

	MU_RUN_TEST(alloc_map_tst);
}

MU_MAIN
{
	MU_DIVIDER;
	MU_RUN_SUITE(map);
	MU_REPORT();
	return (MU_EXIT_CODE);
}

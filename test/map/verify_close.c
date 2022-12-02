/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_close.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwallas- <wwallas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 16:59:18 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/12/02 12:04:47 by wwallas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minunit.h"

t_data	data;

void	test_setup(void)
{
	ft_bzero(&data, sizeof(t_data));
	data.map.size_y = 8;
	data.map.file_name = "map/map.cub";
	alloc_map_or_die(&data.map);
}
void	test_teardown(void)
{
}

MU_TEST(alloc_map_tst)
{
	check_close(&data.map, 4, 4);
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

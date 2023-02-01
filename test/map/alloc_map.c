/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwalas- <wwallas-@student.42sp.org.br>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 16:59:18 by lpaulo-m          #+#    #+#             */
/*   Updated: 2023/02/01 16:35:19 by wwalas-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minunit.h"

t_data	data;

void	test_setup(void)
{
	ft_bzero(&data, sizeof(t_data));
	set_flag(TRUE);
	data.map.size_y = 7;
	data.map.file_name = "map/map.cub";
}
void	test_teardown(void)
{
}

MU_TEST(alloc_map_tst)
{
	alloc_map_status(&data.map);
	mu_check(data.map.map != NULL);
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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwalas- <wwallas-@student.42sp.org.br>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 16:59:18 by lpaulo-m          #+#    #+#             */
/*   Updated: 2023/02/01 23:15:42 by wwalas-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minunit.h"
#include "../ults.h"

t_data	data;

void	test_setup(void)
{
	set_flag(FALSE);
}
void	test_teardown(void)
{
}

MU_TEST(alloc_map_tst)
{
	ft_bzero(&data, sizeof(t_data));
	fake_alloc_map(&data.map, 5, 5, 18, "map/map.cub");
	mu_check(data.map.map != NULL);
	delete_map(data.map.map);
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

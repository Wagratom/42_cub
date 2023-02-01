/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwalas- <wwallas-@student.42sp.org.br>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 15:39:34 by wwalas-           #+#    #+#             */
/*   Updated: 2023/01/31 13:12:16 by wwalas-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minunit.h"
#include "../ults.h"

void	test_setup(void)
{
}
void	test_teardown(void)
{
}

MU_TEST(extract_data_tst)
{
	t_data data;
	char **map;

	map = retorne_fake_map(24, "map/pdffull.cub");
	set_flag(TRUE);
	mu_assert_int_eq(extract_data(&data.data_map, map), FALSE);
	delete_map(map);
}

MU_TEST_SUITE(suite_extract_data)
{
	MU_SUITE_CONFIGURE(&test_setup, &test_teardown);

	MU_RUN_TEST(extract_data_tst);
}

MU_MAIN
{
	MU_DIVIDER;
	MU_RUN_SUITE(suite_extract_data);
	MU_REPORT();
	return (MU_EXIT_CODE);
}

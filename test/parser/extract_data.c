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
	set_flag(FALSE);
}
void	test_teardown(void)
{
}

MU_TEST(NULL_tst)
{
	t_data data;
	char **map;

	mu_assert_int_eq(extract_data_map(&data, NULL), FALSE);
}

MU_TEST(extract_data_pdf)
{
	t_data	data;
	char	**map;

	map = retorne_fake_map(24, "map/parser/pdf.cub");
	mu_assert_int_eq(extract_data_map(&data, map), FALSE);
	delete_map(map);
}

MU_TEST(extract_data_north)
{
	t_data data;
	char **map;

	map = retorne_fake_map(24, "map/parser/north.cub");
	mu_assert_int_eq(extract_data_map(&data, map), FALSE);
	delete_map(map);
}

MU_TEST(extract_data_south)
{
	t_data data;
	char **map;

	map = retorne_fake_map(24, "map/parser/south.cub");
	mu_assert_int_eq(extract_data_map(&data, map), FALSE);
	delete_map(map);
}

MU_TEST(extract_data_west)
{
	t_data data;
	char **map;

	map = retorne_fake_map(24, "map/parser/west.cub");
	mu_assert_int_eq(extract_data_map(&data, map), FALSE);
	delete_map(map);
}

MU_TEST(extract_data_valid_texture)
{
	t_data data;
	char **map;

	map = retorne_fake_map(24, "map/parser/valid_texture.cub");
	mu_assert_int_eq(extract_data_map(&data, map), TRUE);

	mu_assert_int_eq(data.d_map.f[0], 220);
	mu_assert_int_eq(data.d_map.f[1], 100);
	mu_assert_int_eq(data.d_map.f[2], 0);

	mu_assert_int_eq(data.d_map.c[0], 225);
	mu_assert_int_eq(data.d_map.c[1], 30);
	mu_assert_int_eq(data.d_map.c[2], 0);
	delete_map(map);
}

MU_TEST(extract_data_valid_texture2)
{
	t_data data;
	char **map;

	map = retorne_fake_map(24, "map/parser/valid_texture2.cub");
	mu_assert_int_eq(extract_data_map(&data, map), TRUE);

	mu_assert_int_eq(data.d_map.f[0], 220);
	mu_assert_int_eq(data.d_map.f[1], 100);
	mu_assert_int_eq(data.d_map.f[2], 0);

	mu_assert_int_eq(data.d_map.c[0], 225);
	mu_assert_int_eq(data.d_map.c[1], 30);
	mu_assert_int_eq(data.d_map.c[2], 0);
	delete_map(map);
}

MU_TEST_SUITE(suite_extract_data)
{
	MU_SUITE_CONFIGURE(&test_setup, &test_teardown);

	MU_RUN_TEST(NULL_tst);
	MU_RUN_TEST(extract_data_pdf);
	MU_RUN_TEST(extract_data_north);
	MU_RUN_TEST(extract_data_south);
	MU_RUN_TEST(extract_data_west);
	MU_RUN_TEST(extract_data_valid_texture);
	MU_RUN_TEST(extract_data_valid_texture2);
}

MU_MAIN
{
	MU_DIVIDER;
	MU_RUN_SUITE(suite_extract_data);
	MU_REPORT();
	return (MU_EXIT_CODE);
}

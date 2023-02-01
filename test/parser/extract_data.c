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

MU_TEST(extract_data_pdf)
{
	t_data data;
	char **map;

	map = retorne_fake_map(24, "map/parser/pdf.cub");
	set_flag(TRUE);
	mu_assert_int_eq(extract_data(&data.data_map, map), FALSE);
	delete_map(map);
}

MU_TEST(extract_data_north)
{
	t_data data;
	char **map;

	map = retorne_fake_map(24, "map/parser/north.cub");
	set_flag(TRUE);
	mu_assert_int_eq(extract_data(&data.data_map, map), FALSE);
	delete_map(map);
}

MU_TEST(extract_data_south)
{
	t_data data;
	char **map;

	map = retorne_fake_map(24, "map/parser/south.cub");
	set_flag(TRUE);
	mu_assert_int_eq(extract_data(&data.data_map, map), FALSE);
	delete_map(map);
}

MU_TEST(extract_data_west)
{
	t_data data;
	char **map;

	map = retorne_fake_map(24, "map/parser/west.cub");
	set_flag(TRUE);
	mu_assert_int_eq(extract_data(&data.data_map, map), FALSE);
	delete_map(map);
}

MU_TEST(extract_data_valid_texture)
{
	t_data data;
	char **map;

	map = retorne_fake_map(24, "map/parser/valid_texture.cub");
	set_flag(TRUE);
	mu_assert_int_eq(extract_data(&data.data_map, map), FALSE);
	delete_map(map);
}

MU_TEST_SUITE(suite_extract_data)
{
	MU_SUITE_CONFIGURE(&test_setup, &test_teardown);

	// MU_RUN_TEST(extract_data_pdf);
	// MU_RUN_TEST(extract_data_north);
	// MU_RUN_TEST(extract_data_soth);
	// MU_RUN_TEST(extract_data_west);
	MU_RUN_TEST(extract_data_valid_texture);
}

MU_MAIN
{
	MU_DIVIDER;
	MU_RUN_SUITE(suite_extract_data);
	MU_REPORT();
	return (MU_EXIT_CODE);
}

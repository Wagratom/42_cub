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
	t_map	data;

	mu_assert_int_eq(extract_data_status(&data, -1), FALSE);
}

MU_TEST(extract_data_pdf)
{
	t_map	data;

	ft_bzero(&data, sizeof(t_map));

	open_file_status(&data.fd, "map/parser/pdf.cub");
	mu_assert_int_eq(extract_data_status(&data, data.fd), FALSE);
}

MU_TEST(extract_data_north)
{
	t_map	data;

	ft_bzero(&data, sizeof(t_map));
	open_file_status(&data.fd, "map/parser/north.cub");
	mu_assert_int_eq(extract_data_status(&data, data.fd), FALSE);
}

MU_TEST(extract_data_south)
{
	t_map	data;

	ft_bzero(&data, sizeof(t_map));

	open_file_status(&data.fd, "map/parser/south.cub");
	mu_assert_int_eq(extract_data_status(&data, data.fd), FALSE);
}

MU_TEST(extract_data_west)
{
	t_map	data;

	ft_bzero(&data, sizeof(t_map));

	open_file_status(&data.fd, "map/parser/west.cub");
	mu_assert_int_eq(extract_data_status(&data, data.fd), FALSE);
}

MU_TEST(extract_data_valid_texture)
{
	t_map	data;

	ft_bzero(&data, sizeof(t_map));

	open_file_status(&data.fd, "map/parser/valid_texture.cub");
	mu_assert_int_eq(extract_data_status(&data, data.fd), TRUE);

	mu_assert_int_eq(data.d_map.f[0], 220);
	mu_assert_int_eq(data.d_map.f[1], 100);
	mu_assert_int_eq(data.d_map.f[2], 0);

	mu_assert_int_eq(data.d_map.c[0], 225);
	mu_assert_int_eq(data.d_map.c[1], 30);
	mu_assert_int_eq(data.d_map.c[2], 0);
}

MU_TEST(extract_data_valid_texture2)
{
	t_map	data;

	ft_bzero(&data, sizeof(t_map));

	open_file_status(&data.fd, "map/parser/valid_texture2.cub");
	mu_assert_int_eq(extract_data_status(&data, data.fd), TRUE);

	mu_assert_int_eq(data.d_map.f[0], 220);
	mu_assert_int_eq(data.d_map.f[1], 100);
	mu_assert_int_eq(data.d_map.f[2], 0);

	mu_assert_int_eq(data.d_map.c[0], 225);
	mu_assert_int_eq(data.d_map.c[1], 30);
	mu_assert_int_eq(data.d_map.c[2], 0);

	mu_check(data.d_map.coordinites[NORTH] != 0);
	mu_check(data.d_map.coordinites[SOUTH] != 0);
	mu_check(data.d_map.coordinites[WEST] != 0);

	mu_check(data.d_map.coordinites[NORTH] != -1);
	mu_check(data.d_map.coordinites[SOUTH] != -1);
	mu_check(data.d_map.coordinites[WEST] != -1);
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

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
	t_data	data;

	mu_assert_int_eq(extract_data_status(&data, -1), FALSE);
}

MU_TEST(invalid_pdf)
{
	t_data	data;

	ft_bzero(&data, sizeof(t_data));
	init_data_or_die(&data, "map/parser/pdf.cub");

	open_file_status(&data.map.fd, "map/parser/pdf.cub");
	mu_assert_int_eq(extract_data_status(&data, data.map.fd), FALSE);

	cleanup_program(&data);
}

MU_TEST(invalid_north)
{
	t_data	data;

	ft_bzero(&data, sizeof(t_data));
	init_data_or_die(&data, "map/parser/north.cub");
	open_file_status(&data.map.fd, "map/parser/north.cub");

	// set_flag(TRUE);
	mu_assert_int_eq(extract_data_status(&data, data.map.fd), FALSE);
	cleanup_program(&data);
}

MU_TEST(invalid_south)
{
	t_data	data;

	ft_bzero(&data, sizeof(t_data));
	init_data_or_die(&data, "map/parser/south.cub");
	open_file_status(&data.map.fd, "map/parser/south.cub");

	mu_assert_int_eq(extract_data_status(&data, data.map.fd), FALSE);
	cleanup_program(&data);
}

MU_TEST(invalid_west)
{
	t_data	data;

	ft_bzero(&data, sizeof(t_data));
	init_data_or_die(&data, "map/parser/west.cub");
	open_file_status(&data.map.fd, "map/parser/west.cub");

	mu_assert_int_eq(extract_data_status(&data, data.map.fd), FALSE);
	cleanup_program(&data);
}

MU_TEST(valid_texture)
{
	t_data	data;

	ft_bzero(&data, sizeof(t_data));
	init_data_or_die(&data, "map/parser/valid_texture.cub");
	open_file_status(&data.map.fd, "map/parser/valid_texture.cub");

	mu_assert_int_eq(extract_data_status(&data, data.map.fd), TRUE);

	mu_assert_int_eq(data.parser.f[0], 220);
	mu_assert_int_eq(data.parser.f[1], 100);
	mu_assert_int_eq(data.parser.f[2], 0);

	mu_assert_int_eq(data.parser.c[0], 225);
	mu_assert_int_eq(data.parser.c[1], 30);
	mu_assert_int_eq(data.parser.c[2], 0);

	cleanup_program(&data);
}

MU_TEST(valid_texture2)
{
	t_data	data;

	ft_bzero(&data, sizeof(t_data));
	init_data_or_die(&data, "map/parser/valid_texture2.cub");
	open_file_status(&data.map.fd, "map/parser/valid_texture2.cub");

	mu_assert_int_eq(extract_data_status(&data, data.map.fd), TRUE);

	mu_assert_int_eq(data.parser.f[0], 220);
	mu_assert_int_eq(data.parser.f[1], 100);
	mu_assert_int_eq(data.parser.f[2], 0);

	mu_assert_int_eq(data.parser.c[0], 225);
	mu_assert_int_eq(data.parser.c[1], 30);
	mu_assert_int_eq(data.parser.c[2], 0);
	cleanup_program(&data);
}

MU_TEST(very_texture)
{
	t_data	data;

	ft_bzero(&data, sizeof(t_data));
	init_data_or_die(&data, "map/parser/very_texture.cub");
	open_file_status(&data.map.fd, "map/parser/very_texture.cub");

	mu_assert_int_eq(extract_data_status(&data, data.map.fd), FALSE);
	cleanup_program(&data);
}

MU_TEST_SUITE(suite_extract_data)
{
	MU_SUITE_CONFIGURE(&test_setup, &test_teardown);

	MU_RUN_TEST(NULL_tst);
	MU_RUN_TEST(invalid_pdf);
	MU_RUN_TEST(invalid_north);
	MU_RUN_TEST(invalid_south);
	MU_RUN_TEST(invalid_west);
	MU_RUN_TEST(valid_texture);
	MU_RUN_TEST(valid_texture2);
	MU_RUN_TEST(very_texture);
}

MU_MAIN
{
	MU_DIVIDER;
	MU_RUN_SUITE(suite_extract_data);
	MU_REPORT();
	return (MU_EXIT_CODE);
}

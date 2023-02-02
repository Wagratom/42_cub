/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_chars.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwalas- <wwallas-@student.42sp.org.br>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 16:59:18 by lpaulo-m          #+#    #+#             */
/*   Updated: 2023/02/01 22:33:05 by wwalas-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minunit.h"
#include "../ults.h"

t_map	data;

void	test_setup(void)
{
	set_flag(FALSE);
}
void	test_teardown(void)
{
}

MU_TEST(valid_chars)
{
	ft_bzero(&data, sizeof(t_data));
	mu_assert_int_eq(valid_chars_line(&data, ft_strdup("0000000000000000000000000000000")), TRUE);
	mu_assert_int_eq(valid_chars_line(&data, "0000000000000000000000000000000\n"), TRUE);
	mu_assert_int_eq(valid_chars_line(&data, "1111111111111111111111111111111"), TRUE);
	mu_assert_int_eq(valid_chars_line(&data, "1111111111111111111111111111111\n"), TRUE);
	mu_assert_int_eq(valid_chars_line(&data, "01N\n"), TRUE);
}

MU_TEST(invalid_chars)
{
	mu_assert_int_eq(valid_chars_line(&data, "a000000000000000000000000000000"), FALSE);
	mu_assert_int_eq(valid_chars_line(&data, "000000000000000000000000000000a"), FALSE);
	mu_assert_int_eq(valid_chars_line(&data, "00000000000000a0000000000000000"), FALSE);
	mu_assert_int_eq(valid_chars_line(&data, "0000000000000000000000000000000\na"), FALSE);

	mu_assert_int_eq(valid_chars_line(&data, "a111111111111111111111111111111"), FALSE);
	mu_assert_int_eq(valid_chars_line(&data, "111111111111111b111111111111111"), FALSE);
	mu_assert_int_eq(valid_chars_line(&data, "111111111111111111111111111111c"), FALSE);
	mu_assert_int_eq(valid_chars_line(&data, "1111111111111111111111111111111\nd"), FALSE);

	mu_assert_int_eq(valid_chars_line(&data, "1111111111111111111111111111111\n@"), FALSE);
	mu_assert_int_eq(valid_chars_line(&data, "01NSEW\n01NSEW\n01NSEW\n01NSEW\n"), FALSE);
}


MU_TEST(map_valid_tst)
{
	ft_bzero(&data, sizeof(t_map));
	data.file_name = "map/map.cub";
	open_file_status(&data);
	mu_assert_int_eq(valid_chars_or_die(&data), TRUE);
}

MU_TEST(map_invalid_tst)
{
	ft_bzero(&data, sizeof(t_map));
	data.file_name = "map/many_character.cub";
	open_file_status(&data);
	mu_assert_int_eq(valid_chars_or_die(&data), FALSE);
}

MU_TEST_SUITE(valid_chars_line_suite)
{
	MU_SUITE_CONFIGURE(&test_setup, &test_teardown);

	//esse tem que rodar um de cada vez porque a função e estatica

	// MU_RUN_TEST(valid_chars);
	// MU_RUN_TEST(invalid_chars);
	// MU_RUN_TEST(map_valid_tst);
	MU_RUN_TEST(map_invalid_tst);
}

MU_MAIN
{
	MU_DIVIDER;
	MU_RUN_SUITE(valid_chars_line_suite);
	MU_REPORT();
	return (MU_EXIT_CODE);
}

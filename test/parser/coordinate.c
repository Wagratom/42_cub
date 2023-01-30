/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coordinate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwalas- <wwallas-@student.42sp.org.br>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 15:39:34 by wwalas-           #+#    #+#             */
/*   Updated: 2023/01/30 16:40:12 by wwalas-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minunit.h"

int	foo;

void	test_setup(void)
{
}
void	test_teardown(void)
{
}

MU_TEST(north)
{
	mu_assert_int_eq(is_texture_north("N ./path_to_the_north_texture\n"), FALSE);
	mu_assert_int_eq(is_texture_north("NO ./path_to_the_north_texture\n"), TRUE);
	mu_assert_int_eq(is_texture_north("NOO ./path_to_the_north_texture\n"), FALSE);

	mu_assert_int_eq(is_texture_north("SO ./path_to_the_north_texture\n"), FALSE);
	mu_assert_int_eq(is_texture_north("WE ./path_to_the_north_texture\n"), FALSE);
	mu_assert_int_eq(is_texture_north("AE ./path_to_the_north_texture\n"), FALSE);
}

MU_TEST(south)
{
	mu_assert_int_eq(is_texture_south("S ./path_to_the_north_texture\n"), FALSE);
	mu_assert_int_eq(is_texture_south("SO ./path_to_the_north_texture\n"), TRUE);
	mu_assert_int_eq(is_texture_south("SOS ./path_to_the_north_texture\n"), FALSE);
	mu_assert_int_eq(is_texture_south("SOO ./path_to_the_north_texture\n"), FALSE);

	mu_assert_int_eq(is_texture_south("NO ./path_to_the_north_texture\n"), FALSE);
	mu_assert_int_eq(is_texture_south("WE ./path_to_the_north_texture\n"), FALSE);
	mu_assert_int_eq(is_texture_south("AE ./path_to_the_north_texture\n"), FALSE);
}

MU_TEST(west)
{
	mu_assert_int_eq(is_texture_west("W ./path_to_the_north_texture\n"), FALSE);
	mu_assert_int_eq(is_texture_west("WE ./path_to_the_north_texture\n"), TRUE);
	mu_assert_int_eq(is_texture_west("WEE ./path_to_the_north_texture\n"), FALSE);
	mu_assert_int_eq(is_texture_west("WEW ./path_to_the_north_texture\n"), FALSE);

	mu_assert_int_eq(is_texture_west("SO ./path_to_the_north_texture\n"), FALSE);
	mu_assert_int_eq(is_texture_west("NO ./path_to_the_north_texture\n"), FALSE);
	mu_assert_int_eq(is_texture_west("AE ./path_to_the_north_texture\n"), FALSE);
}

MU_TEST(east)
{
	mu_assert_int_eq(is_texture_east("E ./path_to_the_north_texture\n"), FALSE);
	mu_assert_int_eq(is_texture_east("EA ./path_to_the_north_texture\n"), TRUE);
	mu_assert_int_eq(is_texture_east("EAA ./path_to_the_north_texture\n"), FALSE);
	mu_assert_int_eq(is_texture_east("EAE ./path_to_the_north_texture\n"), FALSE);

	mu_assert_int_eq(is_texture_east("SO ./path_to_the_north_texture\n"), FALSE);
	mu_assert_int_eq(is_texture_east("WE ./path_to_the_north_texture\n"), FALSE);
	mu_assert_int_eq(is_texture_east("NO ./path_to_the_north_texture\n"), FALSE);
}

MU_TEST_SUITE(suite_coordinate)
{
	MU_SUITE_CONFIGURE(&test_setup, &test_teardown);

	MU_RUN_TEST(north);
	MU_RUN_TEST(south);
	MU_RUN_TEST(west);
	MU_RUN_TEST(east);
}

MU_MAIN
{
	MU_DIVIDER;
	MU_RUN_SUITE(suite_coordinate);
	MU_REPORT();
	return (MU_EXIT_CODE);
}

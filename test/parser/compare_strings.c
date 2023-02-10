/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compare_strings.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwalas- <wwallas-@student.42sp.org.br>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 17:04:05 by wwalas-           #+#    #+#             */
/*   Updated: 2023/02/01 16:34:20 by wwalas-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minunit.h"

void	test_setup(void)
{
	set_flag(FALSE);
}
void	test_teardown(void)
{
}

MU_TEST(north)
{
	mu_assert_int_eq(compare_strings(first_word("NO ./path_to_the_north_texture"), "NO"), TRUE);
	mu_assert_int_eq(compare_strings(first_word("SO ./path_to_the_north_texture"), "SO"), TRUE);
	mu_assert_int_eq(compare_strings(first_word("WE ./path_to_the_north_texture"), "WE"), TRUE);
	mu_assert_int_eq(compare_strings(first_word("AE ./path_to_the_north_texture"), "AE"), TRUE);

	mu_assert_int_eq(compare_strings(first_word("NO ./path_to_the_north_texture"), "SO"), FALSE);
	mu_assert_int_eq(compare_strings(first_word("SO ./path_to_the_north_texture"), "NO"), FALSE);
	mu_assert_int_eq(compare_strings(first_word("WE ./path_to_the_north_texture"), "EE"), FALSE);
	mu_assert_int_eq(compare_strings(first_word("AE ./path_to_the_north_texture"), "AA"), FALSE);
}

MU_TEST_SUITE(suite_coordinate)
{
	MU_SUITE_CONFIGURE(&test_setup, &test_teardown);

	MU_RUN_TEST(north);

}

MU_MAIN
{
	MU_DIVIDER;
	MU_RUN_SUITE(suite_coordinate);
	MU_REPORT();
	return (MU_EXIT_CODE);
}

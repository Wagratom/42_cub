/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_chars_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwallas- <wwallas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 16:59:18 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/11/30 18:27:37 by wwallas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minunit.h"

int	foo;

void	test_setup(void)
{
}
void	test_teardown(void)
{
}

MU_TEST(valid_chars)
{
	mu_assert_int_eq(valid_chars_line("0000000000000000000000000000000"), 1);
	mu_assert_int_eq(valid_chars_line("0000000000000000000000000000000\n"), 1);
	mu_assert_int_eq(valid_chars_line("1111111111111111111111111111111"), 1);
	mu_assert_int_eq(valid_chars_line("1111111111111111111111111111111\n"), 1);
	mu_assert_int_eq(valid_chars_line("01NSEW\n01NSEW\n01NSEW\n01NSEW\n"), 1);
}

MU_TEST(invalid_chars)
{
	mu_assert_int_eq(valid_chars_line("a000000000000000000000000000000"), 0);
	mu_assert_int_eq(valid_chars_line("000000000000000000000000000000a"), 0);
	mu_assert_int_eq(valid_chars_line("00000000000000a0000000000000000"), 0);
	mu_assert_int_eq(valid_chars_line("0000000000000000000000000000000\na"), 0);

	mu_assert_int_eq(valid_chars_line("a111111111111111111111111111111"), 0);
	mu_assert_int_eq(valid_chars_line("111111111111111b111111111111111"), 0);
	mu_assert_int_eq(valid_chars_line("111111111111111111111111111111c"), 0);
	mu_assert_int_eq(valid_chars_line("1111111111111111111111111111111\nd"), 0);

	mu_assert_int_eq(valid_chars_line("1111111111111111111111111111111\n@"), 0);
}

MU_TEST_SUITE(valid_chars_line_suite)
{
	MU_SUITE_CONFIGURE(&test_setup, &test_teardown);

	MU_RUN_TEST(invalid_chars);
	MU_RUN_TEST(valid_chars);
}

MU_MAIN
{
	MU_DIVIDER;
	MU_RUN_SUITE(valid_chars_line_suite);
	MU_REPORT();
	return (MU_EXIT_CODE);
}

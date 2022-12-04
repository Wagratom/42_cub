/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_chars_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwallas- <wwallas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 16:59:18 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/12/03 22:57:57 by wwallas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minunit.h"

t_data	foo;

void	test_setup(void)
{
}
void	test_teardown(void)
{
}

MU_TEST(valid_chars)
{
	ft_bzero(&foo.map, sizeof(t_data));
	mu_assert_int_eq(valid_chars_line(&foo.map, ft_strdup("0000000000000000000000000000000")), TRUE);
	mu_assert_int_eq(valid_chars_line(&foo.map, "0000000000000000000000000000000\n"), TRUE);
	mu_assert_int_eq(valid_chars_line(&foo.map, "1111111111111111111111111111111"), TRUE);
	mu_assert_int_eq(valid_chars_line(&foo.map, "1111111111111111111111111111111\n"), TRUE);
	mu_assert_int_eq(valid_chars_line(&foo.map, "01NSEW\n01NSEW\n01NSEW\n01NSEW\n"), TRUE);
}

MU_TEST(invalid_chars)
{
	mu_assert_int_eq(valid_chars_line(&foo.map, "a000000000000000000000000000000"), FALSE);
	mu_assert_int_eq(valid_chars_line(&foo.map, "000000000000000000000000000000a"), FALSE);
	mu_assert_int_eq(valid_chars_line(&foo.map, "00000000000000a0000000000000000"), FALSE);
	mu_assert_int_eq(valid_chars_line(&foo.map, "0000000000000000000000000000000\na"), FALSE);

	mu_assert_int_eq(valid_chars_line(&foo.map, "a111111111111111111111111111111"), FALSE);
	mu_assert_int_eq(valid_chars_line(&foo.map, "111111111111111b111111111111111"), FALSE);
	mu_assert_int_eq(valid_chars_line(&foo.map, "111111111111111111111111111111c"), FALSE);
	mu_assert_int_eq(valid_chars_line(&foo.map, "1111111111111111111111111111111\nd"), FALSE);

	mu_assert_int_eq(valid_chars_line(&foo.map, "1111111111111111111111111111111\n@"), FALSE);
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

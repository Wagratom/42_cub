/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_interactor.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwallas- <wwallas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 16:59:18 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/12/01 11:39:31 by wwallas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minunit.h"

t_data	foo;

void	test_setup(void)
{
}
void	test_teardown(void)
{
}

MU_TEST(open_invalid_file_tst)
{
	ft_bzero(&foo, sizeof(t_data));
	interactor_chars(&foo, 'S');
	interactor_chars(&foo, 'W');
	interactor_chars(&foo, 'E');

	mu_assert_int_eq(foo.map.chars[P_S], 1);
	mu_assert_int_eq(foo.map.chars[P_W], 1);
	mu_assert_int_eq(foo.map.chars[P_E], 1);

	interactor_chars(&foo, 'S');
	interactor_chars(&foo, 'E');

	mu_assert_int_eq(foo.map.chars[P_S], 2);
	mu_assert_int_eq(foo.map.chars[P_W], 1);
	mu_assert_int_eq(foo.map.chars[P_E], 2);
	mu_assert_int_eq(foo.map.chars[P_N], 0);
}

MU_TEST(open_file_tst)
{
}

MU_TEST_SUITE(open_file_suite)
{
	MU_SUITE_CONFIGURE(&test_setup, &test_teardown);

	MU_RUN_TEST(open_invalid_file_tst);
	MU_RUN_TEST(open_file_tst);
}

MU_MAIN
{
	MU_DIVIDER;
	MU_RUN_SUITE(open_file_suite);
	MU_REPORT();
	return (MU_EXIT_CODE);
}

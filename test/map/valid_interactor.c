/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_interactor.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwalas- <wwallas-@student.42sp.org.br>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 16:59:18 by lpaulo-m          #+#    #+#             */
/*   Updated: 2023/02/06 17:53:35 by wwalas-          ###   ########.fr       */
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

MU_TEST(open_invalid_file_tst)
{
	mu_assert_int_eq(interactor_chars_status('S'), TRUE);
	mu_assert_int_eq(interactor_chars_status('W'), FALSE);
	mu_assert_int_eq(interactor_chars_status('E'), FALSE);
}

MU_TEST_SUITE(open_file_suite)
{
	MU_SUITE_CONFIGURE(&test_setup, &test_teardown);

	MU_RUN_TEST(open_invalid_file_tst);
}

MU_MAIN
{
	MU_DIVIDER;
	MU_RUN_SUITE(open_file_suite);
	MU_REPORT();
	return (MU_EXIT_CODE);
}

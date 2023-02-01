/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_get_int_valid.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwalas- <wwallas-@student.42sp.org.br>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 15:39:34 by wwalas-           #+#    #+#             */
/*   Updated: 2023/01/31 10:24:00 by wwalas-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minunit.h"

void	test_setup(void)
{
}
void	test_teardown(void)
{
}

MU_TEST(get_get_int_valid_tst)
{
	char *dst;

	mu_assert_int_eq(get_int_valid(NULL, "220,100,0\n"), FALSE);

	mu_assert_int_eq(get_int_valid(&dst, NULL), FALSE);
	mu_assert_int_eq(get_int_valid(&dst, ""), FALSE);

	mu_assert_int_eq(get_int_valid(&dst, "220,100,0\n"), TRUE);
	mu_assert_string_eq(dst, "220");
	free(dst);

	mu_assert_int_eq(get_int_valid(&dst, "120,100,0\n"), TRUE);
	mu_assert_string_eq(dst, "120");
	free(dst);

	mu_assert_int_eq(get_int_valid(&dst, "0,100,0\n"), TRUE);
	mu_assert_string_eq(dst, "0");
	free(dst);
}

MU_TEST_SUITE(suite_get_get_int_valid)
{
	MU_SUITE_CONFIGURE(&test_setup, &test_teardown);

	MU_RUN_TEST(get_get_int_valid_tst);
}

MU_MAIN
{
	MU_DIVIDER;
	MU_RUN_SUITE(suite_get_get_int_valid);
	MU_REPORT();
	return (MU_EXIT_CODE);
}

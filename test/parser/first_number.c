/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_firts_number.c                                   :+:      :+:    :+:   */
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
	set_flag(FALSE);
}
void	test_teardown(void)
{
}

MU_TEST(get_firts_number_tst)
{
	char	*tmp;


	mu_assert_string_eq(firts_number(NULL), NULL);
	mu_assert_string_eq(firts_number(""), NULL);

	tmp = firts_number("220,100,0\n");
	mu_assert_string_eq(tmp, "220");
	free(tmp);

	tmp = firts_number("120,100,0\n");
	mu_assert_string_eq(tmp, "120");
	free(tmp);

	tmp = firts_number("0,100,0\n");
	mu_assert_string_eq(tmp, "0");
	free(tmp);
}

MU_TEST_SUITE(suite_get_firts_number)
{
	MU_SUITE_CONFIGURE(&test_setup, &test_teardown);

	MU_RUN_TEST(get_firts_number_tst);
}

MU_MAIN
{
	MU_DIVIDER;
	MU_RUN_SUITE(suite_get_firts_number);
	MU_REPORT();
	return (MU_EXIT_CODE);
}

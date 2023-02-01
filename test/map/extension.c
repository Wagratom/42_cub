/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extension.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwalas- <wwallas-@student.42sp.org.br>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 16:59:18 by lpaulo-m          #+#    #+#             */
/*   Updated: 2023/02/01 16:35:25 by wwalas-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minunit.h"

int	foo;

void	test_setup(void)
{
	set_flag(TRUE);
}
void	test_teardown(void)
{
}

MU_TEST(invalid_tst)
{
	mu_assert_int_eq(verify_extension("teste.c"), FALSE);
	mu_assert_int_eq(verify_extension("teste.cu"), FALSE);
	mu_assert_int_eq(verify_extension("teste.cub.c"), FALSE);
	mu_assert_int_eq(verify_extension("teste.cub.cu"), FALSE);
	mu_assert_int_eq(verify_extension("teste.cub.cubb"), FALSE);
}

MU_TEST(valid_tst)
{
	mu_assert_int_eq(verify_extension("teste.cub"), TRUE);
	mu_assert_int_eq(verify_extension("teste.cu.cub"), TRUE);
	mu_assert_int_eq(verify_extension("teste.cub.cub"), TRUE);
}

MU_TEST_SUITE(extension)
{
	MU_SUITE_CONFIGURE(&test_setup, &test_teardown);

	MU_RUN_TEST(invalid_tst);
	MU_RUN_TEST(valid_tst);
}

MU_MAIN
{
	MU_DIVIDER;
	MU_RUN_SUITE(extension);
	MU_REPORT();
	return (MU_EXIT_CODE);
}

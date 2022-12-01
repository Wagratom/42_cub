/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extension.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwallas- <wwallas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 16:59:18 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/11/30 16:13:03 by wwallas-         ###   ########.fr       */
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

MU_TEST(invalid_tst)
{
	mu_assert_int_eq(verify_extension("teste.c"), 0);
	mu_assert_int_eq(verify_extension("teste.cu"), 0);
	mu_assert_int_eq(verify_extension("teste.cub.c"), 0);
	mu_assert_int_eq(verify_extension("teste.cub.cu"), 0);
	mu_assert_int_eq(verify_extension("teste.cub.cubb"), 0);
}

MU_TEST(valid_tst)
{
	mu_assert_int_eq(verify_extension("teste.cub"), 0);
	mu_assert_int_eq(verify_extension("teste.cu.cub"), 0);
	mu_assert_int_eq(verify_extension("teste.cub.cub"), 0);
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

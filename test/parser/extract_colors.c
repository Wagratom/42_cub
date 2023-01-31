/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_colors.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwalas- <wwallas-@student.42sp.org.br>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 10:23:22 by wwalas-           #+#    #+#             */
/*   Updated: 2023/01/31 10:37:44 by wwalas-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minunit.h"

void	test_setup(void)
{
}
void	test_teardown(void)
{
}

MU_TEST(collors_tst1)
{
	t_parser parse;

	ft_bzero(&parse, sizeof(t_parser));
	extract_colors(parse.f, "250,140,0\n");
	mu_assert_int_eq(parse.f[0], 250);
	mu_assert_int_eq(parse.f[1], 140);
	mu_assert_int_eq(parse.f[2], 0);
}

MU_TEST(collors_tst2)
{
	t_parser parse;

	ft_bzero(&parse, sizeof(t_parser));
	extract_colors(parse.f, "0,0,0\n");
	mu_assert_int_eq(parse.f[0], 0);
	mu_assert_int_eq(parse.f[1], 0);
	mu_assert_int_eq(parse.f[2], 0);
}

MU_TEST(collors_many_numbers)
{
	t_parser parse;

	ft_bzero(&parse, sizeof(t_parser));
	mu_assert_int_eq(extract_colors(parse.f,  "250,140,120,100\n"), FALSE);
	mu_assert_int_eq(extract_colors(parse.f,  "250,140,120,100\n"), FALSE);
}

MU_TEST(collors_few_numbers)
{
	t_parser parse;

	ft_bzero(&parse, sizeof(t_parser));
	mu_assert_int_eq(extract_colors(parse.f,  "250,140\n"), FALSE);
	mu_assert_int_eq(extract_colors(parse.f,  "250,140\n"), FALSE);
}

MU_TEST_SUITE(suite_collor_f)
{
	MU_SUITE_CONFIGURE(&test_setup, &test_teardown);

	MU_RUN_TEST(collors_tst1);
	MU_RUN_TEST(collors_tst2);
	MU_RUN_TEST(collors_many_numbers);
	MU_RUN_TEST(collors_few_numbers);

}

MU_MAIN
{
	MU_DIVIDER;
	MU_RUN_SUITE(suite_collor_f);
	MU_REPORT();
	return (MU_EXIT_CODE);
}

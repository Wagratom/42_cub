/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_first_word.c                                   :+:      :+:    :+:   */
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

MU_TEST(get_first_word_tst)
{
		mu_assert_string_eq(first_word("NO ./path_to_the_north_texture\n"), "NO");
		mu_assert_string_eq(first_word("N ./path_to_the_north_texture\n"), "N");
		mu_assert_string_eq(first_word("NOO ./path_to_the_north_texture\n"), "NOO");

		mu_assert_string_eq(first_word("SO ./path_to_the_north_texture\n"), "SO");
		mu_assert_string_eq(first_word("S ./path_to_the_north_texture\n"), "S");
		mu_assert_string_eq(first_word("SOO ./path_to_the_north_texture\n"), "SOO");

		mu_assert_string_eq(first_word("WE ./path_to_the_north_texture\n"), "WE");
		mu_assert_string_eq(first_word("WEE ./path_to_the_north_texture\n"), "WEE");
		mu_assert_string_eq(first_word("W ./path_to_the_north_texture\n"), "W");

}

MU_TEST_SUITE(suite_get_first_word)
{
	MU_SUITE_CONFIGURE(&test_setup, &test_teardown);

	MU_RUN_TEST(get_first_word_tst);
}

MU_MAIN
{
	MU_DIVIDER;
	MU_RUN_SUITE(suite_get_first_word);
	MU_REPORT();
	return (MU_EXIT_CODE);
}

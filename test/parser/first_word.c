/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_word.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwalas- <wwallas-@student.42sp.org.br>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 15:39:34 by wwalas-           #+#    #+#             */
/*   Updated: 2023/02/01 23:39:47 by wwalas-          ###   ########.fr       */
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

MU_TEST(invalid_tst)
{
	mu_assert_string_eq(first_word(NULL), NULL);
	mu_assert_string_eq(first_word(""), NULL);
}

MU_TEST(valid_tst)
{
	char	*data;

	data = first_word("NO ./path_to_the_north_texture\n");
	mu_assert_string_eq(data, "NO");
	ft_free_ptr(&data, NULL);

	data = first_word("N ./path_to_the_north_texture\n");
	mu_assert_string_eq(data, "N");
	ft_free_ptr(&data, NULL);

	data = first_word("NOO ./path_to_the_north_texture\n");
	mu_assert_string_eq(data, "NOO");
	ft_free_ptr(&data, NULL);

	data = first_word("SO ./path_to_the_north_texture\n");
	mu_assert_string_eq(data, "SO");
	ft_free_ptr(&data, NULL);

	data = first_word("S ./path_to_the_north_texture\n");
	mu_assert_string_eq(data, "S");
	ft_free_ptr(&data, NULL);

	data = first_word("SOO ./path_to_the_north_texture\n");
	mu_assert_string_eq(data, "SOO");
	ft_free_ptr(&data, NULL);

	data = first_word("WE ./path_to_the_north_texture\n");
	mu_assert_string_eq(data, "WE");
	ft_free_ptr(&data, NULL);

	data = first_word("WEE ./path_to_the_north_texture\n");
	mu_assert_string_eq(data, "WEE");
	ft_free_ptr(&data, NULL);

	data = first_word("W ./path_to_the_north_texture\n");
	mu_assert_string_eq(data, "W");
	ft_free_ptr(&data, NULL);
}

MU_TEST_SUITE(suite_get_first_word)
{
	MU_SUITE_CONFIGURE(&test_setup, &test_teardown);

	MU_RUN_TEST(invalid_tst);
	MU_RUN_TEST(valid_tst);
}

MU_MAIN
{
	MU_DIVIDER;
	MU_RUN_SUITE(suite_get_first_word);
	MU_REPORT();
	return (MU_EXIT_CODE);
}

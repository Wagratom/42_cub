/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path_coordinate.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwalas- <wwallas-@student.42sp.org.br>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 17:04:05 by wwalas-           #+#    #+#             */
/*   Updated: 2023/01/31 15:40:59 by wwalas-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minunit.h"

void	test_setup(void)
{
}
void	test_teardown(void)
{
}

MU_TEST(north)
{
	char *result;

	mu_assert_string_eq(data_in_line(NULL), NULL);
	mu_assert_string_eq(data_in_line(""), NULL);

	result = "./path_to_the_north_texture\n";
	mu_assert_string_eq(data_in_line("NO ./path_to_the_north_texture\n"), result);

	result = "./e dois real a palma da banana\n";
	mu_assert_string_eq(data_in_line("NO ./e dois real a palma da banana\n"), result);
}

MU_TEST_SUITE(suite_coordinate)
{
	MU_SUITE_CONFIGURE(&test_setup, &test_teardown);

	MU_RUN_TEST(north);

}

MU_MAIN
{
	MU_DIVIDER;
	MU_RUN_SUITE(suite_coordinate);
	MU_REPORT();
	return (MU_EXIT_CODE);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_in_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwalas- <wwallas-@student.42sp.org.br>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 17:04:05 by wwalas-           #+#    #+#             */
/*   Updated: 2023/02/01 23:22:14 by wwalas-          ###   ########.fr       */
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

MU_TEST(invalid_data_tst)
{
	mu_assert_string_eq(data_in_line(NULL), NULL);
	mu_assert_string_eq(data_in_line(""), NULL);
}

MU_TEST(valid_data_tst)
{
	char	*data;

	data = data_in_line("NO ./path_to_the_north_texture\n");
	mu_assert_string_eq(data, "./path_to_the_north_texture");
	free(data);

	data = data_in_line("NO ./e dois real a palma da banana\n");
	mu_assert_string_eq(data, "./e dois real a palma da banana");
	free(data);
}

MU_TEST_SUITE(suite_coordinate)
{
	MU_SUITE_CONFIGURE(&test_setup, &test_teardown);

	MU_RUN_TEST(invalid_data_tst);
	MU_RUN_TEST(valid_data_tst);

}

MU_MAIN
{
	MU_DIVIDER;
	MU_RUN_SUITE(suite_coordinate);
	MU_REPORT();
	return (MU_EXIT_CODE);
}

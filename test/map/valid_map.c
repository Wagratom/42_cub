/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwallas- <wwallas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 16:59:18 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/12/03 22:50:22 by wwallas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minunit.h"

t_data	data;

void	test_setup(void)
{
}

void	test_teardown(void)
{
}

MU_TEST(valid_map_tst)
{
	ft_bzero(&data, sizeof(t_data));
	data.map.file_name = "./map/map.cub";

	mu_assert_int_eq(valid_map(&data.map), 1);
}

MU_TEST(invalid_extension_tst)
{
	ft_bzero(&data, sizeof(t_data));
	data.map.file_name = "./map/invalid_extension.cubb";

	mu_assert_int_eq(valid_map(&data.map), 0);
}


MU_TEST(invalid_chars)
{

}

MU_TEST_SUITE(valid_map_suite)
{
	MU_SUITE_CONFIGURE(&test_setup, &test_teardown);

	MU_RUN_TEST(valid_map_tst);
	//MU_RUN_TEST(invalid_extension_tst);
}

MU_MAIN
{
	MU_DIVIDER;
	MU_RUN_SUITE(valid_map_suite);
	MU_REPORT();
	return (MU_EXIT_CODE);
}

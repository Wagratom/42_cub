/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   imgs.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwallas- <wwallas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 09:15:40 by wwallas-          #+#    #+#             */
/*   Updated: 2022/11/17 07:38:17 by wwallas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../minunit.h"

t_data data;

void	test_setup(void)
{
}

void	test_teardown(void)
{
}

MU_TEST(init_imgs_tst)
{
	int index;

	mu_assert_int_eq(init_img(&data), FALSE);

	init_data(&data);
	mu_check(data.img.img != NULL);
	mu_check(data.img.addr != NULL);
	clear_program(&data);
}


MU_TEST_SUITE(test_suite)
{
	MU_SUITE_CONFIGURE(&test_setup, &test_teardown);

	MU_RUN_TEST(init_imgs_tst);
}

MU_MAIN
{
	MU_DIVIDER;
	MU_RUN_SUITE(test_suite);
	MU_REPORT();
	argc = argc;
	argv = argv;
	envp = envp;
	return (MU_EXIT_CODE);
}

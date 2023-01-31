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

MU_TEST(collors)
{
}

MU_TEST_SUITE(suite_collor_f)
{
	MU_SUITE_CONFIGURE(&test_setup, &test_teardown);

	MU_RUN_TEST(collors);

}

MU_MAIN
{
	MU_DIVIDER;
	MU_RUN_SUITE(suite_collor_f);
	MU_REPORT();
	return (MU_EXIT_CODE);
}

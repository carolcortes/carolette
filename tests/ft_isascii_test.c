/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cade-oli <cade-oli@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 15:49:14 by cade-oli          #+#    #+#             */
/*   Updated: 2024/11/09 15:37:56 by cade-oli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ansi_colors.h"
#include "libft_tests.h"

int	ft_isascii_test(void)
{
	int			i;
	int			c;
	int			ko;
	int			original;
	int			num_tests;
	const int	chars[] = {'A', 'z', 'b', 'G', '!', '0', '9', -1, 128, '\t'};

	printf("%sft_isascii\t     [", GREEN);
	i = -1;
	ko = 0;
	num_tests = sizeof(chars) / sizeof(chars[0]);
	while (++i < num_tests)
	{
		c = chars[i];
		original = isascii(c);
		if (!original == !ft_isascii(c))
			printf("✔");
		else
		{
			printf("%s✖%s", RED, GREEN);
			ko = 1;
		}
		fflush(stdout);
		usleep(100000);
	}
	if (ko)
		printf("]\t%sKO%s\n", RED, RESET);
	else
		printf("]\tOK%s\n", RESET);
	return (0);
}

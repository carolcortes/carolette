/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cade-oli <cade-oli@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 12:07:05 by cade-oli          #+#    #+#             */
/*   Updated: 2024/11/09 15:37:01 by cade-oli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ansi_colors.h"
#include "libft_tests.h"

int	ft_isalpha_test(void)
{
	int			i;
	int			c;
	int			ko;
	int			num_tests;
	int			original;
	const int	chars[] = {'A', 'z', 'b', 'G', '!', '0', '9', -1, 128, '\t'};

	printf("%sft_isalpha\t     [", GREEN);
	i = -1;
	ko = 0;
	num_tests = sizeof(chars) / sizeof(chars[0]);
	while (++i < num_tests)
	{
		c = chars[i];
		original = isalpha(c);
		if (!original == !ft_isalpha(c))
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

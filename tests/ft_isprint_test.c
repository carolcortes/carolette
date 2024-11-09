/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cade-oli <cade-oli@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 16:19:10 by cade-oli          #+#    #+#             */
/*   Updated: 2024/11/09 15:39:49 by cade-oli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ansi_colors.h"
#include "libft_tests.h"

int	ft_isprint_test(void)
{
	int			i;
	int			c;
	int			ko;
	int			orig;
	int			num_tests;
	const int	chars[] = {'A', ' ', 'b', 'G', '!', 32, 31, 0, 127};

	printf("%sft_isprint\t     [", GREEN);
	i = -1;
	ko = 0;
	num_tests = sizeof(chars) / sizeof(chars[0]);
	while (++i < num_tests)
	{
		c = chars[i];
		orig = isprint(c);
		if (orig != 0)
			orig = 1;
		if (orig == ft_isprint(c))
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

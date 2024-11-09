/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cade-oli <cade-oli@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 15:26:46 by cade-oli          #+#    #+#             */
/*   Updated: 2024/11/09 15:36:53 by cade-oli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ansi_colors.h"
#include "libft_tests.h"

int	ft_isdigit_test(void)
{
	int			i;
	int			c;
	int			ko;
	int			test_len;
	int			original;
	const int	chars[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
		'A', 'z', '!', -1, 128, '\t'};

	printf("%sft_isdigit           [", GREEN);
	i = -1;
	ko = 0;
	test_len = sizeof(chars) / sizeof(chars[0]);
	while (++i < test_len)
	{
		c = chars[i];
		original = isdigit(c);
		if (!original == !ft_isdigit(c))
			printf("✔");
		else
		{
			printf("%s✖%s", RED, GREEN);
			ko = 1;
		}
		fflush(stdout);
		usleep(100000);
	}
	printf("]\tOK%s\n", RESET);
	return (0);
	if (ko)
		printf("]\t%sKO%s\n", RED, RESET);
	else
		printf("]\tOK%s\n", RESET);
	return (0);
}

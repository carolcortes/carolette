/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cade-oli <cade-oli@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 16:30:49 by cade-oli          #+#    #+#             */
/*   Updated: 2024/11/09 15:39:55 by cade-oli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
#include "../include/ansi_colors.h"
#include "libft_tests.h"

int	ft_strlen_test(void)
{
	int			i;
	int			ko;
	int			num_tests;
	int			original;
	const char	*strings[] = {
		"Hello, World!",
		"",
		"42",
		"This is a longer string for testing purposes.",
		"\t\n\v\f\r",
		"1234567890",
		" ",
		"\0Hidden"
	};

	printf("%sft_strlen\t     [", GREEN);
	i = -1;
	ko = 0;
	num_tests = sizeof(strings) / sizeof(strings[0]);
	while (++i < num_tests)
	{
		original = strlen(strings[i]);
		if (original == ft_strlen(strings[i]))
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
		printf("]\t\t%sKO%s\n", RED, RESET);
	else
		printf("]\t\tOK%s\n", RESET);
	return (0);
}

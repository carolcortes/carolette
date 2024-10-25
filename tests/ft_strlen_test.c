/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cade-oli <cade-oli@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 16:30:49 by cade-oli          #+#    #+#             */
/*   Updated: 2024/10/23 17:02:46 by cade-oli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include "ansi_colors.h"
#include <string.h>
#include <stdio.h>

int	ft_strlen_test()
{
	const char *strings[] = {
		"Hello, World!",
		"",
		"42",
		"This is a longer string for testing purposes.",
		"\t\n\v\f\r",
		"1234567890",
		" ",
		"\0Hidden"
	};
	int	num_tests;
	int	i;
	int	original;

	printf("\n*************************************");
	printf("\n*     Running ft_strlen() Tests    *\n");
	printf("*************************************\n");

	num_tests = sizeof(strings) / sizeof(strings[0]);
	i = -1;
	while (++i < num_tests)
	{
		original = strlen(strings[i]);
		if (original == ft_strlen(strings[i]))
			printf("%s[✔] Test passed for string \"%s\" (Got: %d)%s\n",
                GREEN, strings[i], ft_strlen(strings[i]), RESET);
		else
			printf("%s[✖] Test failed for string \"%s\" (Expected: %d, Got: %d)%s\n",
                RED, strings[i], original, ft_strlen(strings[i]), RESET);
	}
	return (0);
}

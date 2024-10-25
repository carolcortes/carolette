/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cade-oli <cade-oli@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 16:19:10 by cade-oli          #+#    #+#             */
/*   Updated: 2024/10/23 16:22:19 by cade-oli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include "ansi_colors.h"
#include <ctype.h>
#include <stdio.h>

int ft_isprint_test()
{
	int	chars[] = {'A', ' ', 'b', 'G', '!', 32, 31, 0, 127};
	int	num_tests;
	int	i;
	int	c;
	int	original;

	printf("\n*************************************");
	printf("\n*     Running ft_isprint() Tests    *\n");
	printf("*************************************\n");
	num_tests = sizeof(chars) / sizeof(chars[0]);
	i = -1;
	while (++i < num_tests)
	{
		c = chars[i];
		original = isprint(c);
		if (original > 0)
			original = 1;
		if (original == ft_isprint(c))
			printf("%s[✔] Test passed for input '%c' (ASCII: %d)%s\n",
				GREEN, c, c, RESET);
		else
			printf("%s[✖] Test failed for input '%c' (ASCII: %d). Expected: %d, Got: %d%s\n",
				RED, c, c, original, ft_isprint(c), RESET);
	}
	printf("\n");
	return (0);
}

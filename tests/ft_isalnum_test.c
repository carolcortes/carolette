/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cade-oli <cade-oli@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 15:42:47 by cade-oli          #+#    #+#             */
/*   Updated: 2024/10/23 15:43:37 by cade-oli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
#include "../include/ansi_colors.h"
#include <ctype.h>
#include <stdio.h>

int	ft_isalnum_test(void)
{
	int	chars[] = {'A', 'z', 'b', 'G', '!', '0', '9', -1, 128};
	int	num_tests;
	int	i;
	int	c;
	int	original;

	printf("\n*************************************");
	printf("\n*     Running ft_isalnum() Tests    *\n");
	printf("*************************************\n");
	num_tests = sizeof(chars) / sizeof(chars[0]);
	i = -1;
	while (++i < num_tests)
	{
		c = chars[i];
		original = isalnum(c);
		if (original > 0)
			original = 1;
		if (original == ft_isalnum(c))
			printf("%s[✔] Test passed for input '%c' (ASCII: %d)%s\n",
				GREEN, c, c, RESET);
		else
			printf("%s[✖] Test failed for input '%c' (ASCII: %d). Expected: %d, Got: %d%s\n",
				RED, c, c, original, ft_isalnum(c), RESET);
	}
	printf("\n");
	return (0);
}

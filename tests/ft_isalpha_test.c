/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abessa-m <abessa-m@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 12:07:05 by cade-oli          #+#    #+#             */
/*   Updated: 2024/10/26 17:20:56 by abessa-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
#include "../include/ansi_colors.h"
#include <ctype.h>
#include <stdio.h>

int	ft_isalpha_test(void)
{
	int	chars[] = {'A', 'z', 'b', 'G', '!', '0', '9', -1, 128, '\t'};
	int	num_tests;
	int	i;
	int	c;
	int	original;

	printf("\n*************************************");
	printf("\n*     Running ft_isalpha() Tests    *\n");
	printf("*************************************\n");
	num_tests = sizeof(chars) / sizeof(chars[0]);
	i = -1;
	while (++i < num_tests)
	{
		c = chars[i];
		original = isalpha(c);
		if (!original == !ft_isalpha(c))
			printf("%s[✔] Test passed for input '%c' (ASCII: %d)%s\n",
				GREEN, c, c, RESET);
		else
			printf("%s[✖] Test failed for input '%c' (ASCII: %d). Expected: %d, Got: %d%s\n",
				RED, c, c, original, ft_isalpha(c), RESET);
	}
	printf("\n");
	return (0);
}

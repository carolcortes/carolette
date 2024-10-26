/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cade-oli <cade-oli@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 15:26:46 by cade-oli          #+#    #+#             */
/*   Updated: 2024/10/23 15:39:44 by cade-oli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
#include "../include/ansi_colors.h"
#include <ctype.h>
#include <stdio.h>

int	ft_isdigit_test(void)
{
	int chars[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
					'A', 'z', '!', -1, 128, '\t'};
	int	i;
	int	test_len;
	int	c;
	int	original;

	printf("\n*************************************");
	printf("\n*      Running ft_digit() Tests     *\n");
	printf("*************************************\n");
	i = -1;
	test_len = sizeof(chars) / sizeof(chars[0]);
	while (++i < test_len)
	{
		c = chars[i];
		original = isdigit(c);
		if (!original == !ft_isdigit(c))
			printf("%s[✔] Test passed for input '%c' (ASCII: %d)%s\n",
				GREEN, c, c, RESET);
		else
			printf("%s[✖] Test failed for input '%c' (ASCII: %d). Expected: %d, Got: %d%s\n",
				RED, c, c, original, ft_isdigit(c), RESET);
	}
	printf("\n");
	return (0);
}

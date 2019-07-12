/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzhao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 13:07:43 by vzhao             #+#    #+#             */
/*   Updated: 2019/07/11 18:08:04 by vzhao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "srcs/ft_printf.h"

int		main(void)
{

	// %c test: Use....
	// Valid: %c, %-c, %-5c, %5c, %lc, %-lc, %-5lc, %5lc
	// InValid: everything else should fail......
	
//	char *test = "Hello";
	long int test[] = {5, 3};
	printf("...char printed: %d\n", printf("%20p", &test));
//	printf("ft_strlen = %lu\n", ft_strlen(test));
	printf("...char printed: %d\n", ft_printf("%20p", &test));
//	system("leaks test_ftprintf");
	return (0);
}

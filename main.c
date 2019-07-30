/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzhao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 13:07:43 by vzhao             #+#    #+#             */
/*   Updated: 2019/07/29 18:17:17 by vzhao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "srcs/ft_printf.h"
#include <stdio.h>
#include <limits.h>
#include <math.h>

int		main(void)
{

/*	char C = 'C';
	// %c test: Use....
	// Valid: %c, %-c, %-5c, %5c, %lc, %-lc, %-5lc, %5lc
	// InValid: everything else should fail......

	printf("......printf printed: %d\n", printf("%c", C));
	printf("...ft_printf printed: %d\n", ft_printf("%c", C));
	printf("......printf printed: %d\n", printf("%-c", C));
	printf("...ft_printf printed: %d\n", ft_printf("%-c", C));
	printf("......printf printed: %d\n", printf("%5c", C));
	printf("...ft_printf printed: %d\n", ft_printf("%5c", C));
	printf("......printf printed: %d\n", printf("%-5c", C));
	printf("...ft_printf printed: %d\n", ft_printf("%-5c", C));
	printf("......printf printed: %d\n", printf("%lc", C));
	printf("...ft_printf printed: %d\n", ft_printf("%lc", C));
	printf("......printf printed: %d\n", printf("%5lc", C));
	printf("...ft_printf printed: %d\n", ft_printf("%5lc", C));
	printf("......printf printed: %d\n", printf("%-5lc", C));
	printf("...ft_printf printed: %d\n", ft_printf("%-5lc", C));
*/
/* 
 * Color codes......
 * Escape sequence to initiate color code = \033
	[0;31m  Red
	[1;31m	Bold Red
	[0;32m	Green
	[1;32m	Bold Green
	[0;33m	Yellow
	[01;33m	Bold Yellow
	[0;34m	Blue
	[1;34m	Bold Blue
	[0;35m	Magenta
	[1;35m	Bold Magenta
	[0;36m	Cyan
	[1;36m	Bold Cyan
	[0m		Reset
*/
//	char *test = NULL;
	printf("---char printed: %d\n", printf("\033[1;32m%s\033[0m", "Hello"));
	printf("---char printed: %d\n", ft_printf("\033[1;32m%s\033[0m", "Hello"));
//	ft_putstr("\033[0;31m Is this red \033[0m\n");
//	system("leaks test_ftprintf");

	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   practice.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzhao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/05 16:36:36 by vzhao             #+#    #+#             */
/*   Updated: 2019/07/06 19:14:12 by vzhao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

int			ft_sum(int nHowMany, ...)
{
	int		nSum = 0;

	va_list	pointer;
	va_start(pointer, nHowMany);
	for (int i = 0; i < nHowMany; i++)
		nSum += va_arg(pointer, int);
	va_end(pointer);

	return (nSum);
}

int			main(void)
{
	int a = 10;
	int b = 20;
	int c = 30;
	int d = 40;

	printf("a = %d\nb = %d\nc = %d\nd = %d\n", a, b, c, d);
	printf("a + b = %d\n", ft_sum(2, a, b));
	printf("a + b + c = %d\n", ft_sum(3, a, b, c));
	printf("a + b + c + d = %d\n", ft_sum(4, d, c, b, a));
	return (1);
}

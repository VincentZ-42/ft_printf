/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzhao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 17:32:20 by vzhao             #+#    #+#             */
/*   Updated: 2019/07/28 03:30:09 by vzhao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			get_next_call(va_list ap, char *str, int count)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '%' && !str[i + 1])
			return (0);
		if (str[i] == '%')
		{
			count += get_info(ap, str + (++i));
			while (str[i] && !is_type(str[i]))
				i++;
		}
		else
		{
			ft_putchar(str[i]);
			count++;
		}
		if (!str[i])
			break ;
		i++;
	}
	va_end(ap);
	return (count);
}

int			ft_printf(const char *format, ...)
{
	va_list	ap;
	int		char_count;

	char_count = 0;
	va_start(ap, format);
	return (get_next_call(ap, (char*)format, char_count));
}

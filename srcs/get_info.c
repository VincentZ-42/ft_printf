/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzhao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/06 17:43:54 by vzhao             #+#    #+#             */
/*   Updated: 2019/07/29 13:45:28 by vzhao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "dispatch.h"

/*
** This keeps scaning and stores all flags into a binary #
** Each flag has it's own bit representation in 00000000
*/

char		*get_flag(char *str, t_var *info)
{
	info->flag = 0;
	if (is_flag(*str))
	{
		while (is_flag(*str))
		{
			if (*str == '0')
				info->flag |= zero;
			if (*str == '#')
				info->flag |= hash;
			if (*str == '-')
				info->flag |= minus;
			if (*str == '+')
				info->flag |= plus;
			if (*str == ' ')
				info->flag |= space;
			str++;
		}
	}
	return (str);
}

char		*get_width(char *str, t_var *info, va_list ap)
{
	int		len;

	len = 0;
	info->width = 0;
	if (ft_isdigit(*str))
	{
		info->width = ft_atoi(str);
		len = ft_int_len(ft_atoi(str));
	}
	else if (*str == '*')
	{
		info->width = va_arg(ap, int);
		if (info->width < 0)
		{
			info->flag += (info->width < 0) ? minus : 0;
			info->width *= -1;
		}
		str++;
	}
	return (str + len);
}

char		*get_precision(char *str, t_var *info, va_list ap)
{
	info->precision = -1;
	if (*str == '.')
	{
		while (*str == '.')
			str++;
		if (*str == '*')
		{
			info->precision = va_arg(ap, int);
			str++;
			return (str);
		}
		info->precision = ft_atoi(str);
		while (ft_isdigit(*str))
			str++;
	}
	return (str);
}

char		*get_length(char *str, t_var *info)
{
	info->length = 0;
	if (is_length(*str))
	{
		if (*str == 'h')
			info->length = (str[1] == 'h') ? hh : h;
		if (*str == 'l')
			info->length = (str[1] == 'l') ? ll : l;
		if (*str == 'j')
			info->length = j;
		if (*str == 'z')
			info->length = z;
		if (*str == 'L')
			info->length = L;
		while (is_length(*str))
			str++;
	}
	return (str);
}

int			get_info(va_list ap, char *str)
{
	t_var	info;
	int		i;
	int		char_count;

	i = -1;
	char_count = 0;
	str = get_flag(str, &info);
	str = get_width(str, &info, ap);
	str = get_precision(str, &info, ap);
	str = get_length(str, &info);
	get_conv(str, &info);
	ft_handle_flags(&info);
	if (*str && !is_type(info.conv))
	{
		ft_putchar(*str);
		return (1);
	}
	else if (!is_type(info.conv) || !*str)
		return (0);
	while (++i < TYPE_NUM)
		if (g_dispatch_table[i].type == *str)
			char_count = g_dispatch_table[i].spec_funct(&info, ap);
	return (char_count);
}

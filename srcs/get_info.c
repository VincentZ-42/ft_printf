/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzhao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/06 17:43:54 by vzhao             #+#    #+#             */
/*   Updated: 2019/07/26 10:30:05 by vzhao            ###   ########.fr       */
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

char		*get_width(char *str, t_var *info)
{
	int		len;

	len = 0;
	info->width = 0;
	if (ft_isdigit(*str))
	{
		info->width = ft_atoi(str);
		len = ft_int_len(ft_atoi(str));
	}
	return (str + len);
}

char		*get_precision(char *str, t_var *info)
{
	int len;

	len = 0;
	info->precision = -1;
	if (*str == '.')
	{
		str++;
		info->precision = ft_atoi(str);
		len = (ft_isdigit(*str)) ? ft_int_len(ft_atoi(str)) : 0;
	}
	return (str + len);
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
	str = get_width(str, &info);
	str = get_precision(str, &info);
	str = get_length(str, &info);
	get_conv(str, &info);
	ft_handle_flags(&info);
	if (!is_type(info.conv) || !*str)
		return (0);
	while (++i < TYPE_NUM)
		if (dispatch_table[i].type == *str)
			char_count = dispatch_table[i].spec_funct(&info, ap);
	return (char_count);
}

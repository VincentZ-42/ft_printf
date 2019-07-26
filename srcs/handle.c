/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzhao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 16:03:00 by vzhao             #+#    #+#             */
/*   Updated: 2019/07/26 11:29:04 by vzhao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_handle_flags(t_var *info)
{
	if (info->flag & zero && info->flag & minus)
		info->flag -= zero;
	if (info->flag & space && info->flag & plus)
		info->flag -= space;
	if (info->flag & zero && info->precision >= 0)
	{
		if (info->conv == 'f')
			return ;
		else
			info->flag -= zero;
	}
}

void		get_conv(char *str, t_var *info)
{
	if (is_type(*str))
		info->conv = *str;
}

int			llui_len_base(LLUI n, int base)
{
	int len;

	len = (n == 0) ? 1 : 0;
	while (n > 0)
	{
		len++;
		n /= base;
	}
	return (len);
}

char		llui_check_base(LLUI n, int base, char choice)
{
	char	c;
	LLUI	temp;
	__UC	start;

	start = (choice == 'U') ? 'A' : 'a';
	temp = n % base;
	c = (temp < 10) ? temp + '0' : temp + start - 10;
	return (c);
}

char		*llui_itoa_base(LLUI n, int base, char choice)
{
	char	*ans;
	int		len;

	len = llui_len_base(n, base);
	if (!(ans = (char*)malloc(sizeof(char) * len + 1)))
		return (NULL);
	ans[len--] = '\0';
	if (n == 0)
		ans[0] = '0';
	while (n > 0)
	{
		ans[len--] = llui_check_base(n, base, choice);
		n /= base;
	}
	return (ans);
}

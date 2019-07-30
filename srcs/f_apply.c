/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_apply.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzhao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 16:32:10 by vzhao             #+#    #+#             */
/*   Updated: 2019/07/29 13:18:40 by vzhao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** ---------------------------------------------------------------------------
** ld_int_len does not account for the (-) sign
** apply_flags function will add the sign if needed
** ---------------------------------------------------------------------------
*/

int			ld_int_len(long double input)
{
	int		len;
	__LD	n;

	len = 0;
	n = (input < 0) ? input * -1 : input;
	while (n >= 1)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char		*ld_itoa(long double nbr)
{
	char	*ans;
	int		len;
	__LD	input;

	input = (nbr < 0) ? -nbr : nbr;
	len = (input < 1 && input >= 0) ? 1 : ld_int_len(input);
	if (!(ans = (char*)malloc(sizeof(char) * len + 1)))
		return (NULL);
	ans[len--] = '\0';
	if (input < 1 && input >= 0)
	{
		ans[0] = '0';
		return (ans);
	}
	input *= (input < 0) ? -1 : 1;
	while (input >= 1)
	{
		ans[len--] = ((long long unsigned int)input % 10) + '0';
		input /= 10;
	}
	return (ans);
}

char		*ld_decimals(long double input, int prec)
{
	int		i;
	__LD	n;
	char	*ans;

	n = 0;
	i = 0;
	if (prec == 0)
		return (NULL);
	if (!(ans = (char*)malloc(sizeof(char) * prec + 1)))
		return (NULL);
	input *= (input < 0) ? -1 : 1;
	if (input > 0)
		input -= (LLUI)input;
	while (prec--)
	{
		input *= 10;
		ans[i++] = ((LLUI)(input) % 10) + '0';
	}
	if (input == 0)
		ans[0] = '0';
	ans[i] = '\0';
	return (ans);
}

__LD		round_up(long double input, t_var *info)
{
	__LD	temp;
	__LD	add;
	int		prec;

	add = 1;
	input += (input < 0) ? -5e-11 : 5e-11;
	temp = (input < 0) ? -input : input;
	if (info->precision == -1)
		info->precision = 6;
	prec = info->precision;
	while (prec--)
	{
		temp *= 10;
		temp -= (LLUI)(temp);
	}
	prec = info->precision;
	if (prec == 0)
		temp -= (LLUI)temp;
	if (temp * 10 >= 5.0)
	{
		while (prec--)
			add /= 10;
		input += (input > 0) ? add : -add;
	}
	return (input);
}

char		*get_f_number(long double input, t_var *info)
{
	char	*temp1;
	char	*temp2;
	char	*print;

	temp1 = ld_itoa(input);
	temp2 = ld_decimals(input, info->precision);
	if (temp2 == NULL && info->flag & hash)
	{
		print = ft_strjoin(temp1, ".");
		ft_strdel(&temp1);
		temp1 = ft_strdup(print);
		ft_strdel(&print);
	}
	else if (temp2)
	{
		print = ft_strjoin(temp1, ".");
		ft_strdel(&temp1);
		temp1 = ft_strjoin(print, temp2);
		ft_strdel(&print);
	}
	print = temp1;
	return (print);
}

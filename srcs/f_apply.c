/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_apply.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzhao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 16:32:10 by vzhao             #+#    #+#             */
/*   Updated: 2019/07/20 15:17:53 by vzhao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// Does not account for negative numbers because that will be added later...
int		ld_int_len(long double input)
{
	int len;
	long double n;

	len = 0;
	n = (input < 0) ? input * -1 : input;
	while (n >= 1)
	{
		n /= 10;
		len++;
	}
	return (len);
}

// This function to make the string of whole numbers, not complete yet
char	*ld_itoa(long double input)
{
	char *ans;
	int len;

	len = (input == 0) ? 1 : ld_int_len(input);
	if (!(ans = (char*)malloc(sizeof(char) * len + 1)))
		return (NULL);
	ans[len--] = '\0';
	if (input == 0)	
		ans[0] = '0';
	input *= (input < 0) ? -1 : 1;
	while (input >= 1)
	{
		ans[len--] = ((long long unsigned int)input % 10) + '0';
		input /= 10;
	}
	return (ans);	
}

char	*ld_decimals(long double input, int prec)
{
	int i;
	long double n;
	char *ans;

	n = 0;
	i = 0;
	if (prec == 0)
		return (NULL);
	if (prec == -1)
		prec = 6; 
	if (!(ans = (char*)malloc(sizeof(char) * prec + 1)))
		return (NULL);
	input *= (input < 0) ? -1 : 1;
	while (input >= 1)
		input -= 1;
	while (prec--)
	{
		input *= 10;
		ans[i++] = ((long long unsigned int)input % 10) + '0';
	}
	if (input == 0)
		ans[0] = '0';
	ans[i] = '\0';
	return (ans);
}

// Make a function that rounds the input up by one
//	if (prec == 0 && (((long long unsigned int)(input * 10)) % 10 >= 5))
//		input += 1;
long double		round_up(long double input, int prec)
{
	long double temp;
	long double add;

	add = 1;
	temp = input;
	if (prec == -1)
		prec = 6;
	while (temp >= 1)
		temp -= 1;
	temp *= (10*(prec + 1));
//	printf("\ninput = %.10Lf\n", input);
	if (((long long unsigned int)(temp) % 10) >= 5)
	{
		while (prec--)
			add /= 10;
		input += add;
	}
//	printf("\nchanged input = %.10Lf\n", input);
	return (input);
}

/*
** function of handle varible format string in ft_printf
** step 1: organzie parameters into struct var (ft_pfmain_var_init)
** step 2: create output string and count (ret) length consisting
**			flag, width and precision (ft_pfvar_cal)
** step 3: copy the converted string into print
**			a. if '-' flag is on, run 1. flag 2. prec 3. width
**			b. if '0' flag is on, run 1. flag 2. width 3. prec
**			c. otherwise, run 1. width 2. flag, 3. prec
**			where:
**				flag function >> ft_pfflag_process
**				prec function >> ft_pfwidpre_preprocess
**				width function >> ft_pfwidpre_widprocess
** step 4: free var if there is no variable format string left
** step 5: return ret
*/

//Make a similar approach to Michael's method, it seems more versatile ^^^
char	*f_add_s_flag_width(char *print, t_var *info, long double input)
{
	char c[2];
	char *temp1;
//	char *temp2;
	char *padding;
	int len;

	len = ft_strlen(print);
	c[0] = (input < 0) ? '-' : '+';
	c[1] = '\0';
	if (info->flag & minus)
	{
		if (info->flag & plus)
			temp1 = ft_strjoin(c, print);
		else if (info->flag & space)
		{
			c[0] = ' ';
			temp1 = ft_strjoin(c, print);
		}
		else
			temp1 = ft_strdup(print);
		len = ft_strlen(temp1);
		if (info->width <= len)
		{
			ft_strdel(&print);
			return (temp1);
		}
		else
			info->width -= len;
		padding = ft_memset(ft_strnew(info->width), ' ', info->width);
		ft_strdel(&print);
		print = ft_strjoin(temp1, padding);
		ft_strdel(&temp1);
		ft_strdel(&padding);
		return (print);
	}
	if (info->flag & zero)
	{
		if (info->flag & plus || info->flag & space)
			len++;
		if (info->width <= len && (info->flag & plus || info->flag & space))
		{
			if (info->flag & space)
				c[0] = ' ';
			temp1 = ft_strjoin(c, print);
			ft_strdel(&print);
			print = ft_strdup(temp1);
			ft_strdel(&temp1);
			return (print);
		}
		else if (info->width <= len)
			return (print);
		else
			info->width -= len;
		padding = ft_memset(ft_strnew(info->width), '0', info->width);
//		printf("\npadding size = %zu\n", ft_strlen(padding));
		temp1 = ft_strjoin(padding, print);
		ft_strdel(&print);
		if (info->flag & plus)
			print = ft_strjoin(c, temp1);
		else if (info->flag & space)
		{
			print = ft_strjoin(" ", temp1);
		}
		else
			print = ft_strdup(temp1);
		ft_strdel(&temp1);
		ft_strdel(&padding);
		return (print);
	}
	//apply flag, width of 0, then prec
	else
	{
		if (info->flag & plus)
			temp1 = ft_strjoin(c, print);
		else if (info->flag & space)
		{
			c[0] = ' ';
			temp1 = ft_strjoin(c, print);
		}
		else
			temp1 = ft_strdup(print);
		len = ft_strlen(temp1);
		if (info->width <= len)
		{
			ft_strdel(&print);
			return (temp1);
		}
		else
			info->width -= len;
		padding = ft_memset(ft_strnew(info->width), ' ', info->width);
		print = ft_strjoin(padding, temp1);
		ft_strdel(&temp1);
		ft_strdel(&padding);
	}
	//apply width, flag, and then prec
	return (print);
}

/*
	char c = '\0';
	char sign = '\0';
	int width = info->width;
	char flag = info->flag;
	char pad = ' ';
	int len;
	char *padding;
	char *temp;

	if (info->flag & plus)
	{
		sign = (input < 0) ? '-' : '+';
		width--;
	}
	if (info->flag & space)
	{
		c = ' ';
		width--;
	}
	len = ft_strlen(print);
	if (width <= len)
		return (print);
// Assume width > len from here on....
	width -= len;
	padding = ft_memset(ft_strnew(width), pad, width);
	if (flag & minus)
	{
		temp = ft_strjoin(print, padding);
		ft_strdel(&print);
		print = temp;
	}
	else
	{
		if (flag & zero)
		{
			ft_strdel(&padding);
			padding = ft_memset(ft_strnew(width), '0', width);
			temp = ft_strjoin(padding, print);
			ft_strdel(&print);
			print = temp;
		}
		else
		{
			temp = ft_strjoin(padding, print);
			ft_strdel(&print);
			print = temp;
		}
	}
	ft_strdel(&padding);
	return (print);
}
	if (info->flag & minus)
	{

	}
	else
	{
		if (info->flag & zero)	
			;
	}
		//no zero flag;
	return (NULL);
}
*/

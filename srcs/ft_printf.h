/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzhao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 12:49:56 by vzhao             #+#    #+#             */
/*   Updated: 2019/07/24 17:39:37 by vzhao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft/libft.h"
# include <stdarg.h>

# define llui long long unsigned int
// Delete this include after finish testing...
# include <stdio.h>
# include <limits.h>

typedef struct		s_var
{
	int				flag;
	int				width;
	int				precision;
	int				length;
	char			conv;
}					t_var;

enum	e_flags 
{		zero = 1,
		hash = 1 << 1,
	   	minus = 1 << 2,
		plus = 1 << 3,
		space = 1 << 4
};

enum	e_lengths
{
		h = 1,
		hh,
		l,
		ll,
		j,
		z,
		L
};

int		ft_printf(const char *format, ...);
int		get_next_call(va_list ap, char *str, int count);

int		get_info(va_list ap, char *str);
char	*get_flag(char *str, t_var *info);
char	*get_width(char *str, t_var *info);
char	*get_precision(char *str, t_var *info);
char	*get_length(char *str, t_var *info);

int		is_type(char c);
int		is_flag(char c);
int		is_length(char c);

int		mod_funct(t_var *info, va_list ap);
int		c_funct(t_var *info, va_list ap);
int		s_funct(t_var *info, va_list ap);
int		p_funct(t_var *info, va_list ap);
int		id_funct(t_var *info, va_list ap);
int		u_funct(t_var *info, va_list ap);
int		o_funct(t_var *info, va_list ap);
int		x_funct(t_var *info, va_list ap);
int		X_funct(t_var *info, va_list ap);
int		f_funct(t_var *info, va_list ap);

void	ft_handle_flags(t_var *info);
void	get_conv(char *str, t_var *info);
int		llui_len_base(long long unsigned int n, int base);
char	llui_check_base(long long unsigned int n, int base, char choice);
char	*llui_itoa_base(long long unsigned int n, int base, char choice);

llui	apply_length(int length, va_list ap);
char	*apply_precision(char *print, t_var *info, llui input);
char	*apply_flags(char *print, t_var *info, llui input, char *sign);
char	*apply_width(char *print, t_var *info);

int		ld_int_len(long double n);
char	*ld_itoa(long double n);
char	*ld_decimals(long double input, int prec);
long double		round_up(long double input, int prec);
char	*f_add_s_flag_width(char *print, t_var *info, long double input);

#endif

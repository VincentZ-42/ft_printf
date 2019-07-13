/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzhao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 12:49:56 by vzhao             #+#    #+#             */
/*   Updated: 2019/07/12 16:50:56 by vzhao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft/libft.h"
# include <stdarg.h>

// Delete this include after finish testing...
# include <stdio.h>

typedef struct		s_var
{
	int				flag;
	int				width;
	int				precision;
	int				length;
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
		z
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

int		c_funct(t_var *info, va_list ap);
int		s_funct(t_var *info, va_list ap);
int		p_funct(t_var *info, va_list ap);
int		id_funct(t_var *info, va_list ap);

void	ft_handle_flags(t_var *info);

#endif

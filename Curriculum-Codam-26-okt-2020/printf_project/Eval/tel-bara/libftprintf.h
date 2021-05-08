/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   libftprintf.h                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: tel-bara <tel-bara@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/21 11:53:07 by tel-bara      #+#    #+#                 */
/*   Updated: 2020/12/05 21:40:02 by tel-bara      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include "libft/libft.h"
# include <stdarg.h>

typedef struct	s_flags
{
	int		hashtag;
	int		zero;
	int		dash;
	int		space;
	int		plus;
	int		field_width;
	int		precision_start;
	int		precision_value;
	int		precision_end;
	int		length_modifier_l;
	int		length_modifier_ll;
	int		length_modifier_h;
	int		length_modifier_hh;
}				t_flags;

typedef struct	s_double
{
	double		nbr;
	double		nbr_e;
	int			exp;
	long long	round;
	long long	decimal;
	int			len;
	int			intlen;
	int			declen;
	int			trailing_zeroes;
	int			front_zeroes;
	char		conv;
	char		sign;
}				t_double;

typedef void	(*t_dp)(t_flags *flags, va_list args, int *count);

int				ft_printf(const char *s, ...);
void			ft_printf_parse_flags(const char **s, t_flags *flags,
				va_list args);
void			ft_printf_parse_specifier(const char **specifier,
				t_flags *flags, va_list args, int *count);
void			ft_printf_convert_char(t_flags *flags, va_list args,
				int *count);
void			ft_printf_convert_string(t_flags *flags, va_list args,
				int *count);
void			ft_printf_convert_int(t_flags *flags, va_list args,
				int *count);
void			ft_printf_convert_u_int(t_flags *flags, va_list args,
				int *count);
void			ft_printf_convert_hex(t_flags *flags, va_list args,
				int *count);
void			ft_printf_convert_big_hex(t_flags *flags, va_list args,
				int *count);
void			ft_printf_convert_hex_ptr(t_flags *flags, va_list args,
				int *count);
void			ft_printf_write_percentage(t_flags *flags, va_list args,
				int *count);
void			ft_printf_store_count(t_flags *flags, va_list args,
				int *count);
void			ft_printf_write_invalid(const char **s, t_flags *flags,
				va_list args, int *count);
void			ft_printf_convert_double_f(t_flags *flags, va_list args,
				int *count);
void			ft_printf_convert_double_e(t_flags *flags, va_list args,
				int *count);
void			ft_printf_convert_double_g(t_flags *flags, va_list args,
				int *count);
void			ft_printf_get_exp(t_double *num, t_flags *flags);
double			ft_printf_to_exp(double nbr, int exp);
void			ft_printf_write_sign(long long nbr, t_flags *flags);
void			ft_printf_double_efg_left_padding(t_double *num,
				t_flags *flags, int *count);
void			ft_printf_double_efg_right_padding(t_double *num,
				t_flags *flags, int *count);
void			ft_printf_write_string(const char **s, int *count);
void			ft_printf_write_front_zeroes(t_double *num, t_flags *flags);
void			ft_printf_write_double_sign(t_double *num, t_flags *flags);

#endif

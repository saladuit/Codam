/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf_convert_int.c                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: tel-bara <tel-bara@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/24 16:57:41 by tel-bara      #+#    #+#                 */
/*   Updated: 2020/11/30 21:05:04 by tel-bara      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	ft_printf_int_left_padding(long long nbr, int numlen,
t_flags *flags, int *count)
{
	int			left_padding;
	char		padding_char;
	int			sign;

	left_padding = (!flags->dash) ? flags->field_width : 0;
	padding_char = (flags->zero) ? '0' : ' ';
	sign = (nbr < 0 || flags->space || flags->plus) ? 1 : 0;
	if (sign && flags->zero)
		ft_printf_write_sign(nbr, flags);
	while (left_padding > numlen &&
	left_padding > flags->precision_value + sign)
	{
		ft_putchar_fd(padding_char, 1);
		(*count)++;
		left_padding--;
	}
	if (sign && !flags->zero)
		ft_printf_write_sign(nbr, flags);
	while (flags->precision_value > numlen - sign)
	{
		ft_putchar_fd('0', 1);
		(*count)++;
		numlen++;
	}
}

static void	ft_printf_int_right_padding(long long nbr, int numlen,
t_flags *flags, int *count)
{
	int			right_padding;
	int			sign;

	right_padding = (flags->dash) ? flags->field_width : 0;
	sign = (nbr < 0 || flags->space || flags->plus) ? 1 : 0;
	while (right_padding > numlen &&
	right_padding > flags->precision_value + sign)
	{
		ft_putchar_fd(' ', 1);
		(*count)++;
		right_padding--;
	}
}

void		ft_printf_convert_int(t_flags *flags, va_list args, int *count)
{
	long long	nbr;
	int			numlen;

	if (flags->precision_start)
		flags->zero = 0;
	if (flags->length_modifier_l)
		nbr = (long)va_arg(args, long);
	else if (flags->length_modifier_ll)
		nbr = va_arg(args, long long);
	else if (flags->length_modifier_h)
		nbr = (short)va_arg(args, int);
	else if (flags->length_modifier_hh)
		nbr = (signed char)va_arg(args, int);
	else
		nbr = (int)va_arg(args, int);
	numlen = (nbr < 0 || (!flags->space && !flags->plus)) ?
	ft_numlen(nbr) : ft_numlen(nbr) + 1;
	if (!flags->precision_value && !nbr)
		numlen -= ft_numlen(nbr);
	ft_printf_int_left_padding(nbr, numlen, flags, count);
	if (nbr || flags->precision_value)
		(nbr < 0) ? ft_putunbr_fd(-nbr, 1) : ft_putnbr_fd(nbr, 1);
	ft_printf_int_right_padding(nbr, numlen, flags, count);
	*count += numlen;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf_convert_hex.c                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: tel-bara <tel-bara@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/24 16:57:41 by tel-bara      #+#    #+#                 */
/*   Updated: 2020/11/30 21:03:11 by tel-bara      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	ft_printf_hex_left_padding(unsigned long long nbr, int numlen,
t_flags *flags, int *count)
{
	int			left_padding;
	char		padding_char;
	int			prefix;

	left_padding = (!flags->dash) ? flags->field_width : 0;
	padding_char = (flags->zero) ? '0' : ' ';
	prefix = (nbr && flags->hashtag) ? 2 : 0;
	if (prefix && flags->zero)
		ft_putstr_fd("0x", 1);
	while (left_padding > numlen &&
	left_padding > flags->precision_value + prefix)
	{
		ft_putchar_fd(padding_char, 1);
		(*count)++;
		left_padding--;
	}
	if (prefix && !flags->zero)
		ft_putstr_fd("0x", 1);
	while (flags->precision_value > numlen - prefix)
	{
		ft_putchar_fd('0', 1);
		(*count)++;
		numlen++;
	}
}

static void	ft_printf_hex_right_padding(unsigned long long nbr, int numlen,
t_flags *flags, int *count)
{
	int			right_padding;
	int			prefix;

	right_padding = (flags->dash) ? flags->field_width : 0;
	prefix = (nbr && flags->hashtag) ? 2 : 0;
	while (right_padding > numlen &&
	right_padding > flags->precision_value + prefix)
	{
		ft_putchar_fd(' ', 1);
		(*count)++;
		right_padding--;
	}
}

void		ft_printf_convert_hex(t_flags *flags, va_list args, int *count)
{
	unsigned long long	nbr;
	int					numlen;

	if (flags->precision_start)
		flags->zero = 0;
	if (flags->length_modifier_l)
		nbr = (unsigned long)va_arg(args, long);
	else if (flags->length_modifier_ll)
		nbr = va_arg(args, long long);
	else if (flags->length_modifier_h)
		nbr = (unsigned short)va_arg(args, int);
	else if (flags->length_modifier_hh)
		nbr = (unsigned char)va_arg(args, int);
	else
		nbr = (unsigned int)va_arg(args, int);
	numlen = (nbr && flags->hashtag) ? ft_hexlen(nbr) + 2 : ft_hexlen(nbr);
	if (!nbr && !flags->precision_value)
		numlen = 0;
	ft_printf_hex_left_padding(nbr, numlen, flags, count);
	if (nbr || flags->precision_value)
		ft_putlunbr_base_fd(nbr, "0123456789abcdef", 1);
	ft_printf_hex_right_padding(nbr, numlen, flags, count);
	*count += numlen;
}

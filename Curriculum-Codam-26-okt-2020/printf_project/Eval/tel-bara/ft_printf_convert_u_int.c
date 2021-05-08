/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf_convert_u_int.c                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: tel-bara <tel-bara@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/24 16:57:41 by tel-bara      #+#    #+#                 */
/*   Updated: 2020/11/30 21:02:39 by tel-bara      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	ft_printf_u_int_left_padding(int numlen, t_flags *flags,
int *count)
{
	int			left_padding;
	char		padding_char;

	left_padding = (!flags->dash) ? flags->field_width : 0;
	padding_char = (flags->zero) ? '0' : ' ';
	while (left_padding > numlen && left_padding > flags->precision_value)
	{
		ft_putchar_fd(padding_char, 1);
		(*count)++;
		left_padding--;
	}
	while (flags->precision_value > numlen)
	{
		ft_putchar_fd('0', 1);
		(*count)++;
		numlen++;
	}
}

static void	ft_printf_u_int_right_padding(int numlen, t_flags *flags,
int *count)
{
	int			right_padding;

	right_padding = (flags->dash) ? flags->field_width : 0;
	while (right_padding > numlen && right_padding > flags->precision_value)
	{
		ft_putchar_fd(' ', 1);
		(*count)++;
		right_padding--;
	}
}

void		ft_printf_convert_u_int(t_flags *flags, va_list args, int *count)
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
	numlen = (flags->precision_value || nbr) ? ft_unumlen(nbr) : 0;
	ft_printf_u_int_left_padding(numlen, flags, count);
	if (flags->precision_value || nbr)
		ft_putunbr_fd(nbr, 1);
	ft_printf_u_int_right_padding(numlen, flags, count);
	*count += numlen;
}

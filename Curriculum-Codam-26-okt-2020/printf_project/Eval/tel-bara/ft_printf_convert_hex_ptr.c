/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf_convert_hex_ptr.c                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: tel-bara <tel-bara@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/24 16:57:41 by tel-bara      #+#    #+#                 */
/*   Updated: 2020/12/05 21:10:31 by tel-bara      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	ft_printf_hex_ptr_left_padding(int numlen, t_flags *flags,
int *count)
{
	int			left_padding;
	char		padding_char;

	left_padding = (!flags->dash) ? flags->field_width : 0;
	padding_char = (flags->zero) ? '0' : ' ';
	if (flags->zero)
		ft_putstr_fd("0x", 1);
	while (left_padding > numlen && left_padding > flags->precision_value + 2)
	{
		ft_putchar_fd(padding_char, 1);
		(*count)++;
		left_padding--;
	}
	if (!flags->zero)
		ft_putstr_fd("0x", 1);
	while (flags->precision_value > numlen - 2)
	{
		ft_putchar_fd('0', 1);
		(*count)++;
		numlen++;
	}
}

static void	ft_printf_hex_ptr_right_padding(int numlen, t_flags *flags,
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

void		ft_printf_convert_hex_ptr(t_flags *flags, va_list args, int *count)
{
	unsigned long long	nbr;
	int					numlen;

	nbr = (unsigned long long)va_arg(args, void *);
	numlen = ft_hexlen(nbr) + 2;
	if (!flags->precision_value && !nbr)
		numlen = 2;
	ft_printf_hex_ptr_left_padding(numlen, flags, count);
	if (flags->precision_value || nbr)
		ft_putlunbr_base_fd(nbr, "0123456789abcdef", 1);
	ft_printf_hex_ptr_right_padding(numlen, flags, count);
	*count += numlen;
}

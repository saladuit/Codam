/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf_write_invalid.c                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: tel-bara <tel-bara@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/25 16:28:01 by tel-bara      #+#    #+#                 */
/*   Updated: 2020/11/30 16:51:26 by tel-bara      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	ft_printf_inv_left_padding(t_flags *flags, int *count)
{
	int			left_padding;
	char		padding_char;

	left_padding = (!flags->dash) ? flags->field_width : 0;
	padding_char = (flags->zero) ? '0' : ' ';
	while (left_padding > 1)
	{
		ft_putchar_fd(padding_char, 1);
		(*count)++;
		left_padding--;
	}
}

static void	ft_printf_inv_right_padding(t_flags *flags, int *count)
{
	int			right_padding;

	right_padding = (flags->dash) ? flags->field_width : 0;
	while (right_padding > 1)
	{
		ft_putchar_fd(' ', 1);
		(*count)++;
		right_padding--;
	}
}

void		ft_printf_write_invalid(const char **s, t_flags *flags,
			va_list args, int *count)
{
	(void)args;
	(*count)++;
	ft_printf_inv_left_padding(flags, count);
	if (ft_putlchar_fd(**s, 1) == -1)
		*count = -1;
	ft_printf_inv_right_padding(flags, count);
}

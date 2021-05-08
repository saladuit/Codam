/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: tel-bara <tel-bara@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/21 11:51:56 by tel-bara      #+#    #+#                 */
/*   Updated: 2020/12/04 14:56:58 by tel-bara      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int			ft_printf(const char *s, ...)
{
	t_flags			flags;
	int				count;
	va_list			args;

	count = 0;
	va_start(args, s);
	while (*s)
	{
		if (*s == '%')
		{
			s++;
			ft_bzero(&flags, sizeof(flags));
			ft_printf_parse_flags(&s, &flags, args);
			ft_printf_parse_specifier(&s, &flags, args, &count);
			if (count == -1)
				break ;
		}
		ft_printf_write_string(&s, &count);
		if (count == -1)
			break ;
	}
	va_end(args);
	return (count);
}

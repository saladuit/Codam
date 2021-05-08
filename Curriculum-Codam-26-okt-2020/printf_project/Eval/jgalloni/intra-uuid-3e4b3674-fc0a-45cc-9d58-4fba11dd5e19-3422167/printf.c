/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   printf.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jgalloni <jgalloni@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/07 15:26:08 by joellegallu   #+#    #+#                 */
/*   Updated: 2021/02/21 18:33:20 by jgalloni      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ftprintf.h"

int	len_til_specifier(char *format)
{
	int	i;

	i = 0;
	while (format[i] && format[i] != '%')
		i++;
	return (i);
}

void	init_struct(struct s_format_data *data)
{
	data->width = 0;
	data->precision = -1;
	data->width_negative = 0;
	data->width_bzero = 0;
}

int	ft_printf(char *format, ...)
{
	va_list					args;
	struct s_format_data	format_data;
	int						segment_size;
	int						ret;

	format_data.return_value = 0;
	va_start(args, format);
	while (*format)
	{
		segment_size = len_til_specifier(format);
		put_str(format, segment_size, &format_data);
		format += segment_size;
		if (!*(format))
			break ;
		format++;
		init_struct(&format_data);
		ret = parse_flags(&format, &format_data, args);
		if (ret == -1)
		{
			va_end(args);
			return (ret);
		}
	}
	va_end(args);
	return (format_data.return_value);
}

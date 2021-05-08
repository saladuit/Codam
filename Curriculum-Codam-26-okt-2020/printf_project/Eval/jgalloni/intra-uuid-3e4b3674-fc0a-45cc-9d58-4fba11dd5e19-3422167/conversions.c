/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   conversions.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: jgalloni <jgalloni@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/21 18:38:02 by jgalloni      #+#    #+#                 */
/*   Updated: 2021/02/21 19:42:17 by jgalloni      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft/libft.h"
#include "ftprintf.h"

int	print_int(struct s_format_data *data, va_list list, int is_unsigned)
{
	char				*str;
	int					n;
	unsigned int		u_n;

	if (!is_unsigned)
	{
		n = va_arg(list, int);
		str = ft_itoa(n);
	}
	else
	{
		u_n = va_arg(list, unsigned int);
		str = itoa_nbr_base(u_n, "0123456789");
	}
	if (!str)
		return (-1);
	if (data->width_negative)
		data->width_bzero = 0;
	width_handler(data, str);
	free(str);
	return (1);
}

int	print_string(struct s_format_data *data, va_list list)
{
	char	*str;
	int		print_len;
	int		str_len;

	str = va_arg(list, char*);
	if (str == NULL)
		str = "(null)";
	str_len = ft_strlen(str);
	if (data->precision < 0 || data->precision > str_len)
		print_len = str_len;
	else
		print_len = data->precision;
	if (!data->width_negative && data->width > 0)
		print_width(' ', data->width - print_len, data);
	put_str(str, print_len, data);
	if (data->width > 0 && data->width_negative)
		print_width(' ', data->width - print_len, data);
	return (1);
}

int	print_char(va_list list, struct s_format_data *data, int is_pct)
{
	char	c;
	char	width_char;

	c = '%';
	width_char = ' ';
	if (data->width_negative)
		data->width_bzero = 0;
	if (data->width_bzero)
		width_char = '0';
	if (!is_pct)
		c = va_arg(list, int);
	if (data->width > 1 && !data->width_negative)
		print_width(width_char, data->width - 1, data);
	write(1, &c, 1);
	data->return_value += 1;
	if (data->width > 1 && data->width_negative)
		print_width(width_char, data->width - 1, data);
	return (1);
}

int	print_hexa(va_list list, struct s_format_data *data, char specifier)
{
	char					*str;
	unsigned int			n;

	n = va_arg(list, unsigned int);
	str = itoa_nbr_base(n, "0123456789abcdef");
	if (!str)
		return (-1);
	if (specifier == 'X')
		string_to_upper(&str);
	if (data->width_negative)
		data->width_bzero = 0;
	width_handler(data, str);
	free(str);
	return (1);
}

int	print_pointer(va_list list, struct s_format_data *data)
{
	char				*str;
	int					len;
	unsigned long int	n;

	n = va_arg(list, unsigned long int);
	str = itoa_nbr_base(n, "0123456789abcdef");
	if (!str)
		return (-1);
	len = strlen_pointer_address(str, data);
	if (!data->width_negative)
	{
		if (data->precision >= len)
			print_width(' ', data->width - (data->precision + 2), data);
		else
			print_width(' ', data->width - len - 2, data);
		data->width = 0;
	}
	put_str("0x", 2, data);
	if (data->width_negative)
		data->width_bzero = 0;
	data->width -= 2;
	width_handler(data, str);
	free(str);
	return (1);
}

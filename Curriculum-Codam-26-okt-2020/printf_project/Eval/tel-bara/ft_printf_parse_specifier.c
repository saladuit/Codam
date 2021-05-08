/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf_parse_specifier.c                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: tel-bara <tel-bara@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/23 17:25:35 by tel-bara      #+#    #+#                 */
/*   Updated: 2020/11/30 12:41:56 by tel-bara      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void		ft_printf_parse_specifier(const char **specifier, t_flags *flags,
va_list args, int *count)
{
	static const t_dp	dispatch_table[256] = {
		['c'] = &ft_printf_convert_char,
		['s'] = &ft_printf_convert_string,
		['p'] = &ft_printf_convert_hex_ptr,
		['d'] = &ft_printf_convert_int,
		['i'] = &ft_printf_convert_int,
		['u'] = &ft_printf_convert_u_int,
		['x'] = &ft_printf_convert_hex,
		['X'] = &ft_printf_convert_big_hex,
		['%'] = &ft_printf_write_percentage,
		['n'] = &ft_printf_store_count,
		['f'] = &ft_printf_convert_double_f,
		['g'] = &ft_printf_convert_double_g,
		['e'] = &ft_printf_convert_double_e,
	};

	if (!(**specifier))
		return ;
	if (dispatch_table[(int)**specifier])
		dispatch_table[(int)**specifier](flags, args, count);
	else
		ft_printf_write_invalid(specifier, flags, args, count);
	(*specifier)++;
}

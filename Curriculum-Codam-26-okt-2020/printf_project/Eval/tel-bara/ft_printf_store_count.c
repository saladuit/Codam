/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf_store_count.c                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: tel-bara <tel-bara@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/25 16:57:13 by tel-bara      #+#    #+#                 */
/*   Updated: 2020/11/30 12:47:29 by tel-bara      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void		ft_printf_store_count(t_flags *flags, va_list args, int *count)
{
	void	*store;

	if (flags->length_modifier_l)
		store = (long long *)va_arg(args, long long *);
	else if (flags->length_modifier_ll)
		store = va_arg(args, long *);
	else if (flags->length_modifier_h)
		store = (short *)va_arg(args, short *);
	else if (flags->length_modifier_hh)
		store = (signed char *)va_arg(args, signed char *);
	else
		store = (int *)va_arg(args, int *);
	*(int *)store = *count;
}

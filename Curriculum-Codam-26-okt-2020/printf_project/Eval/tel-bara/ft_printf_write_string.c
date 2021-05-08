/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf_write_string.c                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: tel-bara <tel-bara@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/28 17:07:07 by tel-bara      #+#    #+#                 */
/*   Updated: 2020/12/05 20:23:38 by tel-bara      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void		ft_printf_write_string(const char **s, int *count)
{
	int		len;

	len = ft_strclen(*s, '%');
	write(1, *s, len);
	*s += len;
	*count += len;
}

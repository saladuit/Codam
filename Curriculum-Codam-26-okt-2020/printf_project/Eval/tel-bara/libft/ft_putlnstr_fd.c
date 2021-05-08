/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putlnstr_fd.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: tel-bara <tel-bara@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/29 19:48:40 by tel-bara      #+#    #+#                 */
/*   Updated: 2020/11/28 18:34:21 by tel-bara      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_putlnstr_fd(char *s, int fd, int len)
{
	if (s && len)
	{
		len = (len > (int)ft_strlen(s)) ? (int)ft_strlen(s) : len;
		return (write(fd, s, len));
	}
	return (0);
}

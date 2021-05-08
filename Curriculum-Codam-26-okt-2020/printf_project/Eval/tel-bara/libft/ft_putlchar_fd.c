/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putlchar_fd.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: tel-bara <tel-bara@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/29 19:38:50 by tel-bara      #+#    #+#                 */
/*   Updated: 2020/11/29 16:23:35 by tel-bara      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

ssize_t		ft_putlchar_fd(char c, int fd)
{
	return (write(fd, &c, 1));
}

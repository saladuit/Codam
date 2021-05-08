/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_chrstr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: djonker <marvin@codam.nl>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/15 02:30:48 by djonker       #+#    #+#                 */
/*   Updated: 2021/02/13 22:34:29 by djonker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_chrstr(char c, char *s)
{
	while (*s)
	{
		if (c == *s)
			return (1);
		s++;
	}
	if (c == *s)
		return (1);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlen.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/25 16:46:13 by mraasvel      #+#    #+#                 */
/*   Updated: 2020/10/29 10:46:03 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (s == 0)
		return (0);
	while (s[i] != 0)
		i++;
	return (i);
}

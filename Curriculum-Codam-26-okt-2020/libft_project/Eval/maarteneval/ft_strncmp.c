/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strncmp.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/26 12:44:47 by mraasvel      #+#    #+#                 */
/*   Updated: 2020/10/29 10:55:27 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (s1 == 0 || s2 == 0)
		return (0);
	while (i < n && (s1[i] != 0 || s2[i] != 0))
	{
		if (s1[i] != s2[i])
		{
			if ((unsigned char)s1[i] < (unsigned char)s2[i])
				return (-1);
			else
				return (1);
		}
		i++;
	}
	return (0);
}

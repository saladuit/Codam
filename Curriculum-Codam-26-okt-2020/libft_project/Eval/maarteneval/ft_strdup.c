/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strdup.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/26 16:10:10 by mraasvel      #+#    #+#                 */
/*   Updated: 2020/10/29 10:58:02 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(const char *s)
{
	int		len;
	char	*d;

	len = 0;
	if (s == 0)
		return (0);
	while (s[len] != 0)
		len++;
	d = (char*)malloc(len + 1);
	if (d == 0)
		return (0);
	d[len] = 0;
	len = 0;
	while (s[len] != 0)
	{
		d[len] = s[len];
		len++;
	}
	return (d);
}

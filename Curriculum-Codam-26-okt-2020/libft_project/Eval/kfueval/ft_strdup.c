/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strdup.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: kfu <kfu@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/29 16:41:57 by kfu           #+#    #+#                 */
/*   Updated: 2020/11/16 10:04:44 by kfu           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>

char	*ft_strdup(const char *str)
{
	int		len;
	char	*dup;

	len = 0;
	while (str[len])
	{
		len++;
	}
	dup = (char *)malloc(sizeof(char) * len + 1);
	if (dup == NULL)
		return (NULL);
	len = 0;
	while (str[len])
	{
		dup[len] = str[len];
		len++;
	}
	dup[len] = '\0';
	return (dup);
}

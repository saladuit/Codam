/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_substr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jgalloni <jgalloni@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/01 21:18:57 by jgalloni      #+#    #+#                 */
/*   Updated: 2020/11/08 12:16:06 by jgalloni      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	int		i;

	if (start < ft_strlen(s))
	{
		str = malloc(len + 1);
		if (str == 0)
			return (0);
		i = 0;
		while (i < (int)len && s[start + i] != 0)
		{
			str[i] = s[start + i];
			i++;
		}
		str[i] = 0;
	}
	else
	{
		str = malloc(1);
		str[0] = 0;
	}
	return (str);
}

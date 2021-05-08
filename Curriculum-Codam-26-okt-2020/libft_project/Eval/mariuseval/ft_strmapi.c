/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strmapi.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-wij <mvan-wij@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/27 12:18:41 by mvan-wij      #+#    #+#                 */
/*   Updated: 2020/10/31 14:21:51 by mvan-wij      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		len;
	char	*mapped;
	int		i;

	if (s == NULL || f == NULL)
		return (NULL);
	len = ft_strlen(s);
	mapped = malloc((len + 1) * sizeof(char));
	if (mapped == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		mapped[i] = f(i, s[i]);
		i++;
	}
	mapped[i] = '\0';
	return (mapped);
}

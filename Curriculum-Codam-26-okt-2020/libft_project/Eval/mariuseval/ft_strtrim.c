/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strtrim.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-wij <mvan-wij@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/27 11:41:25 by mvan-wij      #+#    #+#                 */
/*   Updated: 2020/10/31 14:22:13 by mvan-wij      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strtrim(char const *s1, char const *set)
{
	int	len;
	int	i;
	int	start;

	if (s1 == NULL)
		return (NULL);
	len = ft_strlen(s1);
	i = 0;
	while (i < len)
	{
		if (ft_strchr(set, s1[i]) == NULL)
			break ;
		i++;
	}
	if (i == len)
		return (ft_calloc(1, 1));
	start = i;
	while (len > 0)
	{
		if (ft_strchr(set, s1[len - 1]) == NULL)
			break ;
		len--;
	}
	return (ft_substr(s1, start, len - start));
}

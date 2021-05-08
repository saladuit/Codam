/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strtrim.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: djonker <marvin@codam.nl>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/11 16:41:19 by djonker       #+#    #+#                 */
/*   Updated: 2021/03/30 18:06:43 by djonker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *str, char const *set)
{
	char	*r;
	int		l;

	if (!str)
		return (NULL);
	if (!set)
		return (ft_malstr((char *)str, '\0'));
	while (*str && ft_strchr(set, *str))
		str++;
	l = ft_strlen((char *)str);
	while (ft_strchr(set, str[l]) && l)
		l--;
	r = ft_substr((char *)str, 0, l + 1);
	return (r);
}

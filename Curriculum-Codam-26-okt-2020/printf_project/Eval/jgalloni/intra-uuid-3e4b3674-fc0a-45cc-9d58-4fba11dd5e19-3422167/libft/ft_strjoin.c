/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strjoin.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jgalloni <jgalloni@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/01 21:12:01 by jgalloni      #+#    #+#                 */
/*   Updated: 2020/11/04 15:41:44 by jgalloni      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		i;
	int		k;

	str = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!str)
		return (0);
	i = 0;
	k = 0;
	while (s1[i])
	{
		str[k] = s1[i];
		i++;
		k++;
	}
	i = 0;
	while (s2[i])
	{
		str[k] = s2[i];
		i++;
		k++;
	}
	str[k] = 0;
	return (str);
}

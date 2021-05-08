/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strtrim.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jgalloni <jgalloni@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/01 21:17:16 by jgalloni      #+#    #+#                 */
/*   Updated: 2020/11/14 15:53:43 by jgalloni      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	int	i;
	int	k;
	int	start;

	i = 0;
	k = 0;
	while (s1[i])
	{
		if (ft_strchr(set, s1[i]) == 0)
			break ;
		i++;
	}
	start = i;
	if (start == (int)ft_strlen(s1))
		return (ft_calloc(1, 1));
	i = ft_strlen(s1) - 1;
	while (s1[i])
	{
		if (ft_strchr(set, s1[i]) == 0)
			break ;
		i--;
	}
	return (ft_substr(s1, start, i - start + 1));
}

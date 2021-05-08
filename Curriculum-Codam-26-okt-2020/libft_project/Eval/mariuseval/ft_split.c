/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_split.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-wij <mvan-wij@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/27 11:59:22 by mvan-wij      #+#    #+#                 */
/*   Updated: 2020/10/31 14:21:19 by mvan-wij      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static char	**ft_create_split_arr(char const *str, char c, int *items)
{
	char	**arr;
	char	*s;

	if (str == NULL)
		return (NULL);
	s = (char *)str;
	*items = 0;
	while (*s != '\0')
	{
		*items += *s != c && (s == str || *(s - 1) == c);
		s++;
	}
	arr = malloc((*items + 1) * sizeof(char *));
	return (arr);
}

static void	*ft_clearsplitarr(char **arr)
{
	int i;

	i = 0;
	while (arr[i] != NULL)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
	return (NULL);
}

char		**ft_split(char const *str, char c)
{
	char	**arr;
	char	*s;
	char	*cur;
	int		items;

	arr = ft_create_split_arr(str, c, &items);
	if (arr == NULL)
		return (NULL);
	cur = (char *)str;
	while (*cur != '\0')
	{
		if (*cur != c && (cur == str || *(cur - 1) == c))
			s = cur;
		if (*cur != c && (*(cur + 1) == c || *(cur + 1) == '\0'))
		{
			*arr = ft_substr(s, 0, cur - s + 1);
			if (*arr == NULL)
				return (ft_clearsplitarr(arr - items));
			arr++;
		}
		cur++;
	}
	*arr = NULL;
	return (arr - items);
}

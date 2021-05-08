/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_split.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: jgalloni <jgalloni@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/07 17:18:50 by jgalloni      #+#    #+#                 */
/*   Updated: 2021/02/14 12:58:36 by jgalloni      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_strings(char const *s, char c)
{
	int	i;
	int	count;
	int	last_was_delim;

	i = 0;
	count = 0;
	last_was_delim = 1;
	while (s[i])
	{
		if (last_was_delim && s[i] != c)
			count++;
		if (s[i] == c)
			last_was_delim = 1;
		else
			last_was_delim = 0;
		i++;
	}
	return (count);
}

static int	alloc_array(char ***out, char const *s, char c)
{
	int	size;

	size = count_strings(s, c);
	if (size)
		*out = ft_calloc((size + 1) * sizeof(char *), 1);
	else
		*out = ft_calloc(1 * sizeof(char *), 1);
	if (!*out)
		return (-1);
	return (size);
}

static int	free_utility(char **arr, int fail_index)
{
	int		i;

	i = 0;
	while (fail_index > 0)
	{
		fail_index--;
		free(arr[fail_index]);
	}
	free(arr);
	return (0);
}

static int	split_loop(char const *s, char c, char **out, int len)
{
	int		k;
	int		count;
	char	*str;

	k = 0;
	while (k < len)
	{
		count = 0;
		while (*s == c)
			s++;
		str = (char*)s;
		while (*s != '\0' && *s != c)
		{
			s++;
			count++;
		}
		out[k] = ft_calloc(count + 1, 1);
		if (!out)
			return (free_utility(out, k));
		ft_memccpy(out[k], str, c, count);
		s++;
		k++;
	}
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**out;
	int		count;

	count = alloc_array(&out, s, c);
	if (count < 0)
		return (0);
	if (!split_loop(s, c, out, count))
		return (0);
	return (out);
}

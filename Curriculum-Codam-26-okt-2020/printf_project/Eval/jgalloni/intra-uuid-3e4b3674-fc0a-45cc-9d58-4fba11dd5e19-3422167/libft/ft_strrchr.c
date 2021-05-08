/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strrchr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jgalloni <jgalloni@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/28 16:22:13 by jgalloni      #+#    #+#                 */
/*   Updated: 2020/11/04 15:49:02 by jgalloni      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

void	*ft_strrchr(const char *s, int c)
{
	char	ch;
	int		i;

	i = 0;
	ch = (char)c;
	while (s[i])
		i++;
	if (c == 0)
		return ((void *)&s[i]);
	while (i >= 0)
	{
		if (s[i] == ch)
			return ((void *)&s[i]);
		i--;
	}
	return (0);
}

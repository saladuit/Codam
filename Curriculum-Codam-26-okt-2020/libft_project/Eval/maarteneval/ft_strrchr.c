/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strrchr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/26 11:35:02 by mraasvel      #+#    #+#                 */
/*   Updated: 2020/10/30 12:41:24 by saladin       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *s, int c)
{
	char	*finder;
	char	*ret;

	finder = (char*)s;
	ret = finder;
	if (finder == 0)
		return (0);
	while (*finder != 0)
	{
		if (*finder == c)
			ret = finder;
		finder++;
	}
	if (*finder == c)
		return (finder);
	else if (*ret == c)
		return (ret);
	return (0);
}

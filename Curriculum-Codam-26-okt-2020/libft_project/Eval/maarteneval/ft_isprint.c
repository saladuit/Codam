/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_isprint.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/26 14:27:43 by mraasvel      #+#    #+#                 */
/*   Updated: 2020/10/26 14:31:41 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

int	ft_isprint(int c)
{
	if ((unsigned int)c > 31 && (unsigned int)c < 127)
		return (16384);
	return (0);
}

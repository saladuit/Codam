/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atoi.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/26 12:56:28 by mraasvel      #+#    #+#                 */
/*   Updated: 2020/10/29 10:29:08 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *nptr)
{
	int	nbr;
	int	negative;
	int	i;

	if ((char*)nptr == 0 || *((char*)nptr) == 0)
		return (0);
	negative = 1;
	i = 0;
	while (nptr[i] == '\r' || nptr[i] == '\f' || nptr[i] == '\n'
		|| nptr[i] == '\v' || nptr[i] == ' ' || nptr[i] == '\t')
		i++;
	if (nptr[i] == '-')
		negative = -negative;
	if (nptr[i] == '+' || nptr[i] == '-')
		i++;
	nbr = 0;
	while (nptr[i] != 0 && nptr[i] >= '0' && nptr[i] <= '9')
	{
		nbr = (nbr * 10) + (nptr[i] - '0');
		i++;
	}
	return (nbr * negative);
}

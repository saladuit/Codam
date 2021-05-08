/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   GNLboss.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: saladin <saladin@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/28 15:26:18 by saladin       #+#    #+#                 */
/*   Updated: 2021/01/28 15:54:37 by saladin       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

long long		okrrrrrrr(void)
{
	static long long ganggang = 0;
	ganggang += 1000000000;
	return (ganggang);
}
int		main(void)
{
	int 	i;
	long long		result;

	i = 9;
	while (i)
	{
		result = okrrrrrrr();
		printf("Quantity: %lld\n", result);
		i--;
	}
	return (0);
	
}
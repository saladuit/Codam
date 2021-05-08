/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   functionpointer.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: saladin <saladin@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/21 14:53:40 by saladin       #+#    #+#                 */
/*   Updated: 2021/01/21 15:18:32 by saladin       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>


void	printn(int n)
{
	while (n != 0 || n > 0 || n)
	{
		write(1, "Hello\n", 6);
		n--;
	}
	return ;
}

int		main(void)
{
	void (*function)(int);
	
	function = &printn;
	function(5);
	return (0);
}
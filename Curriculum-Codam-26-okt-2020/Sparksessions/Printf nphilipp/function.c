/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   function.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: saladin <saladin@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/21 14:27:31 by saladin       #+#    #+#                 */
/*   Updated: 2021/01/21 14:48:18 by saladin       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>

// Write a variadic function that:
// has a prototype of function(const int n, ...) n being the number
// of arguments in the list,
// returns the sum of the integers in that list.
// Write the accompanying main to test your function. Example test: does
// yourfunction(3, 40, 5, -3) return 42 ?

int		function(const int n, ...)
{
	va_list	inputsum;
	int		result;
	int		i;

	i = 0;
	result = 0;
	va_start(inputsum, n);
	while (n > i)
	{
		result += va_arg(inputsum, int);
		i++;
	}
	va_end(inputsum);
	return (result);
}

int		main(void)
{
	int	result;

	result = function(3, 40, 5, -3);
	printf("result: %d\n", result);
	return (0);
}
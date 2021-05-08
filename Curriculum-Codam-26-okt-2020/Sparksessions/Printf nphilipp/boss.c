/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   boss.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: saladin <saladin@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/21 15:21:36 by saladin       #+#    #+#                 */
/*   Updated: 2021/01/21 15:40:43 by saladin       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

enum	e_op
{
PLUS = 0, MINUS
};

void	operation_add(int a, int b)
{
printf("%d + %d = %d\n", a, b, a + b);
}

void	operation_minus(int a, int b)
{
printf("%d - %d = %d\n", a, b, a - b);
}

int		main(void)
{
	void 	(*function[2])(int, int);

	function[PLUS] = &operation_add;
	function[MINUS] = &operation_minus;

	function[PLUS](36, 6);
	function[MINUS](50, 8);
}
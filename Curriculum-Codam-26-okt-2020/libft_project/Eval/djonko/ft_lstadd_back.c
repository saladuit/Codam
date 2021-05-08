/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstadd_back.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: djonker <marvin@codam.nl>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/13 18:48:54 by djonker       #+#    #+#                 */
/*   Updated: 2021/02/13 22:43:28 by djonker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*l;

	if (lst)
	{
		if (*lst)
		{
			l = ft_lstlast(*lst);
			l->next = new;
		}
		else
			*lst = new;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstdelone.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: djonker <marvin@codam.nl>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/13 19:06:46 by djonker       #+#    #+#                 */
/*   Updated: 2021/03/16 17:45:14 by djonker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	if (!del)
	{
		free (lst);
		return ;
	}
	if (lst)
	{
		(*del)(lst->content);
		free(lst);
	}
}

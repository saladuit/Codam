/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstclear.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: djonker <marvin@codam.nl>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/13 19:12:41 by djonker       #+#    #+#                 */
/*   Updated: 2021/03/30 12:51:41 by djonker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*t;
	int		i;

	i = 0;
	t = NULL;
	if (!del)
	{
		while (t->next != NULL)
		{
			free(lst[i]);
			i++;
		}
		free(t);
	}
	if (!del || !lst || !*lst)
		return ;
	while (lst && *lst)
	{
		t = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = t;
	}
}

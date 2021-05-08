/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstmap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: djonker <marvin@codam.nl>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/13 19:30:13 by djonker       #+#    #+#                 */
/*   Updated: 2021/04/04 10:48:48 by djonker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	void			*s;
	t_list			*r;
	t_list			*t;

	r = NULL;
	t = NULL;
	while (lst)
	{
		if (f(lst->content))
		{
			s = f(lst->content);
			t = ft_lstnew(s);
			if (!(t))
			{
				ft_lstclear(&r, del);
				lst = NULL;
				return (NULL);
			}
			ft_lstadd_back(&r, t);
		}
		lst = lst->next;
	}
	return (r);
}

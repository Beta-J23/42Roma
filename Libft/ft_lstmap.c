/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpelliz <alpelliz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 12:45:33 by alpelliz          #+#    #+#             */
/*   Updated: 2022/05/05 12:55:20 by alpelliz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*first;
	t_list	*new_element;

	first = 0;
	while (lst)
	{
		new_element = ft_lstnew((*f)(lst->content));
		if (!new_element)
		{
			while (first)
			{
				new_element = first->next;
				(*del)(first->content);
				free(first);
				first = new_element;
			}
			lst = 0;
			return (0);
		}
		ft_lstadd_back(&first, new_element);
		lst = lst->next;
	}
	return (first);
}

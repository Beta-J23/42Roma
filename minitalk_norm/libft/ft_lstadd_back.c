/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpelliz <alpelliz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 13:23:14 by alpelliz          #+#    #+#             */
/*   Updated: 2022/05/05 13:08:31 by alpelliz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*var;

	if (!lst)
		return ;
	if (*lst)
	{
		var = *lst;
		while (var->next)
			var = var->next;
		var->next = new;
	}
	else
		*lst = new;
}

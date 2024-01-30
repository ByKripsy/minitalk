/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouchet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 17:47:55 by mbouchet          #+#    #+#             */
/*   Updated: 2023/11/07 18:35:34 by mbouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*last;
	void	*content;

	new = 0;
	last = 0;
	content = 0;
	if (lst == 0 || f == 0 || del == 0)
		return (0);
	while (lst != 0)
	{
		content = f(lst->content);
		if (new == 0)
		{
			new = ft_lstnew(content);
			last = new;
		}
		else
		{
			last->next = ft_lstnew(content);
			last = last->next;
		}
		lst = lst->next;
	}
	return (new);
}

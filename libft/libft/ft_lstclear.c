/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouchet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 16:52:53 by mbouchet          #+#    #+#             */
/*   Updated: 2023/11/07 17:36:42 by mbouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*next;

	next = 0;
	if (lst == 0 || del == 0)
		return ;
	while ((*lst) != 0)
	{
		next = (*lst);
		del(next->content);
		(*lst) = (*lst)->next;
		free(next);
	}
	*lst = NULL;
}

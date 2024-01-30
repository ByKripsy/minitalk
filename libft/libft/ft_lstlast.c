/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouchet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 18:24:50 by mbouchet          #+#    #+#             */
/*   Updated: 2023/11/07 13:53:25 by mbouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*last;

	last = 0;
	if (lst == 0)
		return (0);
	last = lst;
	while (last->next != 0)
		last = last->next;
	return (last);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouchet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 18:21:40 by mbouchet          #+#    #+#             */
/*   Updated: 2023/11/06 18:40:29 by mbouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../libft.h"

int	ft_lstsize(t_list *lst)
{
	int		nb;
	t_list	*l;

	nb = 1;
	l = 0;
	if (lst == 0)
		return (0);
	l = lst;
	while (l->next != 0)
	{
		l = l->next;
		nb++;
	}
	return (nb);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouchet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 18:06:36 by mbouchet          #+#    #+#             */
/*   Updated: 2023/11/06 18:10:46 by mbouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*nlst;

	nlst = malloc(sizeof(t_list));
	if (nlst == 0)
		return (0);
	nlst->content = content;
	nlst->next = 0;
	return (nlst);
}

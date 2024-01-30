/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouchet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 15:15:22 by mbouchet          #+#    #+#             */
/*   Updated: 2023/11/08 13:19:57 by mbouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;
	int		nb;
	int		s;

	nb = (int) nmemb;
	s = (int) size;
	if (nb == 0 || s == 0)
		return (malloc(0));
	if (nb < 0 || s < 0)
		return (0);
	ptr = malloc(size * nmemb);
	if (ptr == 0)
		return (0);
	ft_bzero(ptr, size * nmemb);
	return (ptr);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brappo <brappo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 15:24:09 by brappo            #+#    #+#             */
/*   Updated: 2023/11/09 11:11:01 by brappo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	char			*cast;
	unsigned long	i;

	i = 0;
	cast = (char *)s;
	while (i < n)
	{
		cast[i] = c;
		i++;
	}
	return (s);
}

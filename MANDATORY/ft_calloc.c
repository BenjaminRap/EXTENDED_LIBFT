/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brappo <brappo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 10:07:31 by brappo            #+#    #+#             */
/*   Updated: 2023/11/10 11:15:09 by brappo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*result;
	size_t	i;
	size_t	new_size;

	i = 0;
	new_size = nmemb * size;
	if (nmemb == 0 || size == 0)
		return (malloc(0));
	if (nmemb > 2147483647 || size > 2147483647)
		return (NULL);
	result = (char *)malloc(new_size);
	if (result == NULL)
		return (NULL);
	while (i < new_size)
	{
		result[i] = '\0';
		i++;
	}
	return (result);
}

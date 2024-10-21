/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brappo <brappo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 10:56:52 by brappo            #+#    #+#             */
/*   Updated: 2024/01/21 19:03:05 by brappo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		len_s1;
	int		len_s2;
	char	*result;
	int		i;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	len_s1 = ft_strlen((char *)s1);
	len_s2 = ft_strlen((char *)s2);
	i = 0;
	result = (char *)malloc((len_s1 + len_s2 + 1) * sizeof(char));
	if (result == NULL)
		return (NULL);
	while (i <= len_s1)
	{
		result[i] = s1[i];
		i++;
	}
	i = 0;
	while (i <= len_s2)
	{
		result[len_s1 + i] = s2[i];
		i++;
	}
	return (result);
}

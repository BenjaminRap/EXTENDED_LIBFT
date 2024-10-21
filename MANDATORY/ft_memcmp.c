/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brappo <brappo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 09:25:48 by brappo            #+#    #+#             */
/*   Updated: 2023/11/10 15:08:42 by brappo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	recur(unsigned char *s1, unsigned char *s2, size_t n)
{
	if (n == 0)
		return (0);
	if (*s1 != *s2)
		return (*s1 - *s2);
	else
		return (recur(s1 + 1, s2 + 1, n - 1));
}

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	return (recur((unsigned char *)s1, (unsigned char *)s2, n));
}

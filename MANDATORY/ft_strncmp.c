/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brappo <brappo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 17:09:01 by brappo            #+#    #+#             */
/*   Updated: 2023/11/10 15:12:36 by brappo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	if (n == 0)
		return (0);
	if (*s1 != *s2 || *s1 == '\0')
		return ((unsigned char)*s1 - (unsigned char)*s2);
	else
		return (ft_strncmp(s1 + 1, s2 + 1, n - 1));
}

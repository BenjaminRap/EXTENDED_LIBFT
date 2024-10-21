/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_in_set.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brappo <brappo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 14:25:48 by brappo            #+#    #+#             */
/*   Updated: 2023/11/15 09:06:26 by brappo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_is_in_set(char c, char *set)
{
	int	length;
	int	i;

	i = 0;
	length = ft_strlen(set);
	while (i < length)
	{
		if (set[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

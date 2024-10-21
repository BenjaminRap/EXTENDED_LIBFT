/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brappo <brappo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 15:09:47 by brappo            #+#    #+#             */
/*   Updated: 2023/11/09 11:06:31 by brappo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	if (c >= 'a' && c <= 'z')
		return (8);
	if (c >= 'A' && c <= 'Z')
		return (8);
	if (c >= '0' && c <= '9')
		return (8);
	return (0);
}

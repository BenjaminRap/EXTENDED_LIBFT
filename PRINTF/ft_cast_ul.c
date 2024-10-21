/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cast_ul.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brappo <brappo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 14:02:57 by brappo            #+#    #+#             */
/*   Updated: 2024/01/19 18:29:12 by brappo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned int	ft_cast_ul(unsigned int n)
{
	unsigned int	result;

	if (n >= 4294967295)
		result = 4294967295;
	else
		result = n;
	return (result);
}

unsigned long	ft_cast_pointer(long n)
{
	unsigned long	result;

	if (n < -2147483648)
		result = 4294967294 - n;
	result = n;
	return (result);
}

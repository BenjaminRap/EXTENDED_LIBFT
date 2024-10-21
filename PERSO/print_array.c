/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_array.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brappo <brappo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 18:55:27 by brappo            #+#    #+#             */
/*   Updated: 2024/01/25 11:32:04 by brappo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

void	print_array(void **array, size_t length, char *str)
{
	size_t	index;

	index = 0;
	while (index < length)
	{
		ft_printf(str, array[index]);
		index++;
	}
}

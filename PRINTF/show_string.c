/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_string.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brappo <brappo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 19:11:01 by brappo            #+#    #+#             */
/*   Updated: 2024/01/19 20:15:02 by brappo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	show_string(char *str, long *length)
{
	int	result;

	if (str == NULL)
		*length = -1;
	result = write(1, str, *length);
	if (result < 0)
		*length = -1;
	free(str);
}

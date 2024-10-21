/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brappo <brappo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 20:43:56 by brappo            #+#    #+#             */
/*   Updated: 2024/01/20 19:10:41 by brappo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*to_list(void **array, int length)
{
	int		index;
	t_list	*lst;

	index = 0;
	while (index < length)
	{
		if (!add_node(&lst, array[index]))
		{
			free_list(lst, NULL);
			return (NULL);
		}
		index++;
	}
	return (lst);
}

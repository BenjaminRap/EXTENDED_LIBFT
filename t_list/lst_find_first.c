/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_find_first.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brappo <brappo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 09:47:57 by brappo            #+#    #+#             */
/*   Updated: 2024/01/20 19:10:16 by brappo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	lst_find_first(t_list *list, void *value, int (*f)(void *, void*))
{
	int		index;
	t_node	*current;

	index = 0;
	current = list->node;
	while (index < list->length)
	{
		if (f(value, current->value))
			return (index);
		current = current->next;
		index++;
	}
	return (-1);
}

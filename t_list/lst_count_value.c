/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_count_value.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brappo <brappo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 09:27:48 by brappo            #+#    #+#             */
/*   Updated: 2024/01/20 19:10:06 by brappo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	lst_count_value(t_list *list, void *value, int (*f)(void *, void *))
{
	int		count;
	int		index;
	t_node	*current;

	count = 0;
	index = 0;
	if (list == NULL)
		return (0);
	current = list->node;
	while (index < list->length)
	{
		if (f(current->value, value))
			count++;
		current = current->next;
		index++;
	}
	return (count);
}

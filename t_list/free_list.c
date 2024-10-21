/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brappo <brappo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 17:54:48 by brappo            #+#    #+#             */
/*   Updated: 2024/01/20 19:10:02 by brappo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	free_list(t_list *list, void (*free_value)(void *))
{
	int		index;
	t_node	*next;

	index = 0;
	if (list == NULL)
		return ;
	while (index < list->length)
	{
		next = list->node->next;
		if (free_value)
			free_value(list->node->value);
		free(list->node);
		list->node = next;
		index++;
	}
	free(list);
}

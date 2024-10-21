/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_remove_at.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brappo <brappo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 21:36:18 by brappo            #+#    #+#             */
/*   Updated: 2024/01/20 19:10:27 by brappo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	remove_head(t_list *lst, void (*free_value)(void *))
{
	t_node	*head;

	head = lst->node;
	lst->node = lst->node->next;
	if (free_value)
		free_value(head->value);
	free(head);
}

void	lst_remove_at(t_list *lst, int index, void (*free_value)(void *))
{
	t_node	*previous;
	t_node	*node;

	if (index < 0 || index >= lst->length)
		return ;
	if (!index)
		remove_head(lst, free_value);
	else
	{
		previous = lst_element_at(lst, index - 1);
		node = previous->next;
		previous->next = node->next;
		if (free_value)
			free_value(node->value);
		free(node);
	}
	lst->length--;
}

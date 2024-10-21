/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_insert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brappo <brappo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 09:51:16 by brappo            #+#    #+#             */
/*   Updated: 2024/01/20 19:10:22 by brappo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_node	*insert(t_list **list, int index, void *value)
{
	t_node	*new;
	t_node	*previous;

	if (!list || !*list || index > (*list)->length)
		return (NULL);
	if (!index)
		return (add_node(list, value));
	new = create_node(value);
	if (new == NULL)
		return (NULL);
	previous = lst_element_at(*list, index - 1);
	new->next = previous->next;
	previous->next = new;
	(*list)->length++;
	return (new);
}

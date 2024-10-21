/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_element_at.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brappo <brappo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 21:51:28 by brappo            #+#    #+#             */
/*   Updated: 2024/01/20 19:10:09 by brappo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_node	*lst_element_at(t_list *lst, int index)
{
	int		i;
	t_node	*current;

	i = 0;
	if (lst == NULL)
		return (NULL);
	if (index >= lst->length)
		return (NULL);
	current = lst->node;
	while (i < index)
	{
		current = current->next;
		i++;
	}
	return (current);
}

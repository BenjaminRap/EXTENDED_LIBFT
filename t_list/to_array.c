/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_array.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brappo <brappo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 18:47:17 by brappo            #+#    #+#             */
/*   Updated: 2024/01/23 11:46:08 by brappo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*to_array(t_list *list)
{
	int		index;
	void	**array;
	t_node	*current;

	index = 0;
	if (list == NULL)
		return (NULL);
	current = list->node;
	array = (void **)malloc(list->length * sizeof(void *));
	if (array == NULL)
		return (NULL);
	while (index < list->length)
	{
		array[index] = current->value;
		current = current->next;
		index++;
	}
	return (array);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_find_all.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brappo <brappo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 09:33:08 by brappo            #+#    #+#             */
/*   Updated: 2024/01/20 19:11:08 by brappo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	*lst_find_all(t_list *list, void *value, int *count,
		int (*f)(void *, void *))
{
	int		*result;
	int		index;
	t_node	*current;
	int		result_index;

	index = 0;
	result_index = 0;
	if (list == NULL)
		return (NULL);
	*count = lst_count_value(list, value, f);
	if (!count)
		return (NULL);
	result = (int *)malloc(*count * sizeof(int));
	if (result == NULL)
		return (NULL);
	current = list->node;
	while (index < list->length)
	{
		if (f(current->value, value))
			result[result_index++] = index;
		current = current->next;
		index++;
	}
	return (result);
}

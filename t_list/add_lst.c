/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_lst.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brappo <brappo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 10:08:34 by brappo            #+#    #+#             */
/*   Updated: 2024/01/20 19:10:55 by brappo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	add_lst(t_list *start, t_list *end)
{
	t_node	*last;

	if (!start || !end)
		return ;
	last = lst_element_at(start, start->length);
	last->next = end->node;
	start->length += end->length;
	lst_get_last(start)->next = start->node;
	free(end);
}

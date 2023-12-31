/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_list_operations_1.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Philip <juli@student.42london.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 17:31:20 by Philip            #+#    #+#             */
/*   Updated: 2024/01/04 17:43:33 by Philip           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	list_free(t_cdl_list **top)
{
	t_cdl_list	*node;

	if (!top || !(*top))
		return ;
	if (list_len(*top) == 1)
		free(*top);
	else
	{
		node = (*top)->next;
		while (node && node->next != *top)
		{
			free(node->prev);
			node = node->next;
		}
		free(node->prev);
		free(node);
	}
	*top = NULL;
}

/* Returns the minium value stored in the list. */
int	list_min(t_cdl_list *top)
{
	int			min;
	t_cdl_list	*node;

	if (!top)
		return (0);
	if (list_len(top) == 1)
		return (top->value);
	min = top->value;
	node = top->next;
	while (node != top)
	{
		if (node->value < min)
			min = node->value;
		node = node->next;
	}
	return (min);
}

/* Returns the maximum value stored in the list. */
int	list_max(t_cdl_list *top)
{
	int			max;
	t_cdl_list	*node;

	if (!top)
		return (0);
	if (list_len(top) == 1)
		return (top->value);
	max = top->value;
	node = top->next;
	while (node != top)
	{
		if (node->value > max)
			max = node->value;
		node = node->next;
	}
	return (max);
}

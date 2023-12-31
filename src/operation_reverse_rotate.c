/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_reverse_rotate.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Philip <juli@student.42london.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 00:25:39 by Philip Li         #+#    #+#             */
/*   Updated: 2024/01/04 16:19:27 by Philip           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	try_revserse_rotate(t_cdl_list **top);

/* rra (reverse rotate a): Shift down all elements of stack a by 1.
   The last element becomes the first one.*/
void	rra(t_cdl_list **top_a, t_print p)
{
	if (!top_a || !(*top_a) || list_len(*top_a) < 2)
		return ;
	if (p == PRINT)
		ft_putendl_fd("rra", STDOUT_FILENO);
	*top_a = (*top_a)->prev;
}

/* rrb (reverse rotate b): Shift down all elements of stack b by 1.
   The last element becomes the first one. */
void	rrb(t_cdl_list **top_b, t_print p)
{
	if (!top_b || !(*top_b) || list_len(*top_b) < 2)
		return ;
	if (p == PRINT)
		ft_putendl_fd("rrb", STDOUT_FILENO);
	*top_b = (*top_b)->prev;
}

/* rrr : rra and rrb at the same time. */
void	rrr(t_cdl_list **top_a, t_cdl_list **top_b, t_print p)
{
	if (p == PRINT)
		ft_putendl_fd("rrr", STDOUT_FILENO);
	try_revserse_rotate(top_a);
	try_revserse_rotate(top_b);
}

static void	try_revserse_rotate(t_cdl_list **top)
{
	if (!top || !(*top))
		return ;
	if (list_len(*top) > 1)
		*top = (*top)->prev;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvavryn <dvavryn@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 14:23:12 by dvavryn           #+#    #+#             */
/*   Updated: 2025/06/24 01:05:15 by dvavryn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	isolate_node(t_data **buf);

void	swap(t_data **stack)
{
	t_data	*buf;

	if ((*stack)->next == NULL)
		return ;
	buf = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	if ((*stack)->next != NULL)
		(*stack)->next->prev = buf;
	buf->prev = (*stack);
	if ((*stack)->next)
		buf->next = (*stack)->next;
	else
		buf->next = NULL;
	(*stack)->next = buf;
}

void	push(t_data **stack_a, t_data **stack_b)
{
	t_data	*ptr;

	if (!*stack_a)
		return ;
	ptr = *stack_a;
	if ((*stack_a)->next)
	{
		*stack_a = (*stack_a)->next;
		(*stack_a)->prev = NULL;
	}
	else
		*stack_a = NULL;
	isolate_node(&ptr);
	if (!*stack_b)
		*stack_b = ptr;
	else
	{
		ptr->next = *stack_b;
		(*stack_b)->prev = ptr;
		*stack_b = ptr;
	}
}

void	rotate(t_data **stack)
{
	t_data	*ptr;

	if (!(*stack) || !(*stack)->next)
		return ;
	ptr = *stack;
	while (ptr->next)
		ptr = ptr->next;
	ptr->next = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	ptr->next->prev = ptr;
	ptr->next->next = NULL;
}

void	revrotate(t_data **stack)
{
	t_data	*ptr;

	if (!(*stack) || !(*stack)->next)
		return ;
	ptr = *stack;
	while (ptr->next)
		ptr = ptr->next;
	ptr->prev->next = NULL;
	ptr->prev = NULL;
	ptr->next = *stack;
	(*stack)->prev = ptr;
	*stack = (*stack)->prev;
}

static void	isolate_node(t_data **buf)
{
	t_data	*ptr;

	ptr = *buf;
	ptr->prev = NULL;
	ptr->next = NULL;
}

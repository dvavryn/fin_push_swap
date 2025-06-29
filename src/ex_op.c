/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvavryn <dvavryn@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 14:53:14 by dvavryn           #+#    #+#             */
/*   Updated: 2025/06/29 02:15:31 by dvavryn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	swap_(char c, t_data **stack_a, t_data **stack_b)
{
	if (c == 'a' && *stack_a)
	{
		if (!(*stack_a)->next)
			return ;
		swap(stack_a);
		ft_printf("sa\n");
	}
	else if (c == 'b' && *stack_b)
	{
		if (!(*stack_b)->next)
			return ;
		swap(stack_b);
		ft_printf("sb\n");
	}
	else if (c == 's' && *stack_a && *stack_b)
	{
		if (!(*stack_a)->next || !(*stack_b)->next)
			return ;
		swap(stack_a);
		swap(stack_b);
		ft_printf("ss\n");
	}
}

void	push_(char c, t_data **stack_a, t_data **stack_b)
{
	if (c == 'a' && *stack_b)
	{
		push(stack_b, stack_a);
		ft_printf("pa\n");
	}
	else if (c == 'b' && *stack_a)
	{
		push(stack_a, stack_b);
		ft_printf("pb\n");
	}
}

void	rotate_(char c, t_data **stack_a, t_data **stack_b)
{
	if (c == 'a' && *stack_a)
	{
		if (!(*stack_a)->next)
			return ;
		rotate(stack_a);
		ft_printf("ra\n");
	}
	else if (c == 'b' && *stack_b)
	{
		if (!(*stack_b)->next)
			return ;
		rotate(stack_b);
		ft_printf("rb\n");
	}
	else if (c == 'r' && *stack_a && *stack_b)
	{
		if (!(*stack_a)->next || !(*stack_b)->next)
			return ;
		rotate(stack_a);
		rotate(stack_b);
		ft_printf("rr\n");
	}
}

void	rrotate_(char c, t_data **stack_a, t_data **stack_b)
{
	if (c == 'a' && *stack_a)
	{
		if (!(*stack_a)->next)
			return ;
		revrotate(stack_a);
		ft_printf("rra\n");
	}
	else if (c == 'b' && *stack_b)
	{
		if (!(*stack_b)->next)
			return ;
		revrotate(stack_b);
		ft_printf("rrb\n");
	}
	else if (c == 'r' && *stack_a && *stack_b)
	{
		if (!(*stack_a) || !(*stack_b))
			return ;
		revrotate(stack_a);
		revrotate(stack_b);
		ft_printf("rr\n");
	}
}

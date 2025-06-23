/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvavryn <dvavryn@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 12:02:11 by dvavryn           #+#    #+#             */
/*   Updated: 2025/06/24 01:06:48 by dvavryn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

size_t	get_size(t_data *stack)
{
	size_t	i;

	if (!stack)
		return (0);
	i = 1;
	while (stack->next)
	{
		i++;
		stack = stack->next;
	}
	return (i);
}

int	hardcode_sort_three(t_data **stack_a)
{
	int	a;
	int	b;
	int	c;

	a = (*stack_a)->value;
	b = (*stack_a)->next->value;
	if (get_size(*stack_a) == 2 && a > b)
		return (swap_('a', stack_a, NULL), 0);
	c = (*stack_a)->next->next->value;
	if (a < b && b < c)
		return (0);
	else if (a < b && b > c && a < c)
		return (rrotate_('a', stack_a, NULL), swap_('a', stack_a, NULL), 0);
	else if (a > b && b < c && a < c)
		return (swap_('a', stack_a, NULL), 0);
	else if (a < b && b > c && a > c)
		return (rrotate_('a', stack_a, NULL), 0);
	else if (a > b && b < c && a > c)
		return (rotate_('a', stack_a, NULL), 0);
	else if (a > b && b > c)
		return (swap_('a', stack_a, NULL), rrotate_('a', stack_a, NULL), 0);
	return (1);
}

void	hardcode_sort_two(t_data **stack_a)
{
	if ((*stack_a)->value > (*stack_a)->next->value)
		swap_('a', stack_a, NULL);
}

void	bubble_sort(int *arr, size_t n)
{
	size_t	i;
	size_t	j;
	int		tmp;

	i = 0;
	while (i < n)
	{
		j = 0;
		while (j < n - i - 1)
		{
			if (arr[j] > arr[j + 1])
			{
				tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
}

int	issorted(t_data *a)
{
	t_data	*curr;

	if (!a)
		return (0);
	curr = a;
	while (curr->next)
	{
		if (curr->value > curr->next->value)
			return (0);
		curr = curr->next;
	}
	return (1);
}

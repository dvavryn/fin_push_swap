/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvavryn <dvavryn@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 22:02:09 by dvavryn           #+#    #+#             */
/*   Updated: 2025/06/24 01:05:19 by dvavryn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	assign_normalized_values(t_data *stack, int *sorted_values,
	size_t size)
{
	t_data	*node;
	size_t	i;

	node = stack;
	while (node)
	{
		i = 0;
		while (i < size)
		{
			if (sorted_values[i] == node->value)
			{
				node->value = (int)i;
				break ;
			}
			i++;
		}
		node = node->next;
	}
}

void	normalize_stack(t_data *stack, size_t size)
{
	int		*values;
	t_data	*node;
	size_t	i;

	values = malloc(size * sizeof(int));
	if (!values)
		error_exit();
	node = stack;
	i = 0;
	while (node)
	{
		values[i++] = node->value;
		node = node->next;
	}
	bubble_sort(values, size);
	assign_normalized_values(stack, values, size);
	free(values);
}

static size_t	count_bits(int num)
{
	size_t	bits;

	bits = 0;
	while (num)
	{
		bits++;
		num >>= 1;
	}
	return (bits);
}

static void	radix_sort_stack(t_data **a, t_data **b, size_t size)
{
	size_t	max_bits;
	size_t	bit;
	size_t	count;

	max_bits = count_bits(size - 1);
	bit = 0;
	while (bit < max_bits && !issorted(*a))
	{
		count = 0;
		while (count < size)
		{
			if (((*a)->value >> bit) & 1)
				rotate_('a', a, b);
			else
				push_('b', a, b);
			count++;
		}
		while (*b)
			push_('a', a, b);
		bit++;
	}
}

void	sort(t_data *a)
{
	t_data	*b;
	size_t	size;

	b = NULL;
	size = get_size(a);
	if (size <= 1 || issorted(a))
		return ;
	if (size == 2)
		hardcode_sort_two(&a);
	else if (size == 3)
		hardcode_sort_three(&a);
	else
	{
		normalize_stack(a, size);
		radix_sort_stack(&a, &b, size);
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvavryn <dvavryn@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 00:16:11 by dvavryn           #+#    #+#             */
/*   Updated: 2025/06/29 02:32:35 by dvavryn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	free_arr(char **arr)
{
	size_t	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
	arr = NULL;
}

void	free_data(t_data **top)
{
	t_data	*cur;
	t_data	*next;

	if (!top || !*top)
		return ;
	cur = *top;
	while (cur)
	{
		next = cur->next;
		if (next)
			next->prev = NULL;
		free(cur);
		cur = next;
	}
	*top = NULL;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvavryn <dvavryn@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 00:13:52 by dvavryn           #+#    #+#             */
/*   Updated: 2025/06/24 01:18:24 by dvavryn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int	errorcheck_sub1(char **arr);
static int	errorcheck_sub2(char **arr);

void	error_exit(void)
{
	write(2, "ERROR\n", 6);
	exit(1);
}

void	errorcheck(int argc, char **arr)
{
	if (errorcheck_sub1(arr) || errorcheck_sub2(arr))
	{
		if (argc == 2)
			free_arr(arr);
		error_exit();
	}
}

static int	errorcheck_sub1(char **arr)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (arr[i])
	{
		j = 0;
		if (arr[i][0] == '-' || arr[i][0] == '+')
			j++;
		while (arr[i][j])
		{
			if (!ft_isdigit(arr[i][j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

static int	errorcheck_sub2(char **arr)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (arr[i])
	{
		if (ft_atol(arr[i]) > INT_MAX || ft_atol(arr[i]) < INT_MIN)
			return (1);
		j = 0;
		while (arr[j])
		{
			if (i != j && ft_atol(arr[i]) == ft_atol(arr[j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_stack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvavryn <dvavryn@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 14:49:57 by dvavryn           #+#    #+#             */
/*   Updated: 2025/06/29 02:40:32 by dvavryn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static char		**ps_split(char *arg);
static t_data	*convert(int argc, char **arr);
static bool		init_stack(t_data **head, char *s);
static bool		append(t_data **ptr, char *s);

t_data	*get_stack(int argc, char **argv)
{
	char	**arr;
	t_data	*out;

	arr = NULL;
	if (argc < 2)
		error_exit();
	if (argc == 2)
	{
		if (argv[1][0] == 0 || isempty(argv[1]) || argv[1][1] == 0)
			error_exit();
		arr = ps_split(argv[1]);
	}
	else
		arr = argv + 1;
	errorcheck(argc, arr);
	out = convert(argc, arr);
	if (!out)
		return (NULL);
	return (out);
}

static t_data	*convert(int argc, char **arr)
{
	t_data	*out;
	t_data	*ptr;
	size_t	i;

	if (!init_stack(&out, arr[0]))
	{
		if (argc == 2)
			free_arr(arr);
		error_exit();
	}
	ptr = out;
	i = 0;
	while (arr[++i])
	{
		if (!append(&ptr, arr[i]))
		{
			free_data(&out);
			if (argc == 2)
				free_arr(arr);
			error_exit();
		}
	}
	if (argc == 2)
		free_arr(arr);
	return (out);
}

static bool	append(t_data **ptr, char *s)
{
	t_data		*node;
	static int	i = 1;

	node = malloc(sizeof(t_data));
	if (!node)
		return (false);
	node->index = i;
	node->value = ft_atoi(s);
	node->prev = *ptr;
	node->next = NULL;
	(*ptr)->next = node;
	*ptr = node;
	i++;
	return (true);
}

static bool	init_stack(t_data **head, char *s)
{
	t_data	*node;

	node = malloc(sizeof(t_data));
	if (!node)
		return (false);
	node->index = 0;
	node->value = ft_atoi(s);
	node->prev = NULL;
	node->next = NULL;
	*head = node;
	return (true);
}

static char	**ps_split(char *arg)
{
	char	**out;

	out = ft_split(arg, ' ');
	if (!out)
		error_exit();
	return (out);
}

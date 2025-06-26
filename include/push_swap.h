/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvavryn <dvavryn@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 13:26:05 by dvavryn           #+#    #+#             */
/*   Updated: 2025/06/26 19:17:43 by dvavryn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include "../libft/libft.h"
# include <limits.h>
# include <stdbool.h>

typedef struct s_data
{
	struct s_data	*prev;
	int				value;
	int				index;
	struct s_data	*next;
}	t_data;

void	errorcheck(int argc, char **args);
void	error_exit(void);
void	free_arr(char **arr);
void	free_data(t_data *top);
int		issorted(t_data *a);
void	sort(t_data *a);
t_data	*get_stack(int argc, char **argv);
void	swap(t_data **stack);
void	push(t_data **stack_a, t_data **stack_b);
void	rotate(t_data **stack);
void	revrotate(t_data **stack);
void	swap_(char c, t_data **stack_a, t_data **stack_b);
void	push_(char c, t_data **stack_a, t_data **stack_b);
void	rotate_(char c, t_data **stack_a, t_data **stack_b);
void	rrotate_(char c, t_data **stack_a, t_data **stack_b);
size_t	get_size(t_data *stack);
int		hardcode_sort_three(t_data **stack_a);
void	hardcode_sort_two(t_data **stack_a);
void	bubble_sort(int *arr, size_t n);
int		isempty(char *arg);

#endif
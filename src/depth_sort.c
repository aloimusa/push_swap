/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   depth_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloimusa <aloimusa@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 18:28:17 by aloimusa          #+#    #+#             */
/*   Updated: 2025/07/07 18:44:09 by aloimusa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int		search(t_stack *stack, int depth_left, int *sol, int *sol_len);
static t_stack	*dup_stack(t_stack *src);

void	depth_sort(t_stack *stack)
{
	int	*sol;
	int	sol_len;
	int	i;

	sol = malloc(MAX_DEPTH * sizeof(int));
	if (!sol)
		return ;
	i = -1;
	while (++i <= MAX_DEPTH)
	{
		sol_len = 0;
		if (search(stack, i, sol, &sol_len))
		{
			i = 0;
			while (i < sol_len)
				op(stack, sol[i++]);
			while (stack->index > 0)
				op(stack, pa);
			free(sol);
			return ;
		}
	}
	free(sol);
}

static int	search(t_stack *stack, int depth_left, int *sol, int *sol_len)
{
	int		i;
	t_stack	*attempt;

	if (is_sorted(stack))
		return (1);
	if (depth_left <= 0)
		return (0);
	i = -1;
	while (++i < 11)
	{
		attempt = dup_stack(stack);
		if (!attempt)
			return (0);
		op1(attempt, sa + i);
		if (search(attempt, depth_left - 1, sol + 1, sol_len))
		{
			sol[0] = sa + i;
			(*sol_len)++;
			free_stack(attempt);
			return (1);
		}
		free_stack(attempt);
	}
	return (0);
}

static t_stack	*dup_stack(t_stack *src)
{
	t_stack	*dup;
	int		i;

	dup = malloc(sizeof(t_stack));
	if (!dup)
		return (NULL);
	dup->array = malloc(src->size * sizeof(unsigned int));
	if (!(dup->array))
	{
		free(dup);
		return (NULL);
	}
	dup->size = src->size;
	dup->index = src->index;
	i = -1;
	while (++i < src->size)
		dup->array[i] = src->array[i];
	return (dup);
}

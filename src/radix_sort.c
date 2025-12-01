/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloimusa <aloimusa@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 20:04:44 by aloimusa          #+#    #+#             */
/*   Updated: 2025/07/07 20:11:26 by aloimusa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push_a(t_stack *stack, int size, int bit);
static void	push_b(t_stack *stack, int size, int bit);

void	radix_sort(t_stack *stack)
{
	int	max_bit;
	int	bit;
	int	size[2];

	max_bit = 0;
	while ((stack->size - 1) >> max_bit)
		max_bit++;
	bit = 0;
	while (bit < max_bit)
	{
		size[a] = stack->size - stack->index;
		push_b(stack, size[a], bit++);
		size[b] = stack->index;
		if (bit != max_bit)
			push_a(stack, size[b], bit);
	}
	while (stack->index > 0)
		op(stack, pa);
}

static void	push_b(t_stack *stack, int size, int bit)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (is_sorted(stack))
			break ;
		if (((stack->array[stack->index] >> bit) & 1) == 0)
			op(stack, pb);
		else
		{
			op(stack, ra);
		}
		i++;
	}
}

static void	push_a(t_stack *stack, int size, int bit)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (is_sorted(stack))
			break ;
		if (((stack->array[stack->index - 1] >> bit) & 1) == 1)
			op(stack, pa);
		else
		{
			op(stack, rb);
		}
		i++;
	}
}

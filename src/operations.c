/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloimusa <aloimusa@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 17:16:00 by aloimusa          #+#    #+#             */
/*   Updated: 2025/07/02 17:17:11 by aloimusa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	op2(t_stack *stack, int o);
static void	rotate(t_stack *stack, int s, int dir);
static void	swap(unsigned int *a, unsigned int *b);

void	op(t_stack *stack, int o)
{
	op1(stack, o);
	if (o == sa)
		write(1, "sa\n", 3);
	else if (o == sb)
		write(1, "sb\n", 3);
	else if (o == ss)
		write(1, "ss\n", 3);
	else if (o == pa)
		write(1, "pa\n", 3);
	else if (o == pb)
		write(1, "pb\n", 3);
	else if (o == ra)
		write(1, "ra\n", 3);
	else if (o == rb)
		write(1, "rb\n", 3);
	else if (o == rr)
		write(1, "rr\n", 3);
	else if (o == rra)
		write(1, "rra\n", 4);
	else if (o == rrb)
		write(1, "rrb\n", 4);
	else if (o == rrr)
		write(1, "rrr\n", 4);
}

int	op1(t_stack *stack, int o)
{
	if (o > pb)
	{
		op2(stack, o);
		return (0);
	}
	if (o == sa)
		if (stack->index < stack->size - 1)
			swap(&stack->array[stack->index], &stack->array[stack->index + 1]);
	if (o == sb)
		if (stack->index > 1)
			swap(&stack->array[stack->index - 1], &stack->array[stack->index
				- 2]);
	if (o == ss)
		if (op1(stack, sa))
			op1(stack, sb);
	if (o == pa)
		if (stack->index > 0)
			stack->index--;
	if (o == pb)
		if (stack->index < stack->size)
			stack->index++;
	return (0);
}

static int	op2(t_stack *stack, int o)
{
	if (o == ra)
		if (stack->index < stack->size - 1)
			rotate(stack, 'a', up);
	if (o == rb)
		if (stack->index > 1)
			rotate(stack, 'b', up);
	if (o == rr)
		if (op2(stack, ra))
			op2(stack, rb);
	if (o == rra)
		if (stack->index < stack->size - 1)
			rotate(stack, 'a', down);
	if (o == rrb)
		if (stack->index > 1)
			rotate(stack, 'b', down);
	if (o == rrr)
		if (op2(stack, rra))
			op2(stack, rrb);
	return (0);
}

static void	rotate(t_stack *stack, int s, int dir)
{
	int	top;
	int	pm;
	int	bottom;

	if (s == 'a')
	{
		bottom = stack->size - 1;
		top = stack->index;
		pm = 1;
	}
	else
	{
		bottom = 0;
		top = stack->index - 1;
		pm = -1;
	}
	while (bottom != top)
	{
		swap(&stack->array[bottom], &stack->array[top]);
		if (dir == up)
			bottom += dir * pm;
		else
			top += dir * pm;
	}
}

static void	swap(unsigned int *a, unsigned int *b)
{
	*a ^= *b;
	*b ^= *a;
	*a ^= *b;
}

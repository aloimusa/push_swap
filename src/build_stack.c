/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloimusa <aloimusa@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 17:17:54 by aloimusa          #+#    #+#             */
/*   Updated: 2025/07/02 17:17:54 by aloimusa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stack	*init_stack(int size);
static void		check_stack(t_stack *stack);
static void		normalize_stack(t_stack *stack);

t_stack	*build_stack(int size, char **av)
{
	int		arg;
	long	num;
	size_t	i;
	t_stack	*stack;

	stack = init_stack(size);
	arg = 0;
	while (arg < size)
	{
		i = 0;
		num = 0;
		if (av[arg][i] == '+' || av[arg][i] == '-')
			i++;
		while (av[arg][i] >= '0' && av[arg][i] <= '9' && i < 11)
			num = num * 10 + (av[arg][i++] - '0');
		if (num > (long)(INT_MAX) + (av[arg][0] == '-') || (num == 0
				&& av[arg][0] != '0') || av[arg][i])
			exit_error(stack);
		if (av[arg][0] == '-')
			stack->array[arg++] = (unsigned int)((long)(INT_MAX) + 1 - num);
		else
			stack->array[arg++] = (unsigned int)(num + (long)(INT_MAX) + 1);
	}
	check_stack(stack);
	return (stack);
}

static t_stack	*init_stack(int size)
{
	t_stack	*stack;

	if (size < 1)
		exit_error(NULL);
	stack = malloc(sizeof(t_stack));
	if (!stack)
		exit_error(stack);
	stack->array = malloc((size) * sizeof(unsigned int));
	if (!(stack->array))
		exit_error(stack);
	stack->size = size;
	stack->index = 0;
	return (stack);
}

static void	check_stack(t_stack *stack)
{
	int	i;
	int	j;

	i = 0;
	while (i < stack->size)
	{
		j = i;
		while (i > 0)
			if (stack->array[j] == stack->array[--i])
				exit_error(stack);
		i = j + 1;
	}
	normalize_stack(stack);
}

static void	normalize_stack(t_stack *stack)
{
	int				i;
	int				j;
	int				order;
	unsigned int	*tmp;

	tmp = malloc(stack->size * sizeof(unsigned int));
	if (!tmp)
		exit_error(stack);
	i = -1;
	while (++i < stack->size)
		tmp[i] = stack->array[i];
	i = -1;
	while (++i < stack->size)
	{
		order = 0;
		j = -1;
		while (++j < stack->size)
			if (tmp[i] > tmp[j])
				order++;
		stack->array[i] = order;
	}
	free(tmp);
}

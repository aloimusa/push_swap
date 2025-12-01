/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloimusa <aloimusa@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 16:38:04 by aloimusa          #+#    #+#             */
/*   Updated: 2025/07/09 16:38:14 by aloimusa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stack	*stack;

	stack = build_stack(ac - 1, &av[1]);
	if (!is_sorted(stack))
	{
		if (stack->size <= 5)
			depth_sort(stack);
		radix_sort(stack);
	}
	free_stack(stack);
	return (0);
}

int	is_sorted(t_stack *stack)
{
	unsigned int	i;

	i = 0;
	while (i < (unsigned int)stack->size)
	{
		if (stack->array[i] == i)
			i++;
		else
			return (0);
	}
	return (1);
}

void	free_stack(t_stack *stack)
{
	if (stack)
	{
		if (stack->array)
			free(stack->array);
		free(stack);
	}
}

void	exit_error(t_stack *stack)
{
	free_stack(stack);
	write(2, "Error\n", 6);
	exit(-1);
}

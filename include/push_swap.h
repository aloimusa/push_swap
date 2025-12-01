/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloimusa <aloimusa@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 17:53:12 by aloimusa          #+#    #+#             */
/*   Updated: 2025/06/27 17:53:14 by aloimusa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft.h"

# ifndef MAX_DEPTH
#  define MAX_DEPTH 7
# endif

enum				e_operation
{
	sa,
	sb,
	ss,
	pa,
	pb,
	ra,
	rb,
	rr,
	rra,
	rrb,
	rrr,
};

enum				e_stacks
{
	a = 0,
	b = 1,
};

enum				e_dir
{
	up = -1,
	down = 1,
};

typedef struct s_struct
{
	int				size;
	int				index;
	unsigned int	*array;
}					t_stack;

t_stack				*build_stack(int ac, char **av);
void				exit_error(t_stack *stack);
void				op(t_stack *stack, int o);
int					op1(t_stack *stack, int o);
int					is_sorted(t_stack *stack);
void				free_stack(t_stack *stack);
void				radix_sort(t_stack *stack);
void				depth_sort(t_stack *stack);

#endif

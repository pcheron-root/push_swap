/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_util_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcheron <pcheron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 21:48:37 by pcheron           #+#    #+#             */
/*   Updated: 2023/05/10 15:27:28 by pcheron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_set_index(t_stack *stack)
{
	int	i;

	i = 0;
	while (stack)
	{
		stack->index = i;
		stack = stack->next;
		i++;
	}
}

bool	ft_is_duplicate(t_stack *stack, int nbr)
{
	while (stack)
	{
		if (stack->nbr == nbr)
			return (true);
		stack = stack->next;
	}
	return (false);
}

bool	ft_is_sorted(t_stack *stack)
{
	int	max;
	int	min;

	if (!stack)
		return (true);
	max = ft_find_max(stack)->nbr;
	min = ft_find_min(stack)->nbr;
	while (stack->next)
	{
		if (stack->nbr == max)
		{
			if (stack->next->nbr != min)
				return (false);
		}
		else if (stack->nbr > stack->next->nbr)
			return (false);
		stack = stack->next;
	}
	return (true);
}

void	ft_make_order(t_stack **stack)
{
	int	ind_min;
	int	size;

	if (!*stack)
		return ;
	ind_min = ft_find_min(*stack)->index;
	size = ft_stacklast(*stack)->index;
	if (ind_min <= size / 2)
	{
		while (ind_min > 0)
			(write(1, "ra\n", 3), ft_rotate(stack), ind_min--);
	}
	else
	{
		while (ind_min <= size)
			(write(1, "rra\n", 4), ft_r_rotate(stack), ind_min++);
	}
}

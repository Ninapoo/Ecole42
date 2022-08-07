/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_thresholds.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwan-chu <cwan-chu@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 16:44:03 by cwan-chu          #+#    #+#             */
/*   Updated: 2022/08/07 14:37:51 by cwan-chu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
This function will return integer at the threshold in the given stack
Input - stack and percentile int value.
*/
int	find_threshold(t_node *stack, int percentile)
{
	float	p;
	int		pos;
	int		i;

	i = 1;
	p = percentile / (float) 100;
	pos = (count_int(stack) * p) + 1;
	while (i < pos)
	{
		stack = stack->bottom;
		i++;
	}
	i = stack->num;
	obliviate_stack(stack);
	return (i);
}

// This function will return the max integer in the given stack
int	find_i_max(t_node *temp)
{
	int		i_max;
	t_node	*ptr;

	ptr = temp;
	i_max = temp->num;
	ptr = ptr->bottom;
	while (ptr && ptr->num != temp->num)
	{
		if (ptr->num > i_max)
			i_max = ptr->num;
		ptr = ptr->bottom;
	}
	return (i_max);
}

// This function will return the min integer in the given stack
int	find_i_min(t_node *temp)
{
	int		i_min;
	t_node	*ptr;

	ptr = temp;
	i_min = temp->num;
	ptr = ptr->bottom;
	while (ptr && ptr->num != temp->num)
	{
		if (ptr->num < i_min)
			i_min = ptr->num;
		ptr = ptr->bottom;
	}
	return (i_min);
}

// This function will return the second to max integer in the given stack
int	find_i_max2(t_node *temp)
{
	int		i;
	int		imax;
	t_node	*ptr;

	ptr = temp;
	i = temp->num;
	imax = find_i_max(temp);
	ptr = ptr->bottom;
	while (ptr && ptr->num != imax)
	{
		if (ptr->num > i && ptr->num != imax)
			i = ptr->num;
		ptr = ptr->bottom;
	}
	return (i);
}

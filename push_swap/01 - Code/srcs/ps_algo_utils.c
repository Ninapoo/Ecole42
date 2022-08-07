/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_algo_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwan-chu <cwan-chu@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 22:47:25 by cwan-chu          #+#    #+#             */
/*   Updated: 2022/08/07 14:48:33 by cwan-chu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
Returns 1 if rotate is quicker to reach the number.
Returns 0 if reverse rotate is quicker to reach the number.
*/
int	rotate_to_num(t_node *ha, int number)
{
	int		count_top;
	int		count_bottom;
	t_node	*ptr;
	t_node	*ptr2;

	count_top = 0;
	count_bottom = 0;
	ptr = ha;
	ptr2 = ha;
	while (ptr->num != number)
	{
		count_top++;
		ptr = ptr->bottom;
	}
	while (ptr2->top->num != number)
	{
		count_bottom++;
		ptr2 = ptr2->top;
	}
	if (count_top <= count_bottom)
		return (1);
	else
		return (0);
}

//Sort the stack in ascending order
void	ascending_order(t_frame *frame, int na, int nb)
{
	if (na == 1)
	{
		if (rotate_to_num (frame->ha, find_i_min (frame->ha)))
			while (frame->ha->num != find_i_min(frame->ha))
				run(3, frame, na, nb);
		else
			while (frame->ha->num != find_i_min(frame->ha))
				run(4, frame, na, nb);
	}
	else if (nb == 1)
	{
		if (rotate_to_num (frame->hb, find_i_min (frame->hb)))
			while (frame->hb->num != find_i_min(frame->hb))
				run(3, frame, na, nb);
		else
			while (frame->hb->num != find_i_min(frame->hb))
				run(4, frame, na, nb);
	}
}

/*
Finds how many rotates are needed to reach a number. 
Finds how many reverse rotates are needed to reach a number. 
Returns the smaller number of moves. 
*/
/*
int	num_moves_to_num(t_node *ha, int number)
{
	int		count_top;
	int		count_bottom;
	t_node	*ptr;

	count_top = 0;
	count_bottom = 0;
	ptr = ha;
	while (ha->num != number)
	{
		count_top++;
		ha = ha->bottom;
	}
	while (ptr->top->num != number)
	{
		count_bottom++;
		ptr = ptr->top;
	}
	if (count_top <= count_bottom)
		return (count_top);
	else
		return (count_bottom);
}
*/
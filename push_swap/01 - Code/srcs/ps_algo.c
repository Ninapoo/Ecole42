/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_algo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwan-chu <cwan-chu@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 16:08:50 by cwan-chu          #+#    #+#             */
/*   Updated: 2022/08/03 15:45:16 by cwan-chu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	max_on_top(t_frame *frame, int na, int nb);
void	max2_on_top(t_frame *frame, int na, int nb);

void	algo(t_frame *frame)
{
	while (count_int(frame->hb) > 2)
	{
		if (rotate_to_num (frame->hb, find_i_max(frame->hb))
			> rotate_to_num (frame->hb, find_i_max2(frame->hb)))
		{
			max2_on_top(frame, 0, 1);
			run(3, frame, 1, 0);
			max_on_top(frame, 0, 1);
			run(2, frame, 1, 0);
		}
		else
		{
			max_on_top(frame, 0, 1);
			run(2, frame, 1, 0);
		}
	}
	if (frame->hb->num < frame->hb->bottom->num)
	{
		run(1, frame, 0, 1);
	}
	run(2, frame, 1, 0);
	run(2, frame, 1, 0);
}

void	max_on_top(t_frame *frame, int na, int nb)
{
	if (na == 1)
	{
		if (rotate_to_num (frame->ha, find_i_max(frame->ha)))
			while (frame->ha->num != find_i_max(frame->ha))
				run(3, frame, na, nb);
		else
			while (frame->ha->num != find_i_max(frame->ha))
				run(4, frame, na, nb);
	}
	else if (nb == 1)
	{
		if (rotate_to_num (frame->hb, find_i_max(frame->hb)))
			while (frame->hb->num != find_i_max(frame->hb))
				run(3, frame, na, nb);
		else
			while (frame->hb->num != find_i_max(frame->hb))
				run(4, frame, na, nb);
	}
}

void	max2_on_top(t_frame *frame, int na, int nb)
{
	if (na == 1)
	{
		if (rotate_to_num (frame->ha, find_i_max2(frame->ha)))
			while (frame->ha->num != find_i_max2(frame->ha))
				run(3, frame, na, nb);
		else
			while (frame->ha->num != find_i_max2(frame->ha))
				run(4, frame, na, nb);
	}
	else if (nb == 1)
	{
		if (rotate_to_num (frame->hb, find_i_max2(frame->hb)))
			while (frame->hb->num != find_i_max2(frame->hb))
				run(3, frame, na, nb);
		else
			while (frame->hb->num != find_i_max2(frame->hb))
				run(4, frame, na, nb);
	}
}

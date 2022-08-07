/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_algo_teen.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwan-chu <cwan-chu@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 16:08:50 by cwan-chu          #+#    #+#             */
/*   Updated: 2022/08/01 16:09:42 by cwan-chu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	algo_teen_one(t_frame *frame);

void	algo_teen(t_frame *frame)
{
	while (frame->hb)
	{
		if (frame->hb->num < find_i_min(frame->ha))
		{
			ascending_order (frame, 1, 0);
			run (2, frame, 1, 0);
		}
		else if (frame->hb->num < frame->ha->num)
			algo_teen_one (frame);
		else if (frame->hb->num > frame->ha->num)
		{	
			while (frame->hb->num > frame->ha->num)
				run(3, frame, 1, 0);
			run (2, frame, 1, 0);
		}
	}
	ascending_order(frame, 1, 0);
}

// if (hb->num < ha->num)
void	algo_teen_one(t_frame *frame)
{
	if (frame->hb->num < frame->ha->num && frame->hb->num > frame->ha->top->num)
	{
		run (2, frame, 1, 0);
	}
	else if (frame->hb->num < frame->ha->num
		&& frame->hb->num < frame->ha->top->num)
	{
		while (frame->hb->num < frame->ha->num
			&& frame->hb->num < frame->ha->top->num
			&& frame->ha->top->num != find_i_max(frame->ha))
		{
			run (4, frame, 1, 0);
		}
		run (2, frame, 1, 0);
	}
	else if (frame->hb->num < frame->ha->num
		&& frame->ha->top->num == find_i_max(frame->ha))
	{	
		run (2, frame, 1, 0);
	}
}

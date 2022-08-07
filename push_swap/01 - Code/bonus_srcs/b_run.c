/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_run.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwan-chu <cwan-chu@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 21:35:02 by cwan-chu          #+#    #+#             */
/*   Updated: 2022/08/05 14:37:22 by cwan-chu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	b_run_swap(t_frame *frame, int na, int nb);
void	b_run_push(t_frame *frame, int na, int nb);
void	b_run_rotate(t_frame *frame, int na, int nb);
void	b_run_reverse_rotate(t_frame *frame, int na, int nb);

/*
i = 1 -> swap
i = 2 -> push
i = 3 -> rotate
i = 4 -> reverse rotate
*/
void	b_run(int i, t_frame *frame, int na, int nb)
{
	if (i == 1)
		b_run_swap (frame, na, nb);
	if (i == 2)
		b_run_push (frame, na, nb);
	if (i == 3)
		b_run_rotate (frame, na, nb);
	if (i == 4)
		b_run_reverse_rotate (frame, na, nb);
}

void	b_run_swap(t_frame *frame, int na, int nb)
{
	if (na == 1 && frame->ha && nb == 1 && frame->hb)
	{
		swap (frame->ha);
		swap (frame->hb);
	}
	else if (na == 1 && frame->ha)
	{
		swap(frame->ha);
	}
	else if (nb == 1 && frame->hb)
	{
		swap (frame->hb);
	}
	else
		avada_kedavra(frame);
}

void	b_run_push(t_frame *frame, int na, int nb)
{
	if (na == 1)
	{
		push (frame, na, nb);
	}
	else if (nb == 1)
	{
		push (frame, na, nb);
	}
	else
		avada_kedavra(frame);
}

void	b_run_rotate(t_frame *frame, int na, int nb)
{
	if (na == 1 && frame->ha && frame->ha && frame->ha->bottom
		&& nb == 1 && frame->hb && frame->hb && frame->hb->bottom)
	{
		frame->ha = frame->ha->bottom;
		frame->hb = frame->hb->bottom;
	}
	else if (na == 1 && frame->ha && frame->ha && frame->ha->bottom)
	{
		frame->ha = frame->ha->bottom;
	}
	else if (nb == 1 && frame->hb && frame->hb && frame->hb->bottom)
	{
		frame->hb = frame->hb->bottom;
	}
	else
		avada_kedavra(frame);
}

void	b_run_reverse_rotate(t_frame *frame, int na, int nb)
{
	if (na == 1 && frame->ha && frame->ha && frame->ha->top
		&& nb == 1 && frame->hb && frame->hb && frame->hb->top)
	{
		frame->ha = frame->ha->top;
		frame->hb = frame->hb->top;
	}
	else if (na == 1 && frame->ha && frame->ha && frame->ha->top)
	{
		frame->ha = frame->ha->top;
	}
	else if (nb == 1 && frame->hb && frame->hb && frame->hb->top)
	{
		frame->hb = frame->hb->top;
	}
	else
		avada_kedavra(frame);
}

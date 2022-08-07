/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_run.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwan-chu <cwan-chu@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 21:35:02 by cwan-chu          #+#    #+#             */
/*   Updated: 2022/08/03 16:32:11 by cwan-chu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	run_swap(t_frame *frame, int na, int nb);
void	run_push(t_frame *frame, int na, int nb);
void	run_rotate(t_frame *frame, int na, int nb);
void	run_reverse_rotate(t_frame *frame, int na, int nb);

/*
i = 1 -> swap
i = 2 -> push
i = 3 -> rotate
i = 4 -> reverse rotate
*/
void	run(int i, t_frame *frame, int na, int nb)
{
	if (i == 1)
		run_swap (frame, na, nb);
	if (i == 2)
		run_push (frame, na, nb);
	if (i == 3)
		run_rotate (frame, na, nb);
	if (i == 4)
		run_reverse_rotate (frame, na, nb);
}

void	run_swap(t_frame *frame, int na, int nb)
{
	if (na == 1 && nb == 1)
	{
		swap (frame->ha);
		swap (frame->hb);
		write (1, "ss\n", 3);
	}
	else if (na == 1)
	{
		swap(frame->ha);
		write (1, "sa\n", 3);
	}
	else if (nb == 1)
	{
		swap (frame->hb);
		write (1, "sb\n", 3);
	}
}

void	run_push(t_frame *frame, int na, int nb)
{
	if (na == 1)
	{
		push (frame, na, nb);
		write (1, "pa\n", 3);
	}
	else if (nb == 1)
	{
		push (frame, na, nb);
		write (1, "pb\n", 3);
	}
}

void	run_rotate(t_frame *frame, int na, int nb)
{
	if (na == 1 && frame->ha && frame->ha->bottom
		&& nb == 1 && frame->hb && frame->hb->bottom)
	{
		frame->ha = frame->ha->bottom;
		frame->hb = frame->hb->bottom;
		write (1, "rr\n", 3);
	}
	else if (na == 1 && frame->ha && frame->ha->bottom)
	{
		frame->ha = frame->ha->bottom;
		write (1, "ra\n", 3);
	}
	else if (nb == 1 && frame->hb && frame->hb->bottom)
	{
		frame->hb = frame->hb->bottom;
		write (1, "rb\n", 3);
	}
}

void	run_reverse_rotate(t_frame *frame, int na, int nb)
{
	if (na == 1 && frame->ha && frame->ha->top
		&& nb == 1 && frame->hb && frame->hb->top)
	{
		frame->ha = frame->ha->top;
		frame->hb = frame->hb->top;
		write (1, "rrr\n", 4);
	}
	else if (na == 1 && frame->ha && frame->ha->top)
	{
		frame->ha = frame->ha->top;
		write (1, "rra\n", 4);
	}
	else if (nb == 1 && frame->hb && frame->hb->top)
	{
		frame->hb = frame->hb->top;
		write (1, "rrb\n", 4);
	}
}

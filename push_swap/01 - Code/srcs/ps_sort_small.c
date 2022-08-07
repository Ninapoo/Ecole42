/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort_small.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwan-chu <cwan-chu@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 19:43:31 by cwan-chu          #+#    #+#             */
/*   Updated: 2022/08/07 14:39:50 by cwan-chu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_btoa(t_frame *frame);

//Sort 5 and under integers
void	sort_small(t_frame *frame, int na, int nb)
{
	t_node	*head;
	int		num_max;
	int		num_min;

	num_max = find_i_max (frame->ha);
	num_min = find_i_min (frame->ha);
	head = NULL;
	if (na == 1)
		head = frame->ha;
	else if (nb == 1)
		head = frame->hb;
	if (!is_success(head))
	{
		if (count_int (head) == 2 && head->num > head->bottom->num)
			run(1, frame, na, nb);
		else if (count_int (head) == 2 && head->num < head->bottom->num)
		{
			obliviate_frame(frame);
			exit (0);
		}
		else if (count_int (head) == 3)
			sort_three_num (frame, na, nb);
		else
			sort_othersmall (frame, num_min, num_max);
	}
}

//Sort 3 numbers, i only sort 3 numbers in stack a
void	sort_three_num(t_frame *frame, int na, int nb)
{
	if (frame->ha->num > frame->ha->bottom->num
		&& frame->ha->bottom->num > frame->ha->top->num)
	{
		run(1, frame, na, nb);
		run(4, frame, na, nb);
	}
	if (frame->ha->bottom->num == find_i_max (frame->ha)
		&& frame->ha->top->num == find_i_min (frame->ha))
	{
		run(4, frame, na, nb);
		sort_small (frame, na, nb);
	}
	if (frame->ha->bottom->num == find_i_max (frame->ha))
	{
		run(1, frame, na, nb);
		sort_small (frame, na, nb);
	}
	if (frame->ha->bottom->num == find_i_min (frame->ha))
	{
		run(3, frame, na, nb);
		sort_small (frame, na, nb);
	}
}

//Sorts 4-5 numbers
void	sort_othersmall(t_frame *frame, int num_min, int num_max)
{
	int		count;

	count = count_int(frame->ha);
	while (count > 0)
	{
		if (frame->ha->num == num_min || frame->ha->num == num_max)
			run(2, frame, 0, 1);
		else
			run(3, frame, 1, 0);
		count--;
	}
	sort_small (frame, 0, 1);
	sort_small (frame, 1, 0);
	push_btoa(frame);
	run(3, frame, 1, 0);
}

//Push all numbers in stack b to stack a
void	push_btoa(t_frame *frame)
{
	int		count;

	count = count_int(frame->hb);
	while (count)
	{
		run(2, frame, 1, 0);
		count--;
	}
}

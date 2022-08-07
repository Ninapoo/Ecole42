/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort_medium.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwan-chu <cwan-chu@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 19:49:14 by cwan-chu          #+#    #+#             */
/*   Updated: 2022/08/07 14:44:37 by cwan-chu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	starter_split(t_frame *frame);
void	check_split(t_frame *frame, int x, int y, int count);

/*
Sort greater than 5 numbers. 
For up to 12 numbers: 
- push all numbers to stack b, except i_max and 2 other numbers.
- Sort the 3 numbers in stack a. 
- push to stack a in sorted order. 
For greater than 12 numbers:
- starter_split pushes all exept the 12 largest numbers to stack b. 
- It makes a "bow" shaped stack with recalculated' x and y to find p-value. 
- frame->num_y is the minimum of the 12 numbers in stack a. 
- Pushes all the numbers except for 3 numbers to stack b. 
- Sort these 3 numbers in stack a. 
- algo_one pushes the numbers until (and incl) num_y in sorted order to a.
- algo looks for the max in b and pushes it to a. 
*/
void	sort_medium(t_frame *frame, int na, int nb)
{
	if (count_int(frame->ha) <= 12)
	{
		while (count_int (frame->ha) > 3)
		{
			if (frame->ha->num != find_i_max (frame->ha))
				run (2, frame, 0, 1);
			else
				run (3, frame, 1, 0);
		}
		sort_three_num (frame, 1, 0);
		algo_teen (frame);
	}
	else
	{
		starter_split(frame);
		sort_three_num (frame, na, nb);
		algo_one (frame, frame->num_y);
		algo(frame);
	}
}

void	starter_split(t_frame *frame)
{
	int	count;

	count = 0;
	while (count_int (frame->ha) > 12)
	{
		count = count_int (frame->ha);
		if (count > 750)
		{
			frame->nx = 2;
			frame->ny = 5;
		}
		if (count > 70 && count < 750)
		{
			frame->nx = -9.3 * count / 400 + 81 / 4;
			frame->ny = -18 * count / 400 + 81 / 2;
		}
		split_thresh (frame);
	}
	frame->num_y = find_i_min(frame->ha);
	while (count_int (frame->ha) > 3)
		run (2, frame, 0, 1);
}

void	split_thresh(t_frame *frame)
{
	int		x;
	int		y;
	int		count;

	count = count_int (frame->ha);
	x = find_threshold (temp_stack (frame->ha), frame->nx);
	y = find_threshold (temp_stack (frame->ha), frame->ny - 2);
	while (count >= 0)
	{
		if (frame->ha->num < y)
		{
			run (2, frame, 0, 1);
			count--;
			if (count >= 0)
			{
				check_split (frame, x, y, count);
				count = frame->split_counter;
			}
		}
		else
		{
			run(3, frame, 1, 0);
			count--;
		}
	}
}

void	check_split(t_frame *frame, int x, int y, int count)
{
	if (frame->hb->top && frame->hb->num < x && frame->ha->top
		&& frame->ha->num >= y)
	{
		run (3, frame, 1, 1);
		count--;
	}
	else if (frame->hb->bottom && frame->hb->num < x)
		run (3, frame, 0, 1);
	else if (frame->ha->top && frame->ha->num && frame->ha->num >= y)
	{
		run (3, frame, 1, 0);
		count--;
	}
	frame->split_counter = count;
}

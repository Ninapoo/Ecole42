/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_avada_kedavra.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwan-chu <cwan-chu@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 21:59:25 by cwan-chu          #+#    #+#             */
/*   Updated: 2022/08/07 15:02:36 by cwan-chu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	avada_kedavra(t_frame *frame)
{
	obliviate_frame(frame);
	print_error();
	exit (0);
}

void	obliviate_frame(t_frame *frame)
{
	if (frame)
	{
		if (frame->ha)
		{
			obliviate_stack(frame->ha);
			frame->ha = NULL;
		}
		if (frame->hb)
		{
			obliviate_stack(frame->hb);
			frame->hb = NULL;
		}
		free (frame);
		frame = NULL;
	}
}

// This function frees of t_node
int	obliviate_stack(t_node *head)
{
	t_node	*tracker;
	t_node	*del;

	del = NULL;
	tracker = NULL;
	if (head)
	{
		if (head->top)
		{	
			head->top->bottom = NULL;
		}
		tracker = head;
		while (tracker && tracker->bottom)
		{
			del = tracker;
			tracker = tracker->bottom;
			free (del);
			del = NULL;
		}
		free (tracker);
		tracker = NULL;
	}
	return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_allocate_memory.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwan-chu <cwan-chu@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 17:14:01 by cwan-chu          #+#    #+#             */
/*   Updated: 2022/08/06 22:42:38 by cwan-chu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

t_frame	*make_frame(void)
{
	t_frame	*frame;

	frame = (t_frame *)malloc(sizeof(t_frame));
		frame->ha = NULL;
	frame->hb = NULL;
	frame->is_error = 0;
	frame->read_check = 1;
	frame->gnl_count = 1;
	frame->atoi_num = 0;
	frame->stack_size = 0;
	return (frame);
}

//Malloc the t_node
t_node	*malloc_t_node(t_frame *frame)
{
	t_node	*head;

	head = (t_node *)malloc(sizeof(t_node));
	if (!head)
	{
		obliviate_frame(frame);
		print_error();
		exit (0);
	}
	else
		return (head);
}

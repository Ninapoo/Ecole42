/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_make_stack_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwan-chu <cwan-chu@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 18:36:50 by cwan-chu          #+#    #+#             */
/*   Updated: 2022/08/07 15:03:26 by cwan-chu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*add_to_stack_bottom_util(t_node *head, int num);
void	add_to_stack_bottom_util2(t_frame *frame, t_node *new, int num);

// If the stack does not exist, create it
t_node	*create_stack(t_node *head, int num)
{
	head->num = num;
	head->bottom = NULL;
	head->top = NULL;
	return (head);
}

// Add to the bottom of the stack to create the starting stack
void	add_to_stack_bottom2(t_frame *frame, int num)
{
	t_node	*new;

	new = malloc_t_node (frame);
	if (frame->ha == NULL)
	{
		frame->ha = new;
		frame->ha = create_stack(frame->ha, num);
	}
	else
	{
		add_to_stack_bottom_util2(frame, new, num);
	}
}

void	add_to_stack_bottom_util2(t_frame *frame, t_node *new, int num)
{
	if (frame->ha->top == NULL)
	{
		new->num = num;
		new->top = frame->ha;
		new->bottom = frame->ha;
		frame->ha->top = new;
		frame->ha->bottom = new;
	}
	else
	{
		new->num = num;
		new->bottom = frame->ha;
		new->top = frame->ha->top;
		frame->ha->top->bottom = new;
		frame->ha->top = new;
	}
}

// Add to the bottom of the stack to create the starting stack
t_node	*add_to_stack_bottom(t_node *head, int num)
{
	if (head == NULL)
		return (create_stack(head, num));
	else
		return (add_to_stack_bottom_util(head, num));
}

t_node	*add_to_stack_bottom_util(t_node *head, int num)
{	
	t_node	*ptr;

	ptr = (t_node *)malloc(sizeof(t_node));
	if (head->top == NULL)
	{
		ptr->num = num;
		ptr->top = head;
		ptr->bottom = head;
		head->top = ptr;
		head->bottom = ptr;
	}
	else
	{
		ptr->num = num;
		ptr->bottom = head;
		ptr->top = head->top;
		head->top->bottom = ptr;
		head->top = ptr;
	}
	return (head);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_operations_push.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwan-chu <cwan-chu@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 18:36:52 by cwan-chu          #+#    #+#             */
/*   Updated: 2022/08/01 16:12:27 by cwan-chu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	del_top_giver(t_frame *frame, int na, int nb, t_node *temp);
t_node	*giver_util(t_node *giver, t_node *temp);
void	add_to_receiver(t_frame *frame, int na, int nb, t_node *temp);
t_node	*receiver_util(t_node *receiver, t_node *temp);

void	push(t_frame *frame, int na, int nb)
{
	t_node	*temp;

	temp = NULL;
	if (na == 1 && frame->hb != NULL)
	{
		temp = frame->hb;
		del_top_giver(frame, na, nb, temp);
		add_to_receiver(frame, na, nb, temp);
	}
	else if (nb == 1 && frame->ha != NULL)
	{
		temp = frame->ha;
		del_top_giver(frame, na, nb, temp);
		add_to_receiver(frame, na, nb, temp);
	}
}

void	del_top_giver(t_frame *frame, int na, int nb, t_node *temp)
{
	t_node	*giver;

	giver = frame->ha;
	if (na == 1)
		giver = frame->hb;
	if (giver->bottom == NULL)
		giver = NULL;
	else
		giver = giver_util(giver, temp);
	if (na == 1)
		frame->hb = giver;
	else if (nb == 1)
		frame->ha = giver;
}

t_node	*giver_util(t_node *giver, t_node *temp)
{
	if (giver->top == giver->bottom)
	{
		giver = giver->bottom;
		temp->top = NULL;
		temp->bottom = NULL;
		giver->top = NULL;
		giver->bottom = NULL;
	}
	else
	{
		giver = giver->bottom;
		giver->top = giver->top->top;
		giver->top->bottom = giver;
		temp->top = NULL;
		temp->bottom = NULL;
	}
	return (giver);
}

void	add_to_receiver(t_frame *frame, int na, int nb, t_node *temp)
{
	t_node	*receiver;

	receiver = frame->hb;
	if (na == 1)
		receiver = frame->ha;
	if (receiver == NULL)
	{
		temp->top = NULL;
		temp->bottom = NULL;
		receiver = temp;
	}
	else
		receiver = receiver_util(receiver, temp);
	if (na == 1)
		frame->ha = receiver;
	else if (nb == 1)
		frame->hb = receiver;
}

t_node	*receiver_util(t_node *receiver, t_node *temp)
{
	if (receiver->top == NULL)
	{
		temp->top = receiver;
		temp->bottom = receiver;
		receiver->top = temp;
		receiver->bottom = temp;
		receiver = temp;
	}
	else
	{
		temp->top = receiver->top;
		temp->bottom = receiver;
		receiver->top->bottom = temp;
		receiver->top = temp;
		receiver = temp;
	}
	return (receiver);
}

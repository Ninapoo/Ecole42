/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_temp_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwan-chu <cwan-chu@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 15:10:55 by cwan-chu          #+#    #+#             */
/*   Updated: 2022/08/07 14:20:14 by cwan-chu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*add_to_stack_top(t_node *head, int num, t_node *temp);
t_node	*add_to_stack_top_util(t_node *head, int num, t_node *temp);

/*
This function will make the temporary, sorted stack.
Use it to identify the thresholds.
input - unsorted stack
output - sorted stack
*/
t_node	*temp_stack(t_node *head)
{
	int		i;
	t_node	*temp;
	t_node	*other;

	other = (t_node *)malloc(sizeof(t_node));
	i = head->num;
	temp = (t_node *)malloc(sizeof(t_node));
	if (temp == NULL)
		return (NULL);
	temp = create_stack(temp, i);
	temp = add_to_stack_top(temp, head->bottom->num, other);
	head = head->bottom->bottom;
	while (head->num != i)
	{
		temp = make_temp(temp, head->num);
		head = head->bottom;
	}
	while (temp)
	{
		if (temp->num == find_i_min(head))
			return (temp);
		temp = temp->bottom;
	}
	obliviate_stack(other);
	return (temp);
}

/*
This function will sort the stack. 
From this, obtain the value of percentile x and y.
*/
t_node	*make_temp(t_node *temp, int num)
{
	int	i_max;
	int	i_min;

	i_max = find_i_max(temp);
	i_min = find_i_min(temp);
	while (temp->num != i_min)
			temp = temp->bottom;
	if (num < i_min)
		temp = add_to_stack_bottom (temp, num);
	else if (num > i_max)
		temp = add_to_stack_bottom (temp, num);
	else
	{
		while (temp->num < num)
			temp = temp->bottom;
		temp = add_to_stack_bottom (temp, num);
	}
	i_min = find_i_min(temp);
	while (temp->num != i_min)
		temp = temp->bottom;
	return (temp);
}

/*
This should go in operations or operations_utils
Add to the top of the stack. I use this for temp_stack.
*/
t_node	*add_to_stack_top(t_node *head, int num, t_node *temp)
{
	if (head == NULL)
		return (create_stack(temp, num));
	else
		return (add_to_stack_top_util(head, num, temp));
}

t_node	*add_to_stack_top_util(t_node *head, int num, t_node *ptr)
{	
	if (head->top == NULL)
	{
		ptr->num = num;
		ptr->bottom = head;
		ptr->top = head;
		head->bottom = ptr;
		head->top = ptr;
	}
	else
	{
		ptr->num = num;
		ptr->bottom = head;
		ptr->top = head->top;
		head->top = ptr;
		ptr->top->bottom = ptr;
	}
	head = ptr;
	return (head);
}

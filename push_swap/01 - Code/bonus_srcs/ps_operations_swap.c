/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_operations_swap.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwan-chu <cwan-chu@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 18:36:52 by cwan-chu          #+#    #+#             */
/*   Updated: 2022/08/05 19:15:56 by cwan-chu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

/*
sa (swap a): Swap the first 2 elements at the top of stack a. 
	Do nothing if there is only one or no elements.
sb (swap b): Swap the first 2 elements at the top of stack b. 
	Do nothing if there is only one or no elements.
ss : sa and sb at the same time.
*/
void	swap(t_node *head)
{
	int	a;
	int	b;

	a = 0;
	b = 0;
	if (head != NULL || head->top != NULL)
	{
		a = head->num;
		b = head->bottom->num;
		head->num = b;
		head->bottom->num = a;
	}
}

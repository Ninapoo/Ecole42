/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_count_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwan-chu <cwan-chu@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 19:31:08 by cwan-chu          #+#    #+#             */
/*   Updated: 2022/08/05 19:15:43 by cwan-chu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

/*
Returns the number of integers in the stack
*/
int	count_int(t_node *head)
{
	int	num;
	int	i;

	i = 0;
	num = 0;
	if (head == NULL)
		return (0);
	else
	{
		num = head->num;
		i++;
		head = head->bottom;
		while (head && head->num != num)
		{
			i++;
			head = head->bottom;
		}
		return (i);
	}	
}

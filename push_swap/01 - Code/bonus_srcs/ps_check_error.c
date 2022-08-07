/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_check_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwan-chu <cwan-chu@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 18:36:44 by cwan-chu          #+#    #+#             */
/*   Updated: 2022/08/07 17:03:29 by cwan-chu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
Return 0 if duplicate found
Return 1 if duplicate not found
*/
int	duplicate_not_found(t_frame *frame, int num)
{	
	t_node	*temp;
	int		first_num;

	temp = NULL;
	first_num = 0;
	if (frame->ha == NULL)
		return (1);
	else if (num == frame->ha->num)
		return (0);
	else
	{
		first_num = frame->ha->num;
		temp = frame->ha->bottom;
		while (temp && temp->num != first_num)
		{
			if (temp->num != num)
				temp = temp->bottom;
			else
			{
				frame->is_error = 1;
				return (0);
			}
		}
	}
	return (1);
}

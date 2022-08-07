/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_is_success.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwan-chu <cwan-chu@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 17:17:03 by cwan-chu          #+#    #+#             */
/*   Updated: 2022/08/05 19:15:46 by cwan-chu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

/*
Return 1 if success
Return 0 if fail
*/
int	is_success(t_node *head)
{
	t_node	*ptr;

	ptr = head;
	if (head == NULL)
		return (0);
	else if (head->top == NULL)
		return (0);
	else if (ptr->num < ptr->bottom->num)
	{
		ptr = ptr->bottom;
		while (ptr && ptr->bottom != head && ptr->num < ptr->bottom->num)
			ptr = ptr->bottom;
		if (ptr->bottom == head)
			return (1);
		else
			return (0);
	}
	else
		return (0);
}

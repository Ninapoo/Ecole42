/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_print_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwan-chu <cwan-chu@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 18:36:44 by cwan-chu          #+#    #+#             */
/*   Updated: 2022/08/07 14:39:32 by cwan-chu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
//#include <stdio.h>

//This functions prints the error message and exits the program. 
int	print_error(void)
{
	write (1, "Error\n", 6);
	return (0);
}

/*
printf("Printing both stacks:\n");//
printf("stack a\n");print_stack(frame->ha);//
printf("stack b\n");print_stack(frame->hb);//
*/
/*
void	print_stack(t_node *head)
{
	t_node	*ptr;
	int		count;

	ptr = head;
	count = count_int(head);
	printf("count = %d\n", count);
	if (head == NULL)
		printf("\n\tStack is NULL \n");
	else
	{
		printf ("\t[head = %d]\n", ptr->num);
		ptr = ptr->bottom;
		while (--count)
		{
			printf("\t[ num = %d]\n", ptr->num);
			ptr = ptr->bottom;
		}
	}
	printf("\n");
}
*/
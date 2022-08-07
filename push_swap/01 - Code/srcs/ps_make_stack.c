/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_make_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwan-chu <cwan-chu@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 18:36:50 by cwan-chu          #+#    #+#             */
/*   Updated: 2022/08/07 17:00:23 by cwan-chu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Make stack when argc = 2, eg "1 2 3"
void	make_stack_few_args(t_frame *frame, char *str)
{
	int		i;
	int		*ptr;

	i = -1;
	ptr = malloc ((ft_numwords(str, ' ') + 1) * sizeof (*ptr));
	ptr = ft_split (frame, &ptr[0], str, ' ');
	while (++i < ft_numwords(str, ' '))
	{
		if (!duplicate_not_found(frame, ptr[i]) || frame->is_error == 1)
		{
			obliviate_frame(frame);
			print_error();
			free (ptr);
			exit (0);
		}
		else
			add_to_stack_bottom2(frame, ptr[i]);
	}
	ptr = &ptr[0];
	free(ptr);
	ptr = NULL;
}

// Make stack when argc > 2, eg 1 2 3
void	make_stack_many_args(t_frame *frame, char *str)
{
	int	j;
	int	num;

	j = -1;
	while (str[++j])
	{
		if (str[j] < '-' || (str[j] > '-' && str[j] < '0') || str[j] > '9')
		{
			obliviate_frame(frame);
			print_error();
			exit (0);
		}
	}
	ft_atoi(frame, str);
	num = frame->atoi_num;
	if (!str[0] || frame->is_error == 1 || !duplicate_not_found(frame, num))
		frame->is_error = 1;
	add_to_stack_bottom2(frame, num);
}

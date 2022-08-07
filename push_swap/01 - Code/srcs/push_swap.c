/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwan-chu <cwan-chu@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 18:36:39 by cwan-chu          #+#    #+#             */
/*   Updated: 2022/08/07 17:13:48 by cwan-chu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	int		i;
	t_frame	*frame;

	i = 0;
	if (argc == 1)
		return (0);
	frame = make_frame();
	if (argc == 2 && argv[1])
		make_stack_few_args(frame, argv[1]);
	else
	{
		while (argv[++i])
		{
			make_stack_many_args(frame, argv[i]);
			if (frame->is_error == 1)
				avada_kedavra(frame);
		}
	}
	if (frame->ha && !is_success(frame->ha) && count_int(frame->ha) > 1
		&& count_int(frame->ha) <= 5)
		sort_small(frame, 1, 0);
	else if (frame->ha && count_int(frame->ha) > 1 && !is_success(frame->ha))
		sort_medium(frame, 1, 0);
	obliviate_frame(frame);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwan-chu <cwan-chu@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 16:55:21 by cwan-chu          #+#    #+#             */
/*   Updated: 2022/08/07 17:14:46 by cwan-chu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	run_instructions(t_frame *frame);

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
	frame->stack_size = count_int(frame->ha);
	if (!is_success(frame->ha) && frame->ha)
		run_instructions(frame);
	checker_is_success(frame);
	obliviate_frame(frame);
	return (0);
}

void	run_instructions(t_frame *frame)
{
	char	*line;

	line = get_next_line(0);
	while (line)
	{
		execute(frame, line);
		free (line);
		line = get_next_line(0);
	}
	if (line)
		free (line);
}

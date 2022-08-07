/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_execute.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwan-chu <cwan-chu@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 20:19:47 by cwan-chu          #+#    #+#             */
/*   Updated: 2022/08/06 22:37:43 by cwan-chu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	execute(t_frame *frame, char *line)
{
	if (check_line(line, "ss\n"))
		b_run(1, frame, 1, 1);
	else if (check_line(line, "sa\n"))
		b_run(1, frame, 1, 0);
	else if (check_line(line, "sb\n"))
		b_run(1, frame, 0, 1);
	else if (check_line(line, "pa\n"))
		b_run(2, frame, 1, 0);
	else if (check_line(line, "pb\n"))
		b_run(2, frame, 0, 1);
	else if (check_line(line, "rr\n"))
		b_run(3, frame, 1, 1);
	else if (check_line(line, "ra\n"))
		b_run(3, frame, 1, 0);
	else if (check_line(line, "rb\n"))
		b_run(3, frame, 0, 1);
	else if (check_line(line, "rrr\n"))
		b_run(4, frame, 1, 1);
	else if (check_line(line, "rra\n"))
		b_run(4, frame, 1, 0);
	else if (check_line(line, "rrb\n"))
		b_run(4, frame, 0, 1);
	else
		frame->read_check--;
}

int	check_line(char *line, char *inst)
{
	int	count;

	count = 0;
	if (line[count] && line[count] == inst[count])
	{
		count++;
		while (line[count] && inst[count] && line[count] == inst[count])
			count++;
		if (line[count - 1] == '\n' && inst[count - 1] == '\n')
			return (1);
		else
			return (0);
	}
	else
		return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_checker_is_success.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwan-chu <cwan-chu@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 17:19:05 by cwan-chu          #+#    #+#             */
/*   Updated: 2022/08/06 15:23:03 by cwan-chu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	checker_is_success(t_frame *frame)
{
	if (frame->ha == NULL)
		write (0, "\n", 1);
	else if (frame->read_check < 0)
		print_error();
	else if (is_success(frame->ha) && frame->read_check >= 0
		&& frame->stack_size == count_int(frame->ha))
		write (0, "OK\n", 3);
	else
		write (0, "KO\n", 3);
}

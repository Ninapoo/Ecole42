/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwan-chu <cwan-chu@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/03 15:29:53 by cwan-chu          #+#    #+#             */
/*   Updated: 2022/08/05 19:15:26 by cwan-chu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	is_empty_space(char c);

void	ft_atoi(t_frame *frame, const char *str)
{
	int		minus;
	int		i;

	i = 0;
	minus = 0;
	frame->atoi_num = 0;
	while (is_empty_space(str[i]))
		i++;
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
	{
		i++;
		minus = i;
	}
	while ('0' <= str[i] && str[i] <= '9')
	{
		frame->atoi_num = frame->atoi_num * 10 + (str[i] - '0');
		i++;
	}
	if (minus == 1)
		frame->atoi_num = -frame->atoi_num;
	if ((str[i] && ((32 < str[i] && str[i] < '0') || (str[i] > '9')))
		|| frame->atoi_num > INT_MAX || frame->atoi_num < INT_MIN)
		frame->is_error = 1;
}

int	is_empty_space(char c)
{
	if (c == '\t' || c == '\n' || c == '\v'
		|| c == '\f' || c == '\r' || c == ' ')
		return (1);
	else
		return (0);
}

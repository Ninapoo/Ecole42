/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwan-chu <cwan-chu@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 17:14:50 by cwan-chu          #+#    #+#             */
/*   Updated: 2022/08/03 15:23:07 by cwan-chu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	*ft_makestring(t_frame *frame, char *s, int *ptr, char c);

int	*ft_split(t_frame *frame, int *ptr, char const *s, char c)
{
	char	*str;

	str = (char *) s;
	ptr = ft_makestring (frame, str, ptr, c);
	return (ptr);
}

static int	*ft_makestring(t_frame *frame, char *str, int *ptr, char c)
{
	int				i;
	int				j;
	unsigned int	n;

	i = 0;
	j = 0;
	n = 0;
	while (j < ft_numwords(str, c))
	{
		while (str[i] == c)
			i++;
		while (str[i] && str[i] != c)
		{
			i++;
			n++;
		}
		ft_atoi(frame, &str[i - n]);
		ptr[j] = frame->atoi_num;
		j++;
		n = 0;
	}
	ptr[j] = '\0';
	return (&ptr[0]);
}

int	ft_numwords(char const *s, char c)
{
	int	i;
	int	num;

	i = 0;
	if (s[i] == c || !s[i])
		num = 0;
	else
	{
		num = 1;
		i++;
	}
	while (s[i])
	{
		if (s[i] != c && s[i - 1] == c)
			num++;
		i++;
	}
	return (num);
}

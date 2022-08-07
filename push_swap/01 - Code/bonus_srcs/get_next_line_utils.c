/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwan-chu <cwan-chu@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 12:18:00 by cwan-chu          #+#    #+#             */
/*   Updated: 2022/01/30 12:39:10 by cwan-chu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

size_t	ft_strlen(char *str)
{
	size_t	count;

	count = 0;
	while (str[count])
		count++;
	return (count);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*ptr;
	int		len;
	int		i;

	i = -1;
	if (!s1)
	{
		s1 = (char *)malloc(1 * sizeof(char));
		s1[0] = '\0';
	}
	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	ptr = malloc (len * sizeof (char));
	if (!ptr)
		return (NULL);
	while (s1[++i])
		ptr[i] = s1[i];
	i = -1;
	while (s2[++i])
		ptr[i + ft_strlen(s1)] = s2[i];
	ptr[i + ft_strlen(s1)] = '\0';
	free(s1);
	return (ptr);
}

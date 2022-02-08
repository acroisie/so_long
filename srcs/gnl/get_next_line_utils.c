/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acroisie <acroisie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 08:12:14 by acroisie          #+#    #+#             */
/*   Updated: 2021/12/16 14:24:10 by acroisie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	if (!s1)
		return (ft_strndup(s2, ft_strlen(s2)));
	str = malloc(((ft_strlen(s1) + ft_strlen(s2)) * sizeof(char)) + 1);
	if (!str)
		return (NULL);
	while (s1[j])
		str[i++] = s1[j++];
	j = 0;
	while (s2[j])
		str[i++] = s2[j++];
	str[i] = '\0';
	free(s1);
	return (str);
}

char	*ft_strndup(char *src, int n)
{
	int		i;
	char	*copy;
	int		len;

	i = 0;
	len = ft_strlen(src);
	copy = malloc((len + 1) * sizeof(char));
	if (copy == NULL)
		return (NULL);
	while (src[i] && i < n)
	{
		copy[i] = src[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}

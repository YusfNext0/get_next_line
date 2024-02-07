/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynachat <ynachat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 22:43:41 by ynachat           #+#    #+#             */
/*   Updated: 2024/02/07 15:33:59 by ynachat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

char	*ft_strxcpy(char *dst, const char *src, size_t len)
{
	size_t	i;

	i = 0;
	while (src[i] && i < len)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*p;
	size_t	len1;
	size_t	len2;

	if (!s1)
		return (free(s1), s1 = NULL, ft_strdup(s2));
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	p = malloc(((sizeof(char)) * (len1 + len2 + 1)));
	if (!p)
		return (free(s1), s1 = NULL, NULL);
	ft_strxcpy(p, s1, len1);
	ft_strxcpy(p + len1, s2, len2);
	free(s1);
	s1 = NULL;
	return (p);
}

char	*ft_strdup(char *s1)
{
	char	*p;
	int		i;

	p = (char *)malloc((sizeof(char) * (ft_strlen(s1) + 1)));
	if (!p)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		p[i] = s1[i];
		i++;
	}
	p[i] = '\0';
	return (p);
}

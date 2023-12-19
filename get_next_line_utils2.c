/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nait-bou <nait-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 19:58:02 by nait-bou          #+#    #+#             */
/*   Updated: 2023/12/19 20:00:39 by nait-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*v;
	size_t			i;

	i = 0;
	v = (unsigned char *)s;
	while (i < n)
	{
		v[i] = (unsigned char)c;
		i++;
	}
	return ((void *)v);
}

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, '\0', n);
}


void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*d;
	size_t	tot;

	if (size != 0 && nmemb > SIZE_MAX / size)
		return (NULL);
	tot = nmemb * size;
	d = malloc(tot);
	if (!d)
		return (NULL);
	ft_bzero(d, (nmemb * size));
	return ((void *)d);
}

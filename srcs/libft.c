/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jforner <jforner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 11:24:37 by jforner           #+#    #+#             */
/*   Updated: 2022/02/08 11:43:24 by jforner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pushswap.h"

char	*ft_fullstr(char const *s, unsigned int start, size_t len, char *str)
{
	size_t			i;

	i = 0;
	while (i < len)
	{
		str[i] = s[start];
		i++;
		start++;
	}
	str[i] = 0;
	return (str);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*str;
	unsigned int	l;

	l = ft_strlen((char *)s);
	if (start >= l)
	{
		str = malloc(1 * sizeof(char));
		if (!str)
			return (str);
		str[0] = '\0';
		return (str);
	}
	if ((l - start) < len)
		len -= len - (l - start);
	str = malloc(len * sizeof(char) + 1);
	if (!str)
		return (str);
	str = ft_fullstr(s, start, len, str);
	return (str);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	i;
	void	*array;

	i = 0;
	array = malloc(nmemb * size);
	if (!array)
		return (NULL);
	ft_memset(array, '\0', size);
	return (array);
}

void	*ft_memset(void *str, char c, size_t n)
{
	unsigned int	i;
	unsigned char	*v;

	v = (unsigned char *)str;
	i = 0;
	while (i < n)
	{
		v[i] = c;
		i++;
	}
	return (v);
}

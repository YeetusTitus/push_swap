/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jforner <jforner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 17:26:48 by jforner           #+#    #+#             */
/*   Updated: 2022/02/08 15:21:37 by jforner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pushswap.h"

int	ft_malloc_error(char **tab, int size)
{
	while (size-- > 0)
		free(tab[size]);
	free (tab);
	return (0);
}

int	ft_splitage(char const *s, char c, char **tab, unsigned int nb_word)
{
	int	crnt_word;
	int	len;

	crnt_word = 0;
	len = 0;
	while (++crnt_word < (int)nb_word + 1)
	{
		s += len;
		len = 0;
		while (s[len] && s[len] == c)
			len++;
		s += len;
		len = 0;
		while (s[len] && s[len] != c)
			len++;
		if (s[len - 1])
			tab[crnt_word] = ft_substr(s, 0, len);
		if (!(tab[crnt_word]))
		{
			while (crnt_word-- > 0)
				free(tab[crnt_word]);
			return (0);
		}
	}
	return (1);
}

int	ft_tablen(char const *str, char sep, char ***tab, unsigned int *nb_word)
{
	int	i;

	i = 0;
	(*nb_word) = 0;
	while (str[i])
	{
		while (str[i] && str[i] == sep)
			i++;
		if (str[i])
			(*nb_word)++;
		while (str[i] && str[i] != sep)
			i++;
	}
	(*tab) = ft_calloc((*nb_word) + 2, sizeof(char *));
	(**tab) = ft_substr("./push_swap", 0, ft_strlen("./push_swap"));
	if (!(*tab))
		return (0);
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char			**tab;
	unsigned int	nb_word;

	if (!(ft_tablen(s, c, &tab, &nb_word)))
		return (NULL);
	if (!(ft_splitage(s, c, tab, nb_word)))
	{
		free(tab);
		return (NULL);
	}
	tab[nb_word + 1] = NULL;
	return (tab);
}

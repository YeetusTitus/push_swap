/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jforner <jforner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 14:32:18 by jforner           #+#    #+#             */
/*   Updated: 2022/02/08 14:34:21 by jforner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pushswap.h"

int	ft_strcmp(char *str, char *str1)
{
	int	i;

	i = 0;
	while (str[i] && str1[i])
	{
		if (str[i] != str1[i])
			return (0);
		i++;
	}
	if (str[i] != str1[i])
		return (0);
	return (1);
}

int	tablen(char **tab)
{
	int	i;

	i = 0;
	while (tab[i] != NULL)
		i++;
	return (i);
}

long	ft_atol(char *str)
{
	long	i;
	long	nbr;

	i = -1;
	nbr = 0;
	while (++i < (long)ft_strlen(str))
	{
		nbr *= 10;
		if (str[i] >= '0' && str[i] <= '9')
			nbr += (str[i] - '0');
	}
	if (str[0] == '-')
		nbr *= (-1);
	return (nbr);
}

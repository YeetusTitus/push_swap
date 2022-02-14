/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jforner <jforner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 17:26:37 by jforner           #+#    #+#             */
/*   Updated: 2022/02/12 16:57:27 by jforner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pushswap.h"

void	ft_putchar_fd(char chr, int fd)
{
	write(1, &chr, fd);
}

void	ft_putstr_fd(char *str, int fd)
{
	int	i;

	i = -1;
	while (str[++i])
		ft_putchar_fd(str[i], fd);
}

size_t	ft_strlen(char *str)
{
	int	count;

	count = 0;
	if (!str)
		return (0);
	while (str[count])
		count++;
	return (count);
}

int	posit(int nbr)
{
	if (nbr < 0)
		return (nbr * (-1));
	return (nbr);
}

int	samesign(int nb1, int nb2)
{
	if ((nb1 < 0 && nb2 < 0) || (nb1 > 0 && nb2 > 0))
		return (1);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   createlist.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jforner <jforner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 17:46:39 by jforner           #+#    #+#             */
/*   Updated: 2022/02/14 11:46:17 by jforner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pushswap.h"

int	ft_atoi(char *str)
{
	int	i;
	int	nbr;

	i = -1;
	nbr = 0;
	while (++i < (int)ft_strlen(str))
	{
		nbr *= 10;
		if (str[i] >= '0' && str[i] <= '9')
			nbr += (str[i] - '0');
	}
	if (str[0] == '-')
		nbr *= (-1);
	return (nbr);
}

void	createlist(int argc, char **argv, t_list **list)
{
	int		i;

	i = 1;
	*list = ft_lstnew(ft_atoi(argv[i]));
	while (++i < argc)
		ft_lstadd_back(list, ft_lstnew(ft_atoi(argv[i])));
}

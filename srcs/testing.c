/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jforner <jforner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 17:15:16 by jforner           #+#    #+#             */
/*   Updated: 2022/01/25 10:55:16 by jforner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pushswap.h"

int	istidy(t_list *list, int place)
{
	t_list	*liste;
	int		i;

	i = 0;
	liste = list;
	while (liste->next != NULL && i <= place)
	{
		if (liste->next != NULL && liste->next->content < liste->content)
		{
			// printf("%d\n", i);
			// ft_putstr_fd("No\n", 1);
			return (0);
		}
		liste = liste->next;
		i++;
	}
	// ft_putstr_fd("Yes\n", 1);
	return (1);
}

int	inser_test(t_list *list, int nbr)
{
	t_list	*liste;
	int		i;

	liste = list;
	i = -1;
	while (++i < nbr)
		liste = liste->next;
	if (liste->next->content < liste->content)
		return (0);
	return (1);
}

int	inplace(t_list *list, int *conta, int place)
{
	t_list	*liste;
	int		i;
	int		j;
	int		test;

	i = 0;
	liste = list;
	while (liste->next != NULL && i <= place)
	{
		test = 0;
		j = -1;
		while (++j <= place)
			if (conta[j] == liste->content)
				test = 1;
		if (test == 0)
			return (0);
		liste = liste->next;
		i++;
	}
	return (1);
}

int	ristidy(t_list *list, int place)
{
	t_list	*liste;
	int		i;

	i = 0;
	liste = list;
	while (liste->next != NULL && i <= place)
	{
		if (liste->next != NULL && liste->next->content > liste->content)
		{
			// printf("%d\n", i);
			// ft_putstr_fd("No\n", 1);
			return (0);
		}
		liste = liste->next;
		i++;
	}
	// ft_putstr_fd("Yes\n", 1);
	return (1);
}

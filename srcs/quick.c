/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jforner <jforner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 16:47:17 by jforner           #+#    #+#             */
/*   Updated: 2022/02/14 19:02:09 by jforner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pushswap.h"

int	nbrinarray(int nbr, int *array, int max, int min)
{
	int	i;

	i = min - 1;
	while (++i < max)
		if (nbr == array[i])
			return (1);
	return (0);
}

int	listinarray(t_list *list, int *array, int max, int min)
{
	t_list	*temp;
	int		i;

	temp = list;
	while (temp->next != NULL)
	{
		i = min - 1;
		while (++i < max)
			if (temp->content == array[i])
				return (1);
		temp = temp->next;
	}
	return (0);
}

void	qsorting(int min, int max, t_list **list, int *arraya)
{
	int			place;
	int			*arrayb;

	rushb(min, max, list, arraya);
	while (list[1] != NULL)
	{
		place = 0;
		arrayb = rcreateplace(list[1], ft_lstsize(list[1]));
		if (max + 1 < ft_lstsize(list[0]) + ft_lstsize(list[1]))
			place = quarttopush(list[0], arrayb[0]);
		else if (!lastmin(list[1], list[0]->content)
			&& list[0]->content < list[1]->content
			&& nbrinarray(list[0]->content, arraya, max, min))
			place++;
		pushol(list, arrayb, place);
		free(arrayb);
	}
	while (nbrinarray(list[0]->content, arraya, max, min))
		list[0] = rotate_ab(list[0], 'a');
}

void	quicks(t_list **list, int quart, int len)
{
	int	*array;

	array = rcreateplace(list[0], len);
	if (quart < 4)
		qsorting((len / 4) * (quart - 1), ((len / 4) * quart), list, array);
	else
		qsorting((len / 4) * 3, len, list, array);
	free (array);
}

int	lastmin(t_list *lista, int minb)
{
	int		i;
	int		j;
	t_list	*liste;

	liste = lista;
	i = 0;
	j = 0;
	while (liste->next != NULL)
	{
		i++;
		if (liste->content < minb)
			j = i;
		liste = liste->next;
	}
	return (j);
}

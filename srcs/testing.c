/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jforner <jforner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 17:15:16 by jforner           #+#    #+#             */
/*   Updated: 2022/02/07 15:11:53 by jforner          ###   ########.fr       */
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
			return (0);
		liste = liste->next;
		i++;
	}
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

int	ristidy(t_list *list, int place)
{
	t_list	*liste;
	int		i;

	i = 0;
	liste = list;
	while (liste->next != NULL && i <= place)
	{
		if (liste->next != NULL && liste->next->content > liste->content)
			return (0);
		liste = liste->next;
		i++;
	}
	return (1);
}

int	is3ddy(t_list **list)
{
	if (inser_test(list[0], 0) && inser_test(list[0], 1))
		return (1);
	if (inser_test(list[0], 0)
		&& list[0]->content > ft_lstlast(list[0])->content)
		return (1);
	if (list[0]->content > ft_lstlast(list[0])->content
		&& inser_test(list[0], 1))
		return (1);
	return (0);
}

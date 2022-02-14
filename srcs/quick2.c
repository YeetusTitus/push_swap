/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jforner <jforner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 16:27:53 by jforner           #+#    #+#             */
/*   Updated: 2022/02/14 19:36:40 by jforner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pushswap.h"

void	pushol3(t_list **list, int count, int topush)
{
	while (count != 0)
	{
		if (count > 0 && topush > 0 && count--)
		{
			rotate_rr(&list[0], &list[1]);
			topush--;
		}
		else if (count > 0 && topush <= 0 && count-- > 0)
			list[1] = rotate_ab(list[1], 'b');
		else if (count < 0 && topush < 0 && count++)
		{
			rrotate_rrr(&list[0], &list[1]);
			topush++;
		}
		else if (count++)
			list[1] = rrotate_ab(list[1], 'b');
	}
	while (topush > 0 && topush--)
		list[0] = rotate_ab(list[0], 'a');
	while (topush < 0 && topush++)
		list[0] = rrotate_ab(list[0], 'a');
	push_ab(&list[1], &list[0], 'a');
}

void	pushol2(t_list **list, int countmin, int countmax, int topush)
{
	int	creturn;

	creturn = 0;
	if (posit(countmin) >= posit(countmax))
	{
		if (samesign(countmin, topush) && countmin != 0
			&& posit(posit(countmin) - topush) <= posit(countmax))
			pushol3(list, countmin, topush);
		else
			pushol3(list, countmax, topush);
	}
	else
	{
		if (samesign(countmax, topush) && countmax != 0
			&& posit(posit(countmax) - topush) <= posit(countmin))
			pushol3(list, countmax, topush);
		else
			pushol3(list, countmin, topush);
	}
}

void	pushol(t_list **list, int *arrayb, int topush)
{
	int		countmin;
	int		countmax;
	t_list	*liste;

	countmin = 0;
	countmax = 0;
	liste = list[1];
	while (liste->content != arrayb[ft_lstsize(list[1]) - 1])
	{
		liste = liste->next;
		countmin++;
	}
	if (countmin > ((ft_lstsize(list[1]) + 1) / 2) - 1)
		countmin = (ft_lstsize(list[1]) - countmin) * (-1);
	liste = list[1];
	while (liste->content != arrayb[0])
	{
		liste = liste->next;
		countmax++;
	}
	if (countmax > ((ft_lstsize(list[1]) + 1) / 2) - 1)
		countmax = (ft_lstsize(list[1]) - countmax) * (-1);
	pushol2(list, countmin, countmax, topush);
}

int	quarttopush(t_list *lista, int minb)
{
	t_list	*liste;
	int		i;

	liste = lista;
	i = 0;
	while (liste->content < minb && liste->next != NULL)
	{
		liste = liste->next;
		i++;
	}
	if (!i && listismin(lista, minb) && ft_lstlast(lista)->content > minb)
	{
		if (lastmin(lista, minb) > (ft_lstsize(lista) / 2) - 1)
			i = (ft_lstsize(lista) - (lastmin(lista, minb))) * -1;
		else
			i = lastmin(lista, minb);
	}
	return (i);
}

int	listismin(t_list *lista, int min)
{
	int		test;
	t_list	*liste;

	liste = lista;
	test = 0;
	if (liste->content < min)
		test = 1;
	while (liste->next != NULL && !test)
	{
		liste = liste->next;
		if (liste->content < min)
			test = 1;
	}
	return (test);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jforner <jforner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 16:00:38 by jforner           #+#    #+#             */
/*   Updated: 2022/02/07 15:29:45 by jforner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pushswap.h"

t_list	*place_list(t_list *list, int place)
{
	int		i;
	t_list	*liste;

	i = -1;
	liste = list;
	while (++i < place && liste->next != NULL)
		liste = liste->next;
	return (liste);
}

int	exitsb1(t_list **ls, int src, int *ar, int *i)
{
	if (src > ar[(ft_lstsize(ls[1])) / 2])
	{
		if (src < ls[1]->content && src > ls[1]->next->content)
			return (1);
		return (0);
	}
	i[0]++;
	return (0);
}

int	sortingb1(t_list **ls, int src, int *ar)
{
	static int	i = 0;
	int			place;

	if (ft_lstsize(ls[1]) >= 2)
		place = determineplace(ar, src, ls);
	while (ls[1] != NULL && ft_lstsize(ls[1]) >= 2)
	{
		if (place > i)
		{
			ls[1] = rrotate_ab(ls[1], 'b');
			i++;
		}
		else if (place < i && !(src > ls[1]->next->content && i <= 0))
		{
			if ((ft_lstsize(ls[1]) == 2 && istidy(ls[1], 1))
				|| ft_lstsize(ls[1]) > 2)
				ls[1] = rotate_ab(ls[1], 'b');
			i--;
		}
		else
			return (exitsb1(ls, src, ar, &i));
	}
	if (ft_lstsize(ls[1]) == 1 && src < ls[1]->content)
		return (1);
	return (0);
}

int	inser_1h(t_list **list, int maxlen)
{
	static int	phase = 0;
	int			*array;

	array = createplace(list[1], ft_lstsize(list[1]));
	if (phase && !inser_test(list[0], 0))
		swap_ss(&list[0], &list[1]);
	else if (!inser_test(list[0], 0))
		list[0] = swap_ab(list[0], 'a');
	else if (phase)
		list[1] = swap_ab(list[1], 'b');
	if (istidy(list[0], ft_lstsize(list[0]) - 1)
		&& ft_lstsize(list[0]) == maxlen)
		return (0);
	phase = sortingb1(list, (*list)->content, array);
	push_ab(&list[0], &list[1], 'b');
	free(array);
	return (1);
}

void	inser_2h(t_list **list, int asize)
{
	if ((ft_lstsize(list[1]) > 1 && inser_test(list[1], 0)) && !is3ddy(list)
		&& (ft_lstsize(list[1]) > 2
			&& list[1]->content > place_list(list[1], 2)->content))
		swap_ss(&list[0], &list[1]);
	else if (!is3ddy(list))
		list[0] = swap_ab(list[0], 'a');
	else if ((ft_lstsize(list[1]) > 1 && inser_test(list[1], 0))
		&& (ft_lstsize(list[1]) > 2
			&& list[1]->content > place_list(list[1], 2)->content))
		list[1] = swap_ab(list[1], 'b');
	sortingb2(list);
	if (list[1]->content > list[0]->content)
	{
		if (list[0]->next->content > list[1]->content)
			list[0] = rotate_ab(list[0], 'a');
		else
			list[0] = rrotate_ab(list[0], 'a');
	}
	sortinga(list, asize);
}

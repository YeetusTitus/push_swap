/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jforner <jforner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 16:00:38 by jforner           #+#    #+#             */
/*   Updated: 2022/02/07 14:22:09 by jforner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pushswap.h"

int	*createplace(t_list *l, int len)
{
	int	*array;
	int	i;

	array = (int *)malloc(len * sizeof(int));
	i = -1;
	while (++i < len)
		array[i] = place_list(l, i)->content;
	createplace2(&array, len);
	return (array);
}

void	createplace2(int **array, int len)
{
	int	i;
	int	tiddy;
	int	temp;

	tiddy = 0;
	while (!tiddy)
	{
		i = -1;
		tiddy = 1;
		while (++i < len - 1)
		{
			if (array[0][i] < array[0][i + 1])
			{
				temp = array[0][i + 1];
				array[0][i + 1] = array[0][i];
				array[0][i] = temp;
				tiddy = 0;
			}
		}
	}
}

int	determineplace(int *array, int src, t_list **ls)
{
	int	place;

	place = -1;
	while (++place < ft_lstsize(ls[1]))
	{
		if (src > array[place])
			break ;
	}
	if (src < array[(ft_lstsize(ls[1])) / 2])
		place = ft_lstsize(ls[1]) - place;
	else if (src > array[(ft_lstsize(ls[1])) / 2])
		place *= (-1);
	return (place);
}

void	sortingb2(t_list **ls)
{
	while (!ristidy(ls[1], ft_lstsize(ls[1])))
	{
		if (ls[1]->content < ft_lstlast(ls[1])->content)
			ls[1] = rotate_ab(ls[1], 'b');
		else
			ls[1] = rrotate_ab(ls[1], 'b');
	}
}

void	sortinga(t_list **ls, int asize)
{
	int			*array;

	array = createplace(ls[0], ft_lstsize(ls[0]));
	while (asize > 0)
	{
		if (ft_lstlast(ls[0])->content > ls[1]->content
			&& ft_lstlast(ls[0])->content != array[0])
			ls[0] = rrotate_ab(ls[0], 'a');
		else
		{
			push_ab(&ls[1], &ls[0], 'a');
			asize--;
		}
	}
	free(array);
	while (!istidy(ls[0], ft_lstsize(ls[0])))
		ls[0] = rrotate_ab(ls[0], 'a');
}

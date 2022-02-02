/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jforner <jforner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 16:00:38 by jforner           #+#    #+#             */
/*   Updated: 2022/02/02 18:27:13 by jforner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pushswap.h"

int	*createplace(t_list **l, int len)
{
	int	*array;
	int	i;

	array = (int *)malloc(len * sizeof(int));
	i = -1;
	while (++i < len)
		array[i] = place_list(l[1], i)->content;
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
	while (++place < (int)ft_strlen((char *)array))
	{
		if (src > array[place])
			break ;
	}
	if (src > array[(ft_lstsize(ls[1]) + 1) / 2])
		place *= (-1);
	else if (src < array[(ft_lstsize(ls[1]) + 1) / 2])
		place = ft_lstsize(ls[1]) - place;
	return (place);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jforner <jforner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 12:19:30 by jforner           #+#    #+#             */
/*   Updated: 2022/02/14 19:03:00 by jforner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pushswap.h"

int	*rcreateplace(t_list *l, int len)
{
	int	*array;
	int	i;

	array = (int *)malloc(len * sizeof(int));
	i = -1;
	while (++i < len)
		array[i] = place_list(l, i)->content;
	rcreateplace2(&array, len);
	return (array);
}

void	rcreateplace2(int **array, int len)
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
			if (array[0][i] > array[0][i + 1])
			{
				temp = array[0][i + 1];
				array[0][i + 1] = array[0][i];
				array[0][i] = temp;
				tiddy = 0;
			}
		}
	}
}

void	rushb(int min, int max, t_list **list, int *arraya)
{
	while (listinarray(list[0], arraya, max, min))
	{
		if (nbrinarray(list[0]->content, arraya, max, min))
			push_ab(&list[0], &list[1], 'b');
		else if (nbrinarray(list[0]->next->content, arraya, max, min))
			list[0] = swap_ab(list[0], 'a');
		else
			list[0] = rotate_ab(list[0], 'a');
	}
}

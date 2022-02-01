/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jforner <jforner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 16:00:38 by jforner           #+#    #+#             */
/*   Updated: 2022/02/01 17:26:54 by jforner          ###   ########.fr       */
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
		array[i] = -2147483648;
	i = -1;
	while (++i < len)
		array[i] = createplace2(l, array, i);
	return (array);
}

int	createplace2(t_list **l, int *array, int i)
{
	int	k;
	int	j;
	int	max;

	k = -1;
	max = -2147483648;
	while (++k < ft_lstsize(l[1]))
	{
		j = -1;
		while (++j <= i)
			if ((max > array[j] || (array[j] == -2147483648
						&& max == -2147483648))
				&& max < place_list(l[1], k)->content)
				max = place_list(l[1], k)->content;
	}
	printf("max :%d\n", max);
	return (max);
}

int	determineplace(int *array, int src)
{
	int	place;

	place = -1;
	while (++place < (int)ft_strlen((char *)array))
	{
		if (src > array[place])
			break ;
	}
	if (src > array[(ft_strlen((char *)array) + 1) / 2])
		place *= (-1);
	else if (src < array[(ft_strlen((char *)array) + 1) / 2])
		place = ft_strlen((char *)array) - place;
	return (place);
}

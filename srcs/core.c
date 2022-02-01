/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jforner <jforner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 17:00:31 by jforner           #+#    #+#             */
/*   Updated: 2022/01/28 11:23:58 by jforner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pushswap.h"

void	core10(int argc, t_list **list)
{
	// int	i;
	// i = 0;
	list[1] = NULL;
	while (ft_lstsize(list[0]) > 3)
	{
		// printf("To clear :  %d place\n", place);
		// if ((place + 1 <= (argc / 2) && !(argc % 2))
		// 	|| (place + 1 <= (argc / 2) + 1 && (argc % 2)))
		inser_1h(list, argc);
		// else
		// 	inser_2h(list, place, &conta);
		if (istidy(*list, ft_lstsize(*list)))
			break ;
	}
	// printf("\nNbr turn : %d\n", i); //enlever
}

void	core(int argc, t_list **list)
{
	core10(argc - 1, list);
}

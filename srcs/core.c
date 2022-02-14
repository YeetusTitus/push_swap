/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jforner <jforner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 17:00:31 by jforner           #+#    #+#             */
/*   Updated: 2022/02/14 19:38:09 by jforner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pushswap.h"

void	core3(t_list **list)
{
	if (!is3ddy(list))
		list[0] = swap_ab(list[0], 'a');
	if (inser_test(list[0], 0) && !inser_test(list[0], 1))
		list[0] = rrotate_ab(list[0], 'a');
	if (!inser_test(list[0], 0) && inser_test(list[0], 1))
		list[0] = rotate_ab(list[0], 'a');
}

void	core50(int argc, t_list **list)
{
	list[1] = NULL;
	while (!istidy(*list, ft_lstsize(*list)) || ft_lstsize(*list) != argc)
	{
		if (ft_lstsize(list[0]) > 3)
			inser_1h(list, argc);
		else
			inser_2h(list, ft_lstsize(list[1]));
	}
}

void	core100(int argc, t_list **list)
{
	int	quart;

	list[1] = NULL;
	quart = 0;
	while (!istidy(*list, ft_lstsize(*list)) && quart++ < 4)
	{
		quicks(list, quart, argc);
	}
}

int	core(int argc, t_list **list)
{
	if (istidy(*list, ft_lstsize(*list)))
		return (1);
	if (argc == 3)
		list[0] = swap_ab(list[0], 'a');
	else if (argc == 4)
		core3(list);
	else if (argc <= 51)
		core50(argc - 1, list);
	else
		core100(argc - 1, list);
	return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jforner <jforner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 18:40:19 by jforner           #+#    #+#             */
/*   Updated: 2022/01/21 16:37:35 by jforner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/pushswap.h"

int	main(int argc, char **argv)
{
	char	error;
	t_list	*list;
	// t_list	*list2;

	if (!parse(argc, argv, &error))
		return (ft_puterror(&error));
	createlist(argc, argv, &list);
	ft_lstsize(list);
	core(argc, &list);
	// ft_lstsize(list);
	return (0);
}

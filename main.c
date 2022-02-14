/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jforner <jforner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 18:40:19 by jforner           #+#    #+#             */
/*   Updated: 2022/02/14 19:37:36 by jforner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/pushswap.h"

int	main(int argc, char **argv)
{
	char	error;
	t_list	*list;

	if (!parse(&argc, &argv, &error))
		return (ft_puterror(&error));
	createlist(argc, argv, &list);
	core(argc, &list);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jforner <jforner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 18:40:19 by jforner           #+#    #+#             */
/*   Updated: 2022/01/14 19:08:52 by jforner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/pushswap.h"

int	main(int argc, char **argv)
{
	char	error;
	t_list	*list;

	if (!parse(argc, argv, &error))
		return (ft_puterror(&error));
	createlist(argc, argv, &list);
	return (1);
}

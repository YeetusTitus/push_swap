/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puterror.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jforner <jforner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 15:10:17 by jforner           #+#    #+#             */
/*   Updated: 2022/01/13 17:52:44 by jforner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pushswap.h"

int	ft_puterror(char *error)
{
	if (*error != '0')
	{
		ft_putstr_fd("Error", 1);
	}
	ft_putchar_fd('\n', 1);
	return (0);
}

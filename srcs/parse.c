/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jforner <jforner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 13:18:27 by jforner           #+#    #+#             */
/*   Updated: 2022/02/08 15:45:34 by jforner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pushswap.h"

int	verif_int(char **argv, int argc, char *error)
{
	int	i;

	i = 0;
	while (++i < argc)
	{
		if (ft_atol(argv[i]) < -2147483648 || ft_atol(argv[i]) > 2147483647)
		{
			*error = '1';
			return (0);
		}
	}
	return (1);
}

int	verif_isdigit(int argc, char **argv, char *error)
{
	int	i;
	int	j;

	i = 0;
	while (++i < argc)
	{
		j = -1;
		while (argv[i][++j])
		{
			if ((argv[i][0] < '0' || argv[i][0] > '9') && argv[i][0] != '-'
				&& argv[i][0] != '+')
			{
				*error = '1';
				return (0);
			}
			if ((argv[i][j] < '0' || argv[i][j] > '9') && j > 0)
			{
				*error = '1';
				return (0);
			}
		}
	}
	return (1);
}

int	verif_doublon(int argc, char **argv, char *error)
{
	int	i;
	int	j;

	i = 0;
	while (++i < argc)
	{
		j = i;
		while (++j < argc)
		{
			if (ft_strcmp(argv[i], argv[j]))
			{
				*error = '1';
				return (0);
			}
		}
	}
	return (1);
}

void	oneargp(int *argc, char ***argv)
{
	char	*str;

	str = ft_substr(argv[0][1], 0, ft_strlen(argv[0][1]));
	*argv = ft_split(str, ' ');
	*argc = tablen(*argv);
	free (str);
}

int	parse(int *argc, char ***argv, char *error)
{
	*error = '0';
	if (*argc == 1)
		return (0);
	if (*argc == 2)
		oneargp(argc, argv);
	if (argv == NULL)
		return (0);
	if (!verif_isdigit(*argc, *argv, error)
		|| !verif_doublon(*argc, *argv, error)
		|| !verif_int(*argv, *argc, error))
		return (0);
	return (1);
}

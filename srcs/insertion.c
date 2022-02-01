/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jforner <jforner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 16:00:38 by jforner           #+#    #+#             */
/*   Updated: 2022/02/01 16:51:23 by jforner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pushswap.h"

t_list	*place_list(t_list *list, int place)
{
	int		i;
	t_list	*liste;

	i = -1;
	liste = list;
	while (++i < place && liste->next != NULL)
		liste = liste->next;
	return (liste);
}

int	sortingb1(t_list **ls, int src, int *ar)
{
	static int	i = 0;
	int			place;

	place = determineplace(ar, src);
	while (ls[1] != NULL && ft_lstsize(ls[1]) >= 2)
	{
		if (place > i)
		{
			ls[1] = rrotate_ab(ls[1], 'b');
			i++;
		}
		else if (place < i && !(src > ls[1]->next->content && i <= 0))
		{
			ls[1] = rotate_ab(ls[1], 'b');
			i--;
		}
		else
		{
			if (src < ar[(ft_strlen((char *)ar) + 1) / 2])
				i++;
			break ;
		}
	// ft_putstr_fd("------\n", 1);
	// ft_lstprint(ls[1], 'B');
	// ft_putchar_fd('\n', 1);
	}
	// printf("Place = %d\ti = %d\tar half = %d\n",place, i, ar[(ft_strlen((char *)ar) + 1) / 2]);
	// ft_putstr_fd("=====\n", 1);
	// ft_lstprint(ls[1], 'B');
	// ft_putchar_fd('\n', 1);
	return (place - i);
}

int	inser_1h(t_list **list, int maxlen)
{
	static int	phase = 0;
	static int	printo = 0;
	int			*array;

	printo++;
	array = createplace(list, ft_lstsize(list[1]));
	if (phase && !inser_test(list[0], 0))
		swap_ss(&list[0], &list[1]);
	else if (!inser_test(list[0], 0))
		list[0] = swap_ab(list[0], 'a');
	else if (phase)
		list[1] = swap_ab(list[1], 'b');
	if (istidy(list[0], ft_lstsize(list[0]) - 1)
		&& ft_lstsize(list[0]) == maxlen)
		return (0);
	phase = sortingb1(list, (*list)->content, array);
	push_ab(&list[0], &list[1], 'a');
	free(array);
	// printf("Tour %d :\n", printo);
	// ft_lstprint(list[0], 'A');
	// ft_lstprint(list[1], 'B');
	// ft_putchar_fd('\n', 1);
	return (1);
}
// int	inser_2h(t_list **list, int place, int **conta)
// {
// 	int			phase;
// 	// int			count;

// 	phase = 0;
// 	// count = 0;
// 	(*conta)[place] = place_list(*list, place)->content;
// 	// if (place == 4)
// 		// printf("0: %d\t1: %d\t2: %d\t3: %d\t4: %d\n",(*conta)[0],(*conta)[1],(*conta)[2],(*conta)[3],(*conta)[4]);
// 	// ft_putchar_fd('\n', 1);
// 	while (!istidy(*list, place - 1) || !inplace(*list, *conta, place))
// 	{
// 		if ( && phase <= 1)
// 		{
// 			*list = swap_ab(*list, 'a');
// 			phase = 1;
// 		}
// 		else if (phase == 0 || phase == 2)
// 			*list = rrotate_ab(*list, 'a');
// 		else if (phase == 1 && )
// 			*list = rotate_ab(*list, 'a');
// 		else
// 		{
// 			// count -= 1;
// 			phase = 2;
// 		}
// 		// count += 1;
// 		// if (phase == 1)
// 		// 	ft_putstr_fd("Phase 1\n", 1);
// 		if (istidy(*list, ft_lstsize(*list)) && ft_lstsize(*list))
// 			break ;
// 	}
// }

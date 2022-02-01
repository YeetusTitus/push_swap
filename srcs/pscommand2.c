/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pscommand2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jforner <jforner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 13:18:42 by jforner           #+#    #+#             */
/*   Updated: 2022/01/17 15:32:51 by jforner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pushswap.h"

t_list	*rrotate_ab(t_list *lst, char chr)
{
	t_list	*temp;
	t_list	*temp2;

	temp = ft_lstlast(lst);
	temp2 = lst;
	while (lst->next->next != NULL)
		lst = lst->next;
	lst->next = NULL;
	temp->next = temp2;
	if (chr == 'a')
		ft_putstr_fd("rra\n", 1);
	else if (chr == 'b')
		ft_putstr_fd("rrb\n", 1);
	return (temp);
}

void	rrotate_rrr(t_list **lsta, t_list **lstb)
{
	*lsta = rrotate_ab(*lsta, 's');
	*lstb = rrotate_ab(*lstb, 's');
	ft_putstr_fd("rrr\n", 1);
}

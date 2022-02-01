/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pscommand.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jforner <jforner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 10:03:16 by jforner           #+#    #+#             */
/*   Updated: 2022/01/21 14:42:00 by jforner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pushswap.h"

t_list	*swap_ab(t_list *lst, char chr)
{
	t_list	*temp;

	temp = lst->next;
	lst->next = lst->next->next;
	temp->next = lst;
	if (chr == 'a')
		ft_putstr_fd("sa\n", 1);
	else if (chr == 'b')
		ft_putstr_fd("sb\n", 1);
	return (temp);
}

void	swap_ss(t_list **lsta, t_list **lstb)
{
	*lsta = swap_ab(*lsta, 's');
	*lstb = swap_ab(*lstb, 's');
	ft_putstr_fd("ss\n", 1);
}

void	push_ab(t_list **src, t_list **dest, char chr)
{
	t_list	*temps;
	t_list	*tempd;

	temps = (*src)->next;
	tempd = *dest;
	(*src)->next = *dest;
	*dest = *src;
	*src = temps;
	if (chr == 'a')
		ft_putstr_fd("pa\n", 1);
	else if (chr == 'b')
		ft_putstr_fd("pb\n", 1);
}

t_list	*rotate_ab(t_list *lst, char chr)
{
	t_list	*temp;

	temp = lst->next;
	lst->next = NULL;
	ft_lstlast(temp)->next = lst;
	if (chr == 'a')
		ft_putstr_fd("ra\n", 1);
	else if (chr == 'b')
		ft_putstr_fd("rb\n", 1);
	return (temp);
}

void	rotate_rr(t_list **lsta, t_list **lstb)
{
	*lsta = rotate_ab(*lsta, 's');
	*lstb = rotate_ab(*lstb, 's');
	ft_putstr_fd("rr\n", 1);
}

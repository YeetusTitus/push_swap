/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   listfunctions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jforner <jforner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 17:12:28 by jforner           #+#    #+#             */
/*   Updated: 2022/02/14 19:35:48 by jforner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pushswap.h"

t_list	*ft_lstnew(int content)
{
	t_list	*liste;

	liste = malloc(sizeof(t_list));
	liste->content = content;
	liste->next = NULL;
	return (liste);
}

int	ft_lstsize(t_list *lst)
{
	int		i;

	i = 0;
	while (lst)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*liste;

	liste = lst;
	while (liste->next != NULL)
		liste = liste->next;
	return (liste);
}

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	ft_lstlast(*alst)->next = new;
}

void	ft_lstadd_front(t_list **alst, t_list *new)
{
	new->next = alst[0];
	alst[0] = new;
}

// int	ft_lstprint(t_list *lst, char chr)
// {
// 	int		i;

// 	i = 0;
// 	while (lst)
// 	{
// 		printf("List %c : %d\n", chr, lst->content);
// 		i++;
// 		lst = lst->next;
// 	}
// 	printf("=======\n");
// 	return (i);
// }

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jforner <jforner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 12:18:26 by jforner           #+#    #+#             */
/*   Updated: 2022/02/01 17:22:19 by jforner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

typedef struct s_list
{
	int					content;
	int					place;
	struct s_list		*next;
}	t_list;

//parse
int		parse(int argc, char **argv, char *error);
int		verif_doublon(int argc, char **argv, char *error);
int		verif_isdigit(int argc, char **argv, char *error);

//parse utils
int		ft_strcmp(char *str, char *str1);

//utils
void	ft_putchar_fd(char chr, int fd);
void	ft_putstr_fd(char *str, int fd);
size_t	ft_strlen(char *str);

//error
int		ft_puterror(char *error);

//listfunctions
t_list	*ft_lstnew(int content);
void	ft_lstadd_front(t_list **alst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **alst, t_list *new);
//to bannish
int		ft_lstprint(t_list *lst, char chr);

//createlist
int		ft_atoi(char *str);
void	createlist(int argc, char **argv, t_list **list);

//pscommand
t_list	*swap_ab(t_list *lst, char chr);
void	push_ab(t_list **src, t_list **dest, char chr);
void	swap_ss(t_list **lsta, t_list **lstb);
t_list	*rotate_ab(t_list *lst, char chr);
t_list	*rotate_ab(t_list *lst, char chr);
void	rotate_rr(t_list **lsta, t_list **lstb);

//pscommand2
t_list	*rrotate_ab(t_list *lst, char chr);
void	rrotate_rrr(t_list **lsta, t_list **lstb);

//testing
int		istidy(t_list *list, int place);
int		inser_test(t_list *list, int nbr);
int		inplace(t_list *list, int *conta, int place);

//core
void	core(int argc, t_list **list);
void	core10(int argc, t_list **list);

//insertion
t_list	*place_list(t_list *list, int place);
int		sortingb1(t_list **ls, int src, int *ar);
int		inser_1h(t_list **list, int maxlen);

//insertion 2
int		*createplace(t_list **l, int len);
int		createplace2(t_list **l, int *array, int i);
int		determineplace(int *array, int src);
// int		inser_2h(t_list **list, int place, int **conta);
#endif

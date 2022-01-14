/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jforner <jforner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 12:18:26 by jforner           #+#    #+#             */
/*   Updated: 2022/01/14 19:04:08 by jforner          ###   ########.fr       */
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

//createlist
int		ft_atoi(char *str);
void	createlist(int argc, char **argv, t_list **list);

#endif

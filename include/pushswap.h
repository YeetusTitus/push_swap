/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jforner <jforner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 12:18:26 by jforner           #+#    #+#             */
/*   Updated: 2022/02/14 19:38:18 by jforner          ###   ########.fr       */
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
int		parse(int *argc, char ***argv, char *error);
int		verif_doublon(int argc, char **argv, char *error);
int		verif_isdigit(int argc, char **argv, char *error);
int		verif_int(char **argv, int argc, char *error);

//parse utils
int		ft_strcmp(char *str, char *str1);
int		tablen(char **tab);
long	ft_atol(char *str);

//utils
void	ft_putchar_fd(char chr, int fd);
void	ft_putstr_fd(char *str, int fd);
size_t	ft_strlen(char *str);
int		samesign(int nb1, int nb2);
int		posit(int nbr);

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
int		is3ddy(t_list **list);
int		ristidy(t_list *list, int place);

//core
int		core(int argc, t_list **list);
void	core50(int argc, t_list **list);
void	core100(int argc, t_list **list);
void	core3(t_list **list);

//insertion
t_list	*place_list(t_list *list, int place);
int		sortingb1(t_list **ls, int src, int *ar);
int		inser_1h(t_list **list, int maxlen);
int		exitsb1(t_list **ls, int src, int *ar, int *i);
void	inser_2h(t_list **list, int asize);

//insertion 2
int		*createplace(t_list *l, int len);
void	createplace2(int **array, int len);
int		determineplace(int *array, int src, t_list **ls);
void	sortingb2(t_list **ls);
void	sortinga(t_list **ls, int asize);

//split
char	**ft_split(char const *s, char c);
int		ft_malloc_error(char **tab, int size);
int		ft_splitage(char const *s, char c, char **tab, unsigned int nb_word);
int		ft_tablen(char const *str,
			char sep, char ***tab, unsigned int *nb_word);

//libft
char	*ft_substr(char const *s, unsigned int start, size_t len);
void	*ft_memset(void *str, char c, size_t n);
void	*ft_calloc(size_t nmemb, size_t size);
char	*ft_fullstr(char const *s, unsigned int start, size_t len, char *str);

//quick
void	quicks(t_list **list, int quart, int len);
int		nbrinarray(int nbr, int *array, int max, int min);
int		listinarray(t_list *list, int *array, int max, int min);
void	qsorting(int min, int max, t_list **list, int *arraya);
int		lastmin(t_list *lista, int minb);

//quick2
void	pushol3(t_list **list, int count, int topush);
void	pushol2(t_list **list, int countmin, int countmax, int topush);
void	pushol(t_list **list, int *arrayb, int topush);
int		quarttopush(t_list *lista, int minb);
int		listismin(t_list *lista, int min);

//quick3
int		*rcreateplace(t_list *l, int len);
void	rcreateplace2(int **array, int len);
void	rushb(int min, int max, t_list **list, int *arraya);
#endif

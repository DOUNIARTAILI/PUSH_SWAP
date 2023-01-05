/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drtaili <drtaili@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 16:38:31 by drtaili           #+#    #+#             */
/*   Updated: 2023/01/05 04:52:33 by drtaili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct stacknode{
	int					data;
	struct stacknode	*next;
}t_node;

void				sa(struct stacknode *head, int status);
void				sb(struct stacknode *head, int status);
void				ss(struct stacknode *head_a, struct stacknode *head_b);
void				pa(struct stacknode **head_a,
						struct stacknode **head_b, int status);
void				pb(struct stacknode **head_a,
						struct stacknode **head_b, int status);
void				ra(struct stacknode **head, int status);
void				rb(struct stacknode **head, int status);
void				rr(struct stacknode **head_a, struct stacknode **head_b);
void				rra(struct stacknode **head, int status);
void				rrb(struct stacknode **head, int status);
void				rrr(struct stacknode **head_a, struct stacknode **head_b);
t_node				*newnode(int data);
int					is_empty(struct stacknode *head);
void				push(struct stacknode **head, int data);
void				pop(struct stacknode **head);
void				rev_pop(struct stacknode **head);
void				displaystack(struct stacknode *head);
int					size_stack(struct stacknode *head);
void				free_stack(t_node *head);
size_t				ft_strlcpy(char *dst, const char *src, size_t dstsize);
char				*ft_strdup(const char *s1);
char				*ft_substr(char const *s, unsigned int start, size_t len);
void				ft_putstr(char *s);
size_t				ft_strlen(const char *s);
void				ft_putnbr(int n);
void				*ft_calloc(size_t count, size_t size);
void				ft_bzero(void *s, size_t n);
void				*ft_memset(void *b, int c, size_t len);
void				error_(t_node *head);
t_node				*parsing(int argc, char **argv);
int					is_already_sorted(t_node *head);
char				**ft_split(char const *s, char c);
t_node				*indexing(struct stacknode *head);
t_node				*tab_to_stack(int *tab, int size);
void				sort_3(struct stacknode **head_ptr);
void				sort_5(t_node *head, t_node *head_b);
void				sort_100(t_node *head_a, t_node *head_b);
void				search_stack_node(t_node **head_b, int data);
void				fill_up_b(t_node **head_a, t_node **head_b);

#endif
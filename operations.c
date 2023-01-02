/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drtaili <drtaili@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 12:49:59 by drtaili           #+#    #+#             */
/*   Updated: 2023/01/02 03:33:23 by drtaili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strlen(const char *s)
{
	int	len;

	len = 0;
	while (s[len] != '\0')
		len++;
	return (len);
}

void	ft_putstr(char *s)
{
	if (!s)
		return ;
	write(1, s, ft_strlen(s));
}

void	sa(struct stacknode *head, int status)
{
	struct stacknode	*tmp;
	int					cup;

	if (is_empty(head) == 0 || size_stack(head) == 1)
		return ;
	if (status == 1)
		ft_putstr("sa\n");
	tmp = head;
	cup = tmp->data;
	tmp->data = tmp->next->data;
	tmp->next->data = cup;
}

void	sb(struct stacknode *head, int status)
{
	if (status == 1)
		ft_putstr("sb\n");
	sa(head, 0);
}

void	ss(struct stacknode *head_a, struct stacknode *head_b)
{
	ft_putstr("ss\n");
	sa(head_a, 0);
	sb(head_b, 0);
}

void	pa(struct stacknode **head_a, struct stacknode **head_b, int status)
{
	struct stacknode	*tmp_b;

	if (is_empty(*head_b) == 0)
		return ;
	tmp_b = *head_b;
	if (status == 1)
		ft_putstr("pa\n");
	push(head_a, tmp_b->data);
	pop(head_b);
}

void	pb(struct stacknode **head_a, struct stacknode **head_b, int status)
{
	if (is_empty(*head_a) == 0)
		return ;
	if (status == 1)
		ft_putstr("pb\n");
	pa(head_b, head_a, 0);
}

void	ra(struct stacknode **head, int status)
{
	struct stacknode	*tmp;
	struct stacknode	*cup;

	cup = (*head);
	(*head) = (*head)->next;
	tmp = *head;
	if (status == 1)
		ft_putstr("ra\n");
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = cup;
	cup->next = NULL;
}

void	rb(struct stacknode **head, int status)
{
	if (status == 1)
		ft_putstr("rb\n");
	ra(head, 0);
}

void	rr(struct stacknode **head_a, struct stacknode **head_b)
{
	ft_putstr("rr\n");
	ra(head_a, 0);
	rb(head_b, 0);
}

void	rra(struct stacknode **head, int status)
{
	struct stacknode	*tmp;

	tmp = *head;
	if (status == 1)
		ft_putstr("rra\n");
	while (tmp->next != NULL)
		tmp = tmp->next;
	push(head, tmp->data);
	rev_pop(head);
}

void	rrb(struct stacknode **head, int status)
{
	if (status == 1)
		ft_putstr("rb\n");
	rra(head, 0);
}

void	rrr(struct stacknode **head_a, struct stacknode **head_b)
{
	ft_putstr("rrr\n");
	rra(head_a, 0);
	rrb(head_b, 0);
}

// a = tmp b = tmp->next c = tmp->next->next
void	swap_3(struct stacknode *head) 
{
	struct stacknode *tmp;

	tmp = head;
	if (tmp->data < tmp->next->data && tmp->next->data < tmp->next->next->data)
		return ;
	else if(tmp->next->next->data < tmp->data && tmp->data < tmp->next->data)
		rra(&head, 1);
	else if(tmp->next->data < tmp->next->next->data && tmp->next->next->data < tmp->data)
		ra(&head, 1);
	else if(tmp->next->data < tmp->data && tmp->data < tmp->next->next->data)
	{
		ra(&head, 1);
		sa(head, 1);
	}
	else if(tmp->next->next->data < tmp->next->data && tmp->next->data < tmp->data)
	{
		sa(head, 1);
		ra(&head, 1);
	}
	else if(tmp->data < tmp->next->next->data && tmp->next->next->data < tmp->next->data)
		sa(head, 1);
}

// void indexing()
// {
// 	int tab[5];
// 	int i;
// 	int j;
// 	int k;

// 	k = 0;
// 	tab[k] = 0;
// 	i = 0;
// 	j = 1;
// 	while (j < 5)
// 	{
// 		while (i < j)                                
// 		{
// 			k = i - 1;
// 			if (tab[i] > tab[j])
// 				tab[i]++;
// 			else if (tab[i] < tab[j])
// 				tab[j]++;	
// 			else if (i > 0 && k >= 0 && tab[i] > tab[j])
// 			{
// 				tab[i]++;
// 				if(tab[j] > tab[k])
// 					tab[j]++;
// 				else
// 					tab[k]++;
// 				k--;
// 			}
// 			else if(i > 0 && k >= 0 && tab[i] < tab[j])
// 			{
// 				tab[j]++;
// 				if(tab[j] > k)
// 					tab[j]++;
// 				else
// 					tab[k]++;
// 				k--;
// 			}
// 			i++;	
// 		}
// 		j++;
// 	}
// }

int search_node(struct stacknode *head, int i)
{
	int cpt;
	struct stacknode *tmp;

	cpt = -1;
	tmp = head;
	while (tmp != NULL)
	{
		cpt++; 
		if (cpt == i)
			return tmp->data;
		tmp = tmp->next;
	}
	return 0;
}

static void index_update(int fval, int sval, int *findex, int *sindex)
{
	if (fval > sval)
		(*findex)++;
	else if (fval < sval)
		(*sindex)++;
}

int	*indexing(struct stacknode *head)
{
	int	*indexes;
	int	i;
	int	j;
	t_node *a;
	t_node *b;

	indexes = (int *)calloc(size_stack(head), sizeof(int));
	if (!indexes)
		return (NULL);
	i = 0;
	a = head;
	while (a->next)
	{
		j = i + 1;
		b = a->next;
		while (b) {
			index_update(a->data, b->data, &indexes[i], &indexes[j]);
			j++;
			b = b->next;
		}
		i++;
		a = a->next;
	}
	return (indexes);
}

// int main(struct stacknode *head)
// {
// 	// struct stacknode* head = NULL;
// 	// push(&head, -1);
// 	// push(&head, 3);
// 	// push(&head, 1);
// 	// displaystack(head);
// 	// swap_3(head);
	
// }
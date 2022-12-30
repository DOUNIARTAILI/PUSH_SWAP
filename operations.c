/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drtaili <drtaili@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 12:49:59 by drtaili           #+#    #+#             */
/*   Updated: 2022/12/30 18:45:51 by drtaili          ###   ########.fr       */
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

void  sa(struct stacknode *head)
{
    struct stacknode *tmp;
    int cup;

    if (is_empty(head) == 0 || size_stack(head) == 1)
        return ;
    ft_putstr("sa\n");
    tmp = head;    
    cup = tmp->data;
	tmp->data = tmp->next->data;
    tmp->next->data = cup;
}

void  sb(struct stacknode *head)
{
    struct stacknode *tmp;
    int cup;

    if (is_empty(head) == 0 || size_stack(head) == 1)
        return ;
    ft_putstr("sb\n");
    tmp = head;    
    cup = tmp->data;
	tmp->data = tmp->next->data;
    tmp->next->data = cup;
}

void  ss(struct stacknode *head_a, struct stacknode *head_b)
{
    struct stacknode *tmp_a;
    struct stacknode *tmp_b;
    int cup_a;
    int cup_b;

    if (is_empty(head_a) == 0 || size_stack(head_a) == 1)
        return ;
    ft_putstr("ss\n");
    tmp_a = head_a;    
    cup_a = tmp_a->data;
	tmp_a->data = tmp_a->next->data;
    tmp_a->next->data = cup_a;
    tmp_b = head_b;    
    cup_b = tmp_b->data;
	tmp_b->data = tmp_b->next->data;
    tmp_b->next->data = cup_b;
}

void    pa(struct stacknode **head_a, struct stacknode **head_b)
{
    if (is_empty(*head_b) == 0)
        return ;
    struct stacknode *tmp_b;

    tmp_b = *head_b;
    ft_putstr("pa\n");
    push(head_a, tmp_b->data);
    pop(head_b);
}

void    pb(struct stacknode **head_a, struct stacknode **head_b)
{
    if (is_empty(*head_a) == 0)
        return ;
    struct stacknode *tmp_a;

    tmp_a = *head_a;
    ft_putstr("pb\n");
    push(head_b, tmp_a->data);
    pop(head_a);
}

void  ra(struct stacknode **head)
{
    struct stacknode *tmp;
    struct stacknode *node;
    int cup;

    cup = (*head)->data;
    (*head) = (*head)->next;
    tmp = *head;
    while (tmp->next != NULL)
        tmp = tmp->next;
    node = newnode(cup);
    node->next = NULL;
    tmp->next = node;
}

void  rb(struct stacknode **head)
{
    struct stacknode *tmp;
    struct stacknode *node;
    int cup;

    cup = (*head)->data;
    (*head) = (*head)->next;
    tmp = *head;
    while (tmp->next != NULL)
        tmp = tmp->next;
    node = newnode(cup);
    node->next = NULL;
    tmp->next = node;
}

void  rra(struct stacknode **head)
{
    struct stacknode *tmp;
    tmp = *head;
    ft_putstr("ra\n");
    while (tmp->next != NULL)
        tmp = tmp->next;
    push(head, tmp->data);
    rev_pop(head);
}

void  rrb(struct stacknode **head)
{
    struct stacknode *tmp;
    tmp = *head;
    ft_putstr("rb\n");
    while (tmp->next != NULL)
        tmp = tmp->next;
    push(head, tmp->data);
    rev_pop(head);
}

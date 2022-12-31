/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drtaili <drtaili@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 12:49:59 by drtaili           #+#    #+#             */
/*   Updated: 2022/12/31 16:20:55 by drtaili          ###   ########.fr       */
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

void  sa(struct stacknode *head, int status)
{
    struct stacknode *tmp;
    int cup;

    if (is_empty(head) == 0 || size_stack(head) == 1)
        return ;
    if (status == 1)
        ft_putstr("sa\n");
    tmp = head;    
    cup = tmp->data;
	tmp->data = tmp->next->data;
    tmp->next->data = cup;
}

void  sb(struct stacknode *head, int status)
{
    if (status == 1)
        ft_putstr("sb\n");
    sa(head, 0);
}

void  ss(struct stacknode *head_a, struct stacknode *head_b)
{
    ft_putstr("ss\n");
    sa(head_a, 0);
    sb(head_b, 0);
}

void    pa(struct stacknode **head_a, struct stacknode **head_b, int status)
{
    struct stacknode *tmp_b;

    if (is_empty(*head_b) == 0)
        return ;
    tmp_b = *head_b;
    if (status == 1)
        ft_putstr("pa\n");
    push(head_a, tmp_b->data);
    pop(head_b);
}

void    pb(struct stacknode **head_a, struct stacknode **head_b, int status)
{
    if (is_empty(*head_a) == 0)
        return ;
    if (status == 1)
        ft_putstr("pb\n");
    pa(head_b, head_a, 0);
}

void  ra(struct stacknode **head, int status)
{
    struct stacknode *tmp;
    struct stacknode *cup;

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

void  rb(struct stacknode **head, int status)
{
    if (status == 1)
        ft_putstr("rb\n");
    ra(head, 0);
}

void  rr(struct stacknode **head_a, struct stacknode **head_b)
{
    ft_putstr("rr\n");
    ra(head_a, 0);
    rb(head_b, 0);
}
void  rra(struct stacknode **head, int status)
{
    struct stacknode *tmp;
    tmp = *head;
    if (status == 1)
        ft_putstr("ra\n");
    while (tmp->next != NULL)
        tmp = tmp->next;
    push(head, tmp->data);
    rev_pop(head);
}

void  rrb(struct stacknode **head, int status)
{
    if (status == 1)
        ft_putstr("rb\n");
    rra(head, 0);
}

void  rrr(struct stacknode **head_a, struct stacknode **head_b)
{
    ft_putstr("rrr\n");
    rra(head_a, 0);
    rrb(head_b, 0);
}
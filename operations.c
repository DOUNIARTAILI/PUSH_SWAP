/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drtaili <drtaili@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 12:49:59 by drtaili           #+#    #+#             */
/*   Updated: 2023/01/04 05:57:59 by drtaili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

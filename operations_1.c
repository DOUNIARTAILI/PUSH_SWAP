/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drtaili <drtaili@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 05:18:55 by drtaili           #+#    #+#             */
/*   Updated: 2023/01/04 05:57:50 by drtaili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

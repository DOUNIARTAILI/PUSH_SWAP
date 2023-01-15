/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drtaili <drtaili@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 05:19:45 by drtaili           #+#    #+#             */
/*   Updated: 2023/01/15 22:11:46 by drtaili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rrr(struct stacknode **head_a, struct stacknode **head_b)
{
	ft_putstr("rrr\n");
	rra(head_a, 0);
	rrb(head_b, 0);
}

void	push(struct stacknode **head, int data)
{
	struct stacknode	*node;

	node = newnode(data);
	node->next = *head;
	*head = node;
}

void	pop(struct stacknode **head)
{
	struct stacknode	*tmp;

	tmp = *head;
	if (is_empty(*head) == 0)
		return ;
	(*head) = (*head)->next;
	free(tmp);
}

void	rev_pop(struct stacknode **head)
{
	struct stacknode	*tmp;

	tmp = *head;
	if (is_empty(*head) == 0)
		return ;
	while (tmp->next->next != NULL)
		tmp = tmp->next;
	tmp->next = NULL;
	free(tmp->next);
}

t_node	*newnode(int data)
{
	struct stacknode	*node;

	node = (struct stacknode *)malloc(sizeof(struct stacknode));
	if (!node)
		return (NULL);
	node->data = data;
	node->next = NULL;
	return (node);
}

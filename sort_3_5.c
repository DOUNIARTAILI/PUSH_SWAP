/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3_5.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drtaili <drtaili@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 05:02:17 by drtaili           #+#    #+#             */
/*   Updated: 2023/01/04 06:19:06 by drtaili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_3(struct stacknode **head_ptr)
{
	struct stacknode	*head;
	struct stacknode	*tmp;

	head = *head_ptr;
	tmp = head;
	if (tmp->data < tmp->next->data && tmp->next->data < tmp->next->next->data)
		return ;
	else if (tmp->next->next->data < tmp->data && tmp->data < tmp->next->data)
		rra(&head, 1);
	else if (tmp->next->data < tmp->next->next->data
		&& tmp->next->next->data < tmp->data)
		ra(&head, 1);
	else if (tmp->next->data < tmp->data && tmp->data < tmp->next->next->data)
	{
		ra(&head, 1);
		sa(head, 1);
	}
	else if (tmp->next->next->data < tmp->next->data
		&& tmp->next->data < tmp->data)
	{
		sa(head, 1);
		ra(&head, 1);
	}
	else if (tmp->data < tmp->next->next->data
		&& tmp->next->next->data < tmp->next->data)
		sa(head, 1);
	*head_ptr = head;
}

void	sort_5(t_node *head, t_node *head_b)
{
	int	i;

	i = 0;
	while (i < 5)
	{
		if (head->data < 2)
			pb(&head, &head_b, 1);
		else
			ra(&head, 1);
		i++;
	}
	sort_3(&head);
	if (head_b->data < head_b->next->data)
		sb(head, 1);
	pa(&head, &head_b, 1);
	pa(&head, &head_b, 1);
}

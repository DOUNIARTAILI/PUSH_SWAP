/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3_5.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drtaili <drtaili@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 05:02:17 by drtaili           #+#    #+#             */
/*   Updated: 2023/01/10 12:14:32 by drtaili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_3(struct stacknode **head_ptr)
{
	struct stacknode	*head;
	struct stacknode	*tmp;
	int					first;
	int					second;
	int					third;

	head = *head_ptr;
	tmp = head;
	first = tmp->data;
	second = tmp->next->data;
	third = tmp->next->next->data;
	if (first < second && second > third && third < first)
		rra(&head, 1);
	else if (first > second && second < third && third < first)
		ra(&head, 1);
	else if (first > second && second < third && third > first)
		sa(head, 1);
	else if (first > second && second > third && third < first)
	{
		sa(head, 1);
		rra(&head, 1);
	}
	else if (first < second && second > third && third > first)
	{
		rra(&head, 1);
		sa(head, 1);
	}
	*head_ptr = head;
}

// void	sort_5(t_node **head_a, t_node *head_b)
// {
// 	t_node	*head;
// 	int		i;

// 	i = 0;
// 	head = *head_a;
// 	while (i < 5)
// 	{
// 		if (head->data < 2)
// 			pb(&head, &head_b, 1);
// 		else
// 			ra(&head, 1);
// 		i++;
// 	}
// 	sort_3(&head);
// 	if (head_b->data < head_b->next->data)
// 		sb(head_b, 1);
// 	pa(&head, &head_b, 1);
// 	pa(&head, &head_b, 1);
// 	*head_a = head; 
// }

void	sort_5(t_node **head_a)
{
	t_node	*head;
	t_node *head_b;
	int		i;

	i = 0;
	head_b = NULL;
	head = *head_a;
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
		sb(head_b, 1);
	pa(&head, &head_b, 1);
	pa(&head, &head_b, 1);
	*head_a = head; 
}

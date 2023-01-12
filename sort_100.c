/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_100.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drtaili <drtaili@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 23:03:42 by drtaili           #+#    #+#             */
/*   Updated: 2023/01/12 21:26:34 by drtaili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	search_stack_node(t_node **head_b, int val)
{
	int		i;
	t_node	*tmp;

	i = 0;
	tmp = *head_b;
	while (tmp)
	{
		if (tmp->data == val)
			break ;
		tmp = tmp->next;
		i++;
	}
	if (!tmp)
		return ;
	if (i < size_stack(*head_b) / 2)
		while ((*head_b)->data != val)
			rb(head_b, 1);
	else
		while ((*head_b)->data != val)
			rrb(head_b, 1);
}

void	fill_up_b(t_node **head_a_ptr, t_node *head_b)
{
	t_node	*head_a;
	int		cup_size;
	int		data;
	int		s;

	s = 0;
	head_a = *head_a_ptr;
	while (size_stack(head_a) > 3)
	{
		cup_size = size_stack(head_a) / 3;
		while (size_stack(head_b) < cup_size + s)
		{
			if (head_a->data < cup_size + s && head_a->data >= s)
			{
				if (head_a->data <= (cup_size / 2) + s)
				{
					pb(&head_a, &head_b, 1);
					rb(&head_b, 1);
				}
				else
					pb(&head_a, &head_b, 1);
			}
			else
				ra(&head_a, 1);
		}
		s += cup_size;
	}
	sort_3(&head_a);
	while (size_stack(head_b))
	{
		data = head_a->data;
		search_stack_node(&head_b, data - 1);
		pa(&head_a, &head_b, 1);
	}
	*head_a_ptr = head_a;
}

void	sort_100(t_node **head_a, t_node *head_b)
{
	fill_up_b(head_a, head_b);
}

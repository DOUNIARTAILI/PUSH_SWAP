/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_over_100.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drtaili <drtaili@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 11:31:10 by drtaili           #+#    #+#             */
/*   Updated: 2023/01/12 19:55:39 by drtaili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	search_stack_node_over_100(t_node **head_a, t_node **head_b, int val)
{
	int				i;
	int				x;
	int				last;
	t_node	*tmp_b;
	t_node	*tmp_a;

	i = 0;
	tmp_b = *head_b;
	tmp_a = *head_a;
	last = ft_stacklast(head_a);
	while (val == ft_stacklast(head_a))
	{
		rra(head_a, 1);
		val--;
	}
	x = ft_stacklast(head_a);
	if (x > (*head_a)->data)
	{
		x = 0;
		// pa(head_a, head_b, 1);
		// ra(head_a, 1);
	}
	while (tmp_b)
	{
		if (tmp_b->data == val)
			break ;
		tmp_b = tmp_b->next;
		i++;
	}
	if (!tmp_b)
		return ;
	while ((*head_b)->data != val)
	{
		if (((*head_b)->data > x))
		{
			x = (*head_b)->data;
			pa(head_a, head_b, 1);
			ra(head_a, 1);
		}
		else
		{
			if (i < size_stack(*head_b) / 2)
				rb(head_b, 1);
			else
				rrb(head_b, 1);
		}
	}
}

void    sort_500(t_node **head_a_ptr, t_node *head_b)
{
	t_node	*head_a;
    int cup_size;
	int data;
	int s;

	s = 0;
	head_a = *head_a_ptr;
	while (size_stack(head_a) > 3)
	{
		cup_size = size_stack(head_a) / 3;
		while (size_stack(head_b) < cup_size + s && size_stack(head_a) > 3)
		{
			// printf("nbr == %d cup =%d\ts=%d\tsize_b=%d\n",head_a->data,cup_size,s,size_stack(head_b));
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
		search_stack_node_over_100(&head_a, &head_b, head_a->data - 1);
		pa(&head_a, &head_b, 1);
	}
	// displaystack(head_a);
	// while (size_stack(head_b))
	// {
	// 	data = head_a->data;
	// 	search_stack_node(&head_b, data - 1);
	// 	pa(&head_a, &head_b, 1);
	// }
	*head_a_ptr = head_a;
}


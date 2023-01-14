/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_over_100.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drtaili <drtaili@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 11:31:10 by drtaili           #+#    #+#             */
/*   Updated: 2023/01/14 21:21:24 by drtaili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	where_is_val(t_node *head_b, int val)
{
	t_node			*tmp_b;
	int				i;

	i = 0;
	tmp_b = head_b;
	if (!tmp_b)
		return (0);
	while (tmp_b)
	{
		if (tmp_b->data == val)
			break ;
		tmp_b = tmp_b->next;
		i++;
	}
	return (i);
}

void	search_stack_node_over_100(t_node **head_a, t_node **head_b, int val)
{
	int				i;
	int				x;

	x = ft_stacklast(head_a);
	if (x > (*head_a)->data)
		x = 0;
	i = where_is_val(*head_b, val);
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

void	sort_over_100(t_node **head_a_ptr, t_node *head_b)
{
	t_node	*head_a;
	int		data;
	int		s;

	s = 0;
	head_a = *head_a_ptr;
	fill_up_b(&head_a, &head_b);
	sort_3(&head_a);
	while (size_stack(head_b))
	{
		data = head_a->data;
		while (data - 1 == ft_stacklast(&head_a))
		{
			rra(&head_a, 1);
			data--;
		}
		search_stack_node_over_100(&head_a, &head_b, head_a->data - 1);
		pa(&head_a, &head_b, 1);
	}
	*head_a_ptr = head_a;
}

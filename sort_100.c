/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_100.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drtaili <drtaili@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 23:03:42 by drtaili           #+#    #+#             */
/*   Updated: 2023/01/05 05:15:35 by drtaili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	fill_up_b(t_node **a, t_node **b)
{
	t_node *head_a = *a;
	t_node *head_b = *b;

	int	start;
	int	end;
	int	size_a;
	int	i;

	size_a = size_stack(head_a);
	start = 0;
	end = 0;
	while (size_a > 3)
	{
		if (end != 0)
			start = end + 1;
		end += size_a / 3;
		i = 0;
		while (i < size_a)
		{
			if (start <= head_a->data && head_a->data <= end)
			{
				pb(&head_a, &head_b, 1);
				size_a--;
				if (head_a->data < ((start + end) / 2))
					rb(&head_b, 1);
			}
			else
				ra(&head_a, 1);
			i++;
		}
	}

	*a = head_a;
	*b = head_b;
}

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

// void    fill_up_b(t_node *head_a, t_node *head_b)
// {
// 	int	size_a;
// 	int	size_b;
//     int cup_size;
//     int	i;

// 	size_a = size_stack(head_a);
// 	size_b = size_stack(head_b);
// 	while (size_a > 3)
// 	{
// 		cup_size = size_a / 3;
// 		i = 0;
// 		while (i < cup_size && head_a->data <= cup_size + size_b && head_a->data >= size_b)
// 		{
// 			if (head_a->data < (cup_size / 2) + size_b)
//     	    {
// 				pb(&head_a, &head_b, 1);
//     	        rb(&head_b, 1);
//     	    }
// 			else
//     	        pb(&head_a, &head_b, 1);
// 			i++;
// 		}
// 	}
// }

// int	search_stack_node(t_node *head_b, int data)
// {
// 	int	i;
// 	int	size_b;

// 	size_b = size_stack(head_b);
// 	i = 0;
// 	while(i < size_b)
// 	{
// 		if(head_b->data == data)
// 			return (1);
// 		else
// 			rb(&head_b, 1);
// 		i++;
// 	}
// 	return (0);
// }

void    sort_100(t_node *head_a, t_node *head_b)
{
	int	tmp;

	fill_up_b(&head_a, &head_b);
	sort_3(&head_a);
	while (size_stack(head_b))
	{
		tmp = head_a->data;
		search_stack_node(&head_b, tmp - 1);
		pa(&head_a, &head_b, 1);
	}
	while (head_a)
	{
		printf("%d ", head_a->data);
		head_a = head_a->next;
	}
}
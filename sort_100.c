/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_100.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drtaili <drtaili@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 23:03:42 by drtaili           #+#    #+#             */
/*   Updated: 2023/01/08 14:38:28 by drtaili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void	fill_up_b(t_node **a, t_node **b)
// {
// 	t_node *head_a = *a;
// 	t_node *head_b = *b;

// 	int	start;
// 	int	end;
// 	int	size_a;
// 	int	i;

// 	size_a = size_stack(head_a);
// 	start = 0;
// 	end = 0;
// 	while (size_a > 3)
// 	{
// 		if (end != 0)
// 			start = end + 1;
// 		end += size_a / 3;
// 		i = 0;
// 		while (i < size_a)
// 		{
// 			if (start <= head_a->data && head_a->data <= end)
// 			{
// 				pb(&head_a, &head_b, 1);
// 				size_a--;
// 				if (head_a->data < ((start + end) / 2))
// 					rb(&head_b, 1);
// 			}
// 			else
// 				ra(&head_a, 1);
// 			i++;
// 		}
// 	}

// 	*a = head_a;
// 	*b = head_b;
// }

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

void    fill_up_b(t_node *head_a, t_node *head_b)
{
    int cup_size;
	int data;
	int s;

	s = 0;
	while (size_stack(head_a) > 3)
	{
		cup_size = size_stack(head_a) / 3;
		printf("cup_size:%d\ts:%d\n",cup_size,s);
		while (size_stack(head_b) < cup_size + s)
		{
			if (head_a->data < cup_size + s && head_a->data >= s)
			{
				printf("a=%d\tb=%d\n",size_stack(head_a),size_stack(head_b));
				printf("head=%d\n",head_a->data);
				if (head_a->data < (cup_size / 2) + s)
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
	puts("done");
	// displaystack(head_b);
	displaystack(head_a);
	sort_3(&head_a);
	printf("aand");
	displaystack(head_a);
	while (size_stack(head_b))
	{
		data = head_a->data;
		search_stack_node(&head_b, data - 1);
		pa(&head_a, &head_b, 1);
		// ra(&head_a, 1);
	}
	displaystack(head_b);
	displaystack(head_a);
}

// void	search_stack_node(t_node **head_b, int data)
// {
// 	int	i;
// 	t_node *tmp;
// 	int	size_b;

// 	tmp = *head_b;
// 	size_b = size_stack(*head_b);
// 	i = 0;
// 	while(i < size_b)
// 	{
// 		if(tmp->data == data)
// 			break;
// 		else
// 			rb(head_b, 1);
// 		i++;
// 	}
// }

void    sort_100(t_node *head_a, t_node *head_b)
{
	// int	tmp;

	fill_up_b(head_a, head_b);
	// sort_3(&head_a);
	// while (size_stack(head_b))
	// {
	// 	tmp = head_a->data;
	// 	search_stack_node(&head_b, tmp - 1);
	// 	pa(&head_a, &head_b, 1);
	// }
	// while (head_a)
	// {
	// 	printf("%d ", head_a->data);
	// 	head_a = head_a->next;
	// }
}
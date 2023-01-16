/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drtaili <drtaili@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 05:00:51 by drtaili           #+#    #+#             */
/*   Updated: 2023/01/16 23:24:29 by drtaili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	index_update(int aval, int bval, int *aindex, int *bindex)
{
	if (aval > bval)
		(*aindex)++;
	else if (aval < bval)
		(*bindex)++;
	else
	{
		write(2, "Error \n", 7);
		exit(0);
	}
}

t_node	*indexing(struct stacknode *head)
{
	int		*indexes;
	int		i;
	int		j;
	t_node	*a;
	t_node	*b;

	indexes = (int *)ft_calloc(size_stack(head), sizeof(int));
	if (!indexes)
		return (NULL);
	i = 0;
	a = head;
	while (a->next)
	{
		j = i + 1;
		b = a->next;
		while (b)
		{
			index_update(a->data, b->data, &indexes[i], &indexes[j]);
			j++;
			b = b->next;
		}
		i++;
		a = a->next;
	}
	return (tab_to_stack(indexes, size_stack(head)));
}

t_node	*tab_to_stack(int *tab, int size)
{
	t_node	*head;
	t_node	*tmp;
	int		i;

	head = NULL;
	tmp = head;
	i = 0;
	while (i < size)
	{
		push(&head, tab[i]);
		i++;
	}
	return (head);
}

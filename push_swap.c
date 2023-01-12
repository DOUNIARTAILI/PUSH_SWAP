/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drtaili <drtaili@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 12:01:00 by drtaili           #+#    #+#             */
/*   Updated: 2023/01/12 22:28:08 by drtaili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int	main(int argc, char **argv)
{
	t_node	*head;
	t_node	*head_b;
	t_node	*indexed;

	head_b = NULL;
	indexed = NULL;
	head = parsing(argc, argv);
	indexed = indexing(head);
	if (is_already_sorted(indexed))
		exit(0);
	if (size_stack(indexed) == 3)
		sort_3(&indexed);
	else if (size_stack(indexed) == 4)
		sort_4(&indexed);
	else if (size_stack(indexed) == 5)
		sort_5(&indexed);
	else if (size_stack(indexed) > 5 && size_stack(indexed) <= 100)
		sort_100(&indexed, head_b);
	else if (size_stack(indexed) > 100)
		sort_500(&indexed, head_b);
	// puts("**-**");
}

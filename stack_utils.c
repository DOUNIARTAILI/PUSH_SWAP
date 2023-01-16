/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drtaili <drtaili@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 05:22:06 by drtaili           #+#    #+#             */
/*   Updated: 2023/01/17 00:20:27 by drtaili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_empty(struct stacknode *head)
{
	return (size_stack(head));
}

void	displaystack(struct stacknode *head)
{
	struct stacknode	*tmp;

	tmp = head;
	while (tmp != NULL)
	{
		ft_putnbr(tmp->data);
		ft_putstr("\n");
		tmp = tmp->next;
	}
	ft_putstr("\n");
}

int	size_stack(struct stacknode *head)
{
	int					len;
	struct stacknode	*tmp;

	len = 0;
	tmp = head;
	while (tmp != NULL)
	{
		len++;
		tmp = tmp->next;
	}
	return (len);
}

void	free_stack(t_node *head)
{
	t_node	*tmp;

	while (head != NULL)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
}

int	ft_stacklast(t_node **head)
{
	t_node	*tmp;

	tmp = *head;
	if (!tmp)
		return (0);
	while (tmp->next != NULL)
		tmp = tmp->next;
	return (tmp->data);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drtaili <drtaili@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 12:01:00 by drtaili           #+#    #+#             */
/*   Updated: 2023/01/15 22:11:42 by drtaili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	if (size_stack(indexed) == 2)
		sort_2(&indexed);
	else if (size_stack(indexed) == 3)
		sort_3(&indexed);
	else if (size_stack(indexed) == 4)
		sort_4(&indexed);
	else if (size_stack(indexed) == 5)
		sort_5(&indexed);
	else if (size_stack(indexed) > 5 && size_stack(indexed) <= 100)
		sort_100(&indexed, head_b);
	else if (size_stack(indexed) > 100)
		sort_over_100(&indexed, head_b);
}

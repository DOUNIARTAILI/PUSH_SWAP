/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drtaili <drtaili@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 16:32:59 by drtaili           #+#    #+#             */
/*   Updated: 2023/01/15 23:37:46 by drtaili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*ss1;
	unsigned char	*ss2;
	size_t			i;

	ss1 = (unsigned char *)s1;
	ss2 = (unsigned char *)s2;
	i = 0;
	while (i < n && (ss1[i] && ss2[i]))
	{
		if (ss1[i] != ss2[i])
			return (ss1[i] - ss2[i]);
		i++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_node	*head;
	t_node	*head_b;
	t_node	*indexed;
	char	*line;
	t_node	*tmp;
	int i;
	int cpt;
	i = 0;
	cpt = 0;

	head_b = NULL;
	indexed = NULL;
	head = parsing(argc, argv);
	indexed = indexing(head);
	// if (is_already_sorted(indexed))
	// 	exit(0);
	line = get_next_line(0);
	while (line)
	{
		if (ft_strncmp(line, "sa\0", 3) == 0)
		{
			printf("line : %s\n", line);
				sa(indexed, 0);}
		else if (ft_strncmp(line, "sb\0", 3) == 0)
			sb(indexed, 0);
		else if (ft_strncmp(line, "ss\0", 3) == 0)
			ss(indexed, head_b);
		else if (ft_strncmp(line, "pa\0", 3) == 0)
			pa(&indexed, &head_b, 0);
		else if (ft_strncmp(line, "pb\0", 3) == 0)
			pb(&indexed, &head_b, 0);
		else if (ft_strncmp(line, "ra", 3) == 0)
			ra(&indexed, 0);
		else if (ft_strncmp(line, "rb", 3) == 0)
			rb(&indexed, 0);
		else if (ft_strncmp(line, "rr", 3) == 0)
			rr(&indexed, &head_b);
		else if (ft_strncmp(line, "rra", 4) == 0)
			rra(&indexed, 0);
		else if (ft_strncmp(line, "rrb", 4) == 0)
			rrb(&indexed, 0);
		else if (ft_strncmp(line, "rrr", 4) == 0)
			rrr(&indexed, &head_b);
		// else
		// 	error_(indexed);
		free(line);
		line = get_next_line(0);
	}
	puts("***");
	displaystack(indexed);
	puts("****");
	tmp = indexed;
	while (tmp)
	{
		if (tmp->data == i)
			cpt++;
		else
			break;
		i++;
		tmp = tmp->next;
	}
	if (cpt == size_stack(indexed))
		write (1, "ok\n", 3);
	else
		write(1, "ko\n", 3);
}
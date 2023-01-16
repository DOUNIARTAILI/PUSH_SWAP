/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drtaili <drtaili@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 16:32:59 by drtaili           #+#    #+#             */
/*   Updated: 2023/01/17 00:54:09 by drtaili          ###   ########.fr       */
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

void	which_op_to_apply(t_node **indexed, t_node **head_b, char *line)
{
	if (ft_strncmp(line, "sa\n", 3) == 0)
		sa(*indexed, 0);
	else if (ft_strncmp(line, "sb\n", 3) == 0)
		sb(*head_b, 0);
	else if (ft_strncmp(line, "ss\n", 3) == 0)
		ss(*indexed, *head_b, 0);
	else if (ft_strncmp(line, "pa\n", 3) == 0)
		pa(indexed, head_b, 0);
	else if (ft_strncmp(line, "pb\n", 3) == 0)
		pb(indexed, head_b, 0);
	else if (ft_strncmp(line, "ra\n", 3) == 0)
		ra(indexed, 0);
	else if (ft_strncmp(line, "rb\n", 3) == 0)
		rb(head_b, 0);
	else if (ft_strncmp(line, "rr\n", 3) == 0)
		rr(indexed, head_b, 0);
	else if (ft_strncmp(line, "rra\n", 4) == 0)
		rra(indexed, 0);
	else if (ft_strncmp(line, "rrb\n", 4) == 0)
		rrb(head_b, 0);
	else if (ft_strncmp(line, "rrr\n", 4) == 0)
		rrr(indexed, head_b, 0);
	else
		error_(*indexed);
}

int	is_sorted(t_node **indexed)
{
	t_node	*tmp;
	int		i;
	int		cpt;

	tmp = *indexed;
	i = 0;
	cpt = 0;
	while (tmp)
	{
		if (tmp->data == i)
			cpt++;
		else
			break ;
		i++;
		tmp = tmp->next;
	}
	return (cpt);
}

int	main(int argc, char **argv)
{
	t_node	*head;
	t_node	*head_b;
	t_node	*indexed;
	char	*line;
	int		cpt;

	cpt = 0;
	head_b = NULL;
	indexed = NULL;
	head = parsing(argc, argv);
	indexed = indexing(head);
	line = get_next_line(0);
	while (line)
	{
		which_op_to_apply(&indexed, &head_b, line);
		free(line);
		line = get_next_line(0);
	}
	cpt = is_sorted(&indexed);
	if (cpt == size_stack(indexed))
		write (1, "ok\n", 3);
	else
		write(1, "ko\n", 3);
}

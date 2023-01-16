/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drtaili <drtaili@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 17:08:14 by drtaili           #+#    #+#             */
/*   Updated: 2023/01/17 00:20:39 by drtaili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error_(t_node *head)
{
	(void)head;
	write(2, "Error \n", 7);
	exit(EXIT_FAILURE);
}

void	atoi_check(const char *str, int *i, int *s)
{
	while (str[*i] == ' ' || str[*i] == '\n' || str[*i] == '\t'
		|| str[*i] == '\v' || str[*i] == '\f' || str[*i] == '\r')
		(*i)++;
	if (str[*i] == '+' || str[*i] == '-')
	{
		if (str[*i] == '-')
			(*s) = (*s) * (-1);
		(*i)++;
	}
}

int	ft_atoi(const char *str, t_node *head)
{
	long	r;
	int		i;
	int		s;
	int		count;

	i = 0;
	r = 0;
	count = 0;
	s = 1;
	atoi_check(str, &i, &s);
	while (str[i] <= '9' && str[i] >= '0')
	{
		r = r * 10 + (str[i] - '0');
		count++;
		if (count > 10 && r != 0)
			error_(head);
		i++;
	}
	if (str[i] != ' ' && str[i] != '\0')
		error_(head);
	if ((r * s) < -2147483648 || (r * s) > 2147483647)
		error_(head);
	return (r * s);
}

t_node	*parsing(int argc, char **argv)
{
	t_node	*head;
	char	**splits;
	int		i;
	int		j;

	head = NULL;
	i = 1;
	if (argc == 1)
		exit(0);
	while (i < argc)
	{
		splits = ft_split(argv[i], ' ');
		j = 0;
		if (!splits[j])
			error_(head);
		while (splits[j])
		{
			push(&head, ft_atoi(splits[j], head));
			free(splits[j]);
			j++;
		}
		free(splits);
		i++;
	}
	return (head);
}

int	is_already_sorted(t_node *head)
{
	t_node	*tmp;

	tmp = head;
	while (tmp && tmp->next)
	{
		if (tmp->data > tmp->next->data)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

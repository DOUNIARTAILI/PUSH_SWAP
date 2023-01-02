/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drtaili <drtaili@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 12:01:00 by drtaili           #+#    #+#             */
/*   Updated: 2023/01/02 06:11:56 by drtaili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

struct stacknode	*newnode(int data)
{
	struct stacknode	*node;

	node = (struct stacknode *)malloc(sizeof(struct stacknode));
	node->data = data;
	node->next = NULL;
	return (node);
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

int	is_empty(struct stacknode *head)
{
	return (size_stack(head));
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

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int n)
{
	unsigned int	nb;

	nb = (unsigned int)n;
	if (n < 0)
	{
		ft_putchar('-');
		nb = n * -1;
	}
	if (nb <= 9)
		ft_putchar(nb + 48);
	else
	{
		ft_putnbr(nb / 10);
		ft_putchar(((nb % 10) + 48));
	}
}

void displaystack(struct stacknode *head)
{
	struct stacknode	*tmp;

	tmp = head;
	while (tmp != NULL)
	{
		printf("%d\n", tmp->data);
		tmp = tmp->next;
	}
}

// int main()
// {
// 	struct stacknode* head = NULL;
// 	struct stacknode* head_b = NULL;


// 	// puts("a");
// 	// push(&head, 50);
// 	// push(&head, 30);
// 	// push(&head, 4);
// 	// push(&head, 10);
// 	// // push(&head, 20);
// 	// displaystack(head);
// 	// puts("******");
// 	// rev_pop(&head);
// 	// displaystack(head);
// 	// puts("b");
// 	push(&head_b, 1);
// 	push(&head_b, 0);
// 	push(&head_b, 9);
// 	push(&head_b, 2);
// 	push(&head_b, 3);
// 	displaystack(head_b);
// 	puts("******");
// 	int *tab;
// 	int i;
// 	int n = 5;
// 	tab = indexing(head_b);
// 	for( i=4; i >= 0 ; i-- ) {
//       printf("%d ",tab[i]);
//     }
// 	// int x = search_node(head_b, 3);
// 	// printf("%d", x);
// 	// pop(&head);
// 	// displaystack(head);
// 	// puts("******");
// 	// printf("%d popped from stack\n", pop(&head));
 
// 	// printf("number of element is %d\n", size_stack(head));
// 	// ss(head, head_b);
// 	// puts("******");
// 	// ss(head_b, head);
// 	// displaystack(head_b);
// 	// displaystack(head_b);
// 	// puts("\n");
// 	// displaystack(head);
// 	// pb(&head, &head_b);
// 	// puts("b");
// 	// displaystack(head_b);
// 	// puts("ra");
// 	// ra(&head);
// 	// pb(&head, &head_b);
// 	// pa(&head,&head_b, 1);
// 	// displaystack(head);
// 	// displaystack(head_b);
// 	// pb(&head,&head_b, 1);
// 	// displaystack(head);
	
// 	// sa(head_b, 1);
// 	// displaystack(head_b);
// 	return 0;
	
// }


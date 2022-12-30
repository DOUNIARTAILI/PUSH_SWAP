/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drtaili <drtaili@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 16:38:31 by drtaili           #+#    #+#             */
/*   Updated: 2022/12/30 18:46:13 by drtaili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
 
struct stacknode {
	int data;
	struct stacknode* next;
};

void				displaystack(struct stacknode *head);
void				pop(struct stacknode** head);
void				push(struct stacknode** head, int data);
int					size_stack(struct stacknode *head);
struct  stacknode*	newnode(int data);
void				sa(struct stacknode *head);
int					is_empty(struct stacknode *head);
void  				sb(struct stacknode *head);
void 				ss(struct stacknode *head_a, struct stacknode *head_b);
void				pa(struct stacknode **head_a, struct stacknode **head_b);
void				pb(struct stacknode **head_a, struct stacknode **head_b);
void				rra(struct stacknode **head);
void				rrb(struct stacknode **head);
void				rev_pop(struct stacknode** head);
void				ra(struct stacknode **head);
void				rb(struct stacknode **head);
#endif
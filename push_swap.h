/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drtaili <drtaili@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 16:38:31 by drtaili           #+#    #+#             */
/*   Updated: 2022/12/31 16:18:06 by drtaili          ###   ########.fr       */
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
void				sa(struct stacknode *head, int status);
int					is_empty(struct stacknode *head);
void  				sb(struct stacknode *head, int status);
void 				ss(struct stacknode *head_a, struct stacknode *head_b);
void				pa(struct stacknode **head_a, struct stacknode **head_b, int status);
void				pb(struct stacknode **head_a, struct stacknode **head_b, int status);
void				rra(struct stacknode **head, int status);
void				rrb(struct stacknode **head, int status);
void				rev_pop(struct stacknode** head);
void				ra(struct stacknode **head, int status);
void				rb(struct stacknode **head, int status);
void				rr(struct stacknode **head_a, struct stacknode **head_b);
#endif
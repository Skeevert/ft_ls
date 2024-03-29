/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshawand <hshawand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 13:34:24 by hshawand          #+#    #+#             */
/*   Updated: 2019/09/20 13:41:24 by hshawand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int			list_cmp(t_entlist *a, t_entlist *b)
{
	int		result;

	if (!(g_options & 0x10))
		result = ft_strcmp(a->ent_name, b->ent_name);
	else
	{
		result = b->time - a->time;
		if (!result)
			result = ft_strcmp(a->ent_name, b->ent_name);
	}
	return (g_options & 0x08 ? -result : result);
}

void		front_back_split(t_entlist *source, t_entlist **front_ref,
	t_entlist **back_ref)
{
	t_entlist	*fast;
	t_entlist	*slow;

	slow = source;
	fast = source->next;
	while (fast)
	{
		fast = fast->next;
		if (fast)
		{
			fast = fast->next;
			slow = slow->next;
		}
	}
	*front_ref = source;
	*back_ref = slow->next;
	slow->next = 0;
}

t_entlist	*sorted_merge(t_entlist *a, t_entlist *b)
{
	t_entlist	*result;

	result = 0;
	if (!a)
		return (b);
	else if (!b)
		return (a);
	if (list_cmp(a, b) <= 0)
	{
		result = a;
		result->next = sorted_merge(a->next, b);
	}
	else
	{
		result = b;
		result->next = sorted_merge(a, b->next);
	}
	return (result);
}

void		merge_sort(t_entlist **head_ref)
{
	t_entlist	*head;
	t_entlist	*a;
	t_entlist	*b;

	head = *head_ref;
	a = 0;
	b = 0;
	if (head == 0 || head->next == 0)
		return ;
	front_back_split(head, &a, &b);
	merge_sort(&a);
	merge_sort(&b);
	*head_ref = sorted_merge(a, b);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_ops.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Abdu-Rashid <Abdu-Rashid@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 16:01:06 by cdell             #+#    #+#             */
/*   Updated: 2022/07/30 22:41:42 by Abdu-Rashid      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static t_sl_list	*lst_get_last_node(t_sl_list *list)
{
	if (!list)
		return (NULL);
	while (list->next)
		list = list->next;
	return (list);
}

static t_sl_list	*lst_create_new_node(void *key, void *value)
{
	t_sl_list	*node;

	node = (t_sl_list *)malloc(sizeof (t_sl_list));
	if (!node)
		ft_puterror("Failed to allocate memory for token");
	node->key = key;
	node->value = value;
	node->next = NULL;
	return (node);
}

static void	lst_add_back_node(t_sl_list **list, t_sl_list *new_node)
{
	t_sl_list	*last;

	if (!new_node)
		return ;
	if (*list)
	{
		last = lst_get_last_node(*list);
		last->next = new_node;
	}
	else
		*list = new_node;
}

void	lst_clear(t_sl_list **list)
{
	t_sl_list	*tmp;

	if (!*list)
		return ;
	while (*list)
	{
		tmp = *list;
		*list = (*list)->next;
		free(tmp->value);
		free(tmp);
		tmp = NULL;
	}
	list = NULL;
}

void	lst_append_node(t_sl_list **list, void *key, void *value)
{
	t_sl_list	*node;

	node = lst_create_new_node(key, value);
	lst_add_back_node(list, node);
}

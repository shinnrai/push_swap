/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_max_seq.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofedorov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/23 13:22:51 by ofedorov          #+#    #+#             */
/*   Updated: 2016/12/23 13:22:52 by ofedorov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static t_list	*rec_find_seq(int *stack, int size, t_list *lst)
{
	int		prev_val;
	t_list	*curr;
	t_list	*val_incl;
	t_list	*val_nincl;

	if (size == 0)
		return (NULL);
	if (lst)
	{
		prev_val = *(int*)lst->content;
		while (size > 0 && stack[0] < prev_val)
		{
			stack++;
			size--;
		}
		if (!size)
			return (NULL);
	}
	curr = ft_lstnew(stack, sizeof(int));
	val_nincl = rec_find_seq(stack + 1, size - 1, lst);
	ft_lstadd(&lst, curr);
	val_incl = rec_find_seq(stack + 1, size - 1, lst);
	if (ft_lstlen(val_incl) + 1 > ft_lstlen(val_nincl))
	{
		ft_lstadd(&val_incl, curr);
		if (val_nincl)
			free(val_nincl);
		return (val_incl);
	}
	else
	{
		if (val_incl)
			free(val_incl);
		return (val_nincl);
	}
}

t_list *find_max_seq(t_info *info)
{
	t_list	*curr;
	t_list	*max;
	int 	size;

	max = NULL;
	size = info->a_size;
	while (size-- > 0)
	{
		curr = rec_find_seq(info->a, info->a_size, NULL);
		if (ft_lstlen(curr) > ft_lstlen(max))
			max = curr;
		exec_instr_ra(info);
	}
	return (curr);
}

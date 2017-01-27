/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofedorov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 11:13:41 by ofedorov          #+#    #+#             */
/*   Updated: 2017/01/10 11:13:42 by ofedorov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	del_info(t_info **info)
{
	free((*info)->a);
	free((*info)->b);
	free((*info)->ops);
	free(*info);
	*info = NULL;
}

void	del_rev_info(t_info **rev_info)
{
	free((*rev_info)->ops);
	free(*rev_info);
	*rev_info = NULL;
}

void	merge_infos(t_info *info, t_info *rev_info)
{
	char			*rev_ops;
	char 			*ops;
	register int	i;

	rev_ops = rev_info->ops;
	ops = ft_strnew(ft_strlen(rev_info->ops));
	i = -1;
	info->a_size = info->size;
	info->b_size = 0;
	while (*rev_ops)
	{
		++i;
		if (*rev_ops == 'a')
			ops[i] = 'b';
		else if (*rev_ops == 'b')
			ops[i] = 'a';
		else
			ops[i] = *rev_ops;
		rev_ops++;
	}
	if (*ops)
	{
		rev_ops = info->ops;
		info->ops = ft_strjoin(info->ops, ops);
		free(rev_ops);
	}
	free(ops);
}

t_info	*copy_info(t_info *info)
{
	t_info	*copy_info;

	copy_info = (t_info*)malloc(sizeof(t_info));
	copy_info->a = (int *)malloc(sizeof(int) * info->size);
	ft_memcpy(copy_info->a, info->a, sizeof(int) * info->size);
	copy_info->a_size = info->a_size;
	copy_info->b = (int *)malloc(sizeof(int) * info->size);
	ft_memcpy(copy_info->b, info->b, sizeof(int) * info->size);
	copy_info->b_size = info->b_size;
	copy_info->ops = ft_strdup(info->ops);
	copy_info->size = info->size;
	copy_info->color = info->color;
	copy_info->reversed = false;
	copy_info->display_number = info->display_number;
	copy_info->display_stacks = info->display_stacks;
	copy_info->each_op = info->each_op;
	copy_info->print_slow = info->print_slow;
	return (copy_info);
}

t_info	*reverse_info(t_info *info)
{
	t_info	*rev_info;

	rev_info = (t_info*)malloc(sizeof(t_info));
	rev_info->b = info->a;
	rev_info->b_size = info->a_size;
	rev_info->a = info->b;
	rev_info->a_size = info->b_size;
	rev_info->ops = ft_sstrnew(0);
	rev_info->size = info->size;
	rev_info->reversed = true;
	return (rev_info);
}
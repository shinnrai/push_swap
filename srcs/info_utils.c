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
		info->ops = ft_strjoin(info->ops, ops);//TODO free prev str
}

t_info	*reverse_info(t_info *info)
{
	t_info	*rev_info;

	rev_info = (t_info*)malloc(sizeof(t_info));
	rev_info->b = info->a;
	rev_info->b_size = info->a_size;
	rev_info->a = info->b;
	rev_info->a_size = info->b_size;
	rev_info->ops = ft_strnew(0);
	rev_info->size = info->size;
	rev_info->reversed = 1;
	return (rev_info);
}
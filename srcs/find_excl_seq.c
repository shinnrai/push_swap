/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_excl_seq.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofedorov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 13:24:26 by ofedorov          #+#    #+#             */
/*   Updated: 2017/01/18 13:24:28 by ofedorov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

//static int		count_size(int *curr, int size_arr)
//{
//	register int	i;
//	int 			size;
//
//	size = 0;
//	i = -1;
//	while (++i < size_arr)
//		if (curr[i])
//			size++;
//	return (size);
//}

//static int		*rec_seq(t_info *info, int ind, int start_ind, int *curr)
//{
//	register int	i;
//	int				prev_val;
//	int				*val_incl;
//	int				*val_nincl;
//
//	if ((ind + 1) % info->a_size == start_ind)
//		return (ft_memalloc(info->a_size * sizeof(int)));
//	if (count_size(curr, info->a_size))
//	{
//		i = ind;
//		while (i != start_ind && !curr[(i - 1 + info->a_size) % info->a_size])
//			i = (i - 1 + info->a_size) % info->a_size;
//		prev_val = curr[(i - 1 + info->a_size) % info->a_size];
//		while (ind != start_ind && curr[ind] < prev_val)
//			ind = (ind + 1) % info->a_size;
//		if (ind == start_ind)
//			return (ft_memalloc(info->a_size * sizeof(int)));
//	}
//	val_nincl = rec_seq(info, (ind + 1) % info->a_size, start_ind, curr);
//	curr[ind] = 1;
//	val_incl = rec_seq(info, (ind + 1) % info->a_size, start_ind, curr);
//	if (count_size(val_incl, info->a_size) + 1 >
//		count_size(val_nincl, info->a_size))
//	{
//		val_incl[ind] = 1;
//		free(val_nincl);
//		return (val_incl);
//	}
//	else
//	{
//		free(val_incl);
//		return (val_nincl);
//	}
//}

t_list	*find_excl(t_info *info);

static t_list	*find_seq(t_info *info)
{
	int	i;
//	int *tmp;
//	int *res;
//	int *max;
	t_list	*max;
	t_list	*tmp;

	i = -1;
	max = NULL;
	while (++i < info->a_size)
	{
		tmp = find_excl(info);
		if (!max)
			max = tmp;
		else if (ft_lstlen(tmp) >= ft_lstlen(max))
		{
			ft_lstdel(&max, ft_lstdelcontent);
			max = tmp;
		}
		else
			ft_lstdel(&tmp, ft_lstdelcontent);
		exec_instr(info, INSTR_RA);

//		tmp = ft_memalloc(sizeof(int) * info->a_size);
//		res = rec_seq(info, i, i, tmp);
//		if (max == NULL)
//			max = res;
//		else if (count_size(res, info->a_size) > count_size(max, info->a_size))
//		{
//			free(max);
//			max = res;
//		}
//		else
//			free(res);
//		free(tmp);
	}
	return (max);
}

static t_list	*transform(int *seq, t_info *info)
{
	t_list			*lst;
	register int	i;

	i = -1;
	lst = NULL;
	while (++i < info->a_size)
		if (seq[i])
			ft_lstaddend(&lst, ft_lstnew(&info->a[i], sizeof(int)));
	return (lst);
}

t_list			*find_excl_seq(t_info *info)
{
//	int 	*seq;
//
//	seq = find_seq(info);
	return (find_seq(info));
}






















//find from min, then if number is in this seq, can skip
t_list	*find_excl(t_info *info)
{
	register int	i;
	int 			prev_val;
	int 			*arr;

	i = -1;
	arr = ft_memalloc(info->a_size * sizeof(int));
	arr[0] = 1;
	prev_val = info->a[0];
	while (++i < info->a_size)
	{
		if (info->a[i] > prev_val)
		{
			arr[i] = 1;
			prev_val = info->a[i];
		}
	}
	return (transform(arr, info));
}

































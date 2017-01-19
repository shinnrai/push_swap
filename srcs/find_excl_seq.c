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

static int		count_size(int *curr, int size_arr)
{
	register int	i;
	int 			size;

	size = 0;
	i = -1;
	while (++i < size_arr)
		if (curr[i])
			size++;
	return (size);
}

static int		*rec_seq(t_info *info, int ind, int	*curr)
{
	register int	i;
	int				prev_val;
	int				*val_incl;
	int				*val_nincl;

	if (ind == info->a_size)
		return (NULL);
	if (count_size(curr, info->a_size))
	{
		i = ind;
		while (i > 0 && !curr[i - 1])
			i--;
		prev_val = curr[i - 1];
		while (ind < info->a_size && curr[ind] < prev_val)
			ind++;
		if (ind == info->a_size)
			return (NULL);
	}
	val_nincl = rec_seq(info, ind + 1, curr);
	curr[ind] = 1;
	val_incl = rec_seq(info, ind + 1, curr);
	if (count_size(val_incl, info->a_size) + 1 >
		count_size(val_nincl, info->a_size))
	{
		val_incl[ind] = 1;
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

static int		*find_seq(t_info *info)
{
	int *tmp;
	int *max;

	tmp = ft_memalloc(sizeof(int) * info->a_size);



}

static t_list	*transform(int *seq, t_info *info)
{
	t_list			*lst;
	register int	i;

	i = -1;
	lst = NULL;
	while (++i < info->a_size)
		if (seq[i])
			ft_lstadd(&lst, ft_lstnew(&info->a[i], sizeof(int)));
	return (lst);
}

t_list			*find_excl_seq(t_info *info)
{
	int 	*seq;

	seq = find_seq(info);
	return (transform(seq, info));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_ind.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofedorov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 12:29:07 by ofedorov          #+#    #+#             */
/*   Updated: 2017/01/11 12:29:09 by ofedorov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

/*
**	op[0] - number of operations
**	op[1] - instr to a and b if exists
**	op[2] - number in a
**	op[3] - number in b
**  op[4] - instr to a
**  op[5] - instr to b
*/

static int find_ind_b_to_push(t_info *info, int a_val)
{
	register int	i;
	int 			ind_max_in_b;
	int 			ind_min_in_b;

	i = 0;
	ind_max_in_b = 0;
	ind_min_in_b = 0;
	while (++i < info->b_size)
		if (info->b[i] < info->b[ind_min_in_b])
			ind_min_in_b = i;
		else if (info->b[i] > info->b[ind_max_in_b])
			ind_max_in_b = i;
	if (a_val > info->b[ind_max_in_b])
		return (ind_max_in_b);
	if (a_val < info->b[ind_min_in_b])
		return (ind_min_in_b + 1) % info->b_size;
	i = -1;
	while (++i < info->b_size)
		if (info->b[i] > a_val && info->b[(i + 1) % info->b_size] < a_val)
			return (i + 1) % info->b_size;
	return (-1);
}

static int	find_ind_rev_to_push(t_info *info, int a_val)
{
	register int	i;
	int 			ind_max_in_b;
	int 			ind_min_in_b;

	i = 0;
	ind_max_in_b = 0;
	ind_min_in_b = 0;
	while (++i < info->b_size) //finding max and min value in b
		if (info->b[i] < info->b[ind_min_in_b])
			ind_min_in_b = i;
		else if (info->b[i] > info->b[ind_max_in_b])
			ind_max_in_b = i;
	if (a_val > info->b[ind_max_in_b])
		return (ind_max_in_b + 1) % info->b_size;
	if (a_val < info->b[ind_min_in_b])
		return (ind_min_in_b);
	i = -1;
	while (++i < info->b_size)
		if (info->b[i] < a_val && info->b[(i + 1) % info->b_size] > a_val)
			return (i + 1) % info->b_size;
	return (-1);
}

int 		*calc_one(t_info *info, int i_a)
{
	register int	i_b;
	int				tmp;
	int				*op;

	if (info->b_size < 2)
		i_b = 0;
	else
		i_b = (info->reversed) ? find_ind_rev_to_push(info, info->a[i_a])
							   : find_ind_b_to_push(info, info->a[i_a]);
	op = (int*)malloc(sizeof(int) * 6);
	op[0] = (HOW_MANY_TO_ROTATE(i_a, info->a_size)) +
			(HOW_MANY_TO_ROTATE(i_b, info->b_size));
	op[1] = 0;
	op[2] = info->a[i_a];
	op[3] = info->b[i_b];
	op[4] = CHOOSE_INSTR_A(i_a, info->a_size);
	op[5] = CHOOSE_INSTR_B(i_b, info->b_size);
	if ((tmp = HOW_MANY_TO_RR(i_a, i_b)) <= op[0])
	{
		op[0] = tmp;
		op[1] = INSTR_RR;
	}
	if ((tmp = HOW_MANY_TO_RRR(i_a, i_b, info->a_size, info->b_size)) <= op[0])
	{
		op[0] = tmp;
		op[1] = INSTR_RRR;
	}
	return (op);
}

static int	**calc_how_many_ops(t_info *info)
{
	register int	i_a;
	int 			**ops;

	i_a = 0;
	ops = malloc(sizeof(int*) * info->a_size);
	while (i_a < info->a_size)
	{
		ops[i_a] = calc_one(info, i_a);
		i_a++;
	}
	return (ops);
}

int		*get_ind(t_info *info, t_list *excl)
{
	int 			i;
	int 			**ops;
	int 			min_ind;
	int 			*rot;

	if (info->a_size == 0)
		return (NULL); // check for this not here
	ops = calc_how_many_ops(info);
	min_ind = -1; // can cause seg fault
	i = -1;
	while (++i < info->a_size)
		if ((min_ind == -1 || ops[i][0] < ops[min_ind][0]) && !ft_lstfindfirst(excl, &info->a[i], sizeof(int)))
		{
			if (min_ind != -1)
				free(ops[min_ind]);
			min_ind = i;
		}
		else
			free(ops[i]);
	rot = (int*)malloc(sizeof(int) * 6);
	rot[0] = ops[min_ind][0];
	rot[1] = ops[min_ind][1];
	rot[2] = ops[min_ind][2];
	rot[3] = ops[min_ind][3];
	rot[4] = ops[min_ind][4];
	rot[5] = ops[min_ind][5];
	free(ops[min_ind]);
	free(ops);
	return (rot);
}

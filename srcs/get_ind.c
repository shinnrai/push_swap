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

#define CHOOSE_IND(i, ia) (i->rev) ? ind_rev(i, i->a[ia]) : ind_b(i, i->a[ia])

static int	ind_b(t_info *info, int a_val)
{
	register int	i;
	int				ind_max_in_b;
	int				ind_min_in_b;

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

static int	ind_rev(t_info *info, int a_val)
{
	register int	i;
	int				ind_max_in_b;
	int				ind_min_in_b;

	i = 0;
	ind_max_in_b = 0;
	ind_min_in_b = 0;
	while (++i < info->b_size)
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

/*
**  CHOOSE_IND can cause errors
*/

int			*calc_one(t_info *info, int i_a)
{
	register int	i_b;
	int				tmp;
	int				*op;

	i_b = (info->b_size < 2) ? 0 : CHOOSE_IND(info, i_a);
	op = (int*)malloc(sizeof(int) * 6);
	op[0] = (TO_ROT(i_a, info->a_size)) + (TO_ROT(i_b, info->b_size));
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
	int				**ops;

	i_a = 0;
	ops = malloc(sizeof(int*) * info->a_size);
	while (i_a < info->a_size)
	{
		ops[i_a] = calc_one(info, i_a);
		i_a++;
	}
	return (ops);
}

int			*get_ind(t_info *info)
{
	int				i;
	int				**ops;
	int				min_ind;
	int				*rot;

	ops = calc_how_many_ops(info);
	min_ind = -1;
	i = -1;
	while (++i < info->a_size)
		if (min_ind == -1 || ops[i][0] < ops[min_ind][0])
		{
			(min_ind != -1) ? free(ops[min_ind]) : (0);
			min_ind = i;
		}
		else
			free(ops[i]);
	rot = (int*)malloc(sizeof(int) * 6);
	i = -1;
	while (++i < 6)
		rot[i] = ops[min_ind][i];
	free(ops[min_ind]);
	free(ops);
	return (rot);
}

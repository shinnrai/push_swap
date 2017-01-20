/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofedorov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/23 11:50:14 by ofedorov          #+#    #+#             */
/*   Updated: 2016/12/23 11:50:15 by ofedorov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>


void	push_swap(t_info *info)
{
	t_info	*rev_info;

	push_to(info); // was excl
	rev_info = reverse_info(info);
	push_to(rev_info);
	merge_infos(info, rev_info);
	end_rotate(info);
	del_rev_info(&rev_info);
	info->ops = optimize(info->ops); //todo delete prev str
	if (*info->ops)
		info->ops[ft_strlen(info->ops) - 1] = '\0';

//	ft_putnbr(i);
//
//	while (excl)
//	{
//		ft_putnbr(*(int*)excl->content);
//		write(1, "\t", 1);
//		excl = excl->next;
//	}

}

int	main(int argc, char **argv)
{
	t_info	*info;

	info = receive_values(argc, argv);
	push_swap(info);
	if (*info->ops)
		ft_putendl(info->ops);
	del_info(&info);

}
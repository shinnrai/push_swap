/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   receive_values.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofedorov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/17 12:05:00 by ofedorov          #+#    #+#             */
/*   Updated: 2016/12/17 12:05:03 by ofedorov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static void	check_equal(int *a, int start, int size)
{
	register int	i;

	i = start;
	while (++i < size)
		if (a[i] == a[start])
			ft_error(NULL);
}

static int	check_options(t_info *info, int argc, char **argv)
{
	int		i;

	i = 0;
	info->each_op = false;
	info->print_slow = false;
	info->display_number = false;
	info->display_stacks = false;
	info->color = false;
	while (i < argc && *(argv[i]) == '-')
	{
		if (!ft_strcmp(argv[i], "-c"))
			info->color = true;
		else if (!ft_strcmp(argv[i], "-d"))
			info->display_stacks = true;
		else if (!ft_strcmp(argv[i], "-n"))
			info->display_number = true;
		else if (!ft_strcmp(argv[i], "-s"))
			info->print_slow = true;
		else if (!ft_strcmp(argv[i], "-q"))
			info->each_op = true;
		else
			ft_error(NULL);
		i++;
	}
	return (i);
}

void		setup_info(t_info *info, int argc)
{
	info->a = (int*)malloc(sizeof(int) * argc);
	info->b = (int*)ft_memalloc(sizeof(int) * argc);
	info->size = argc;
	info->a_size = argc;
	info->b_size = 0;
	info->ops = ft_strnew(0);
	info->rev = false;
}

t_info		*receive_values(int argc, char **argv)
{
	register int	i;
	int				options;
	t_info			*info;

	(argc-- == 1) ? exit(0) : argv++;
	info = (t_info*)malloc(sizeof(t_info));
	options = check_options(info, argc, argv);
	argc -= options;
	argv += options;
	if (argc == 1)
	{
		argv = ft_strsplit(argv[0], ' ');
		argc = 0;
		while (argv && argv[argc])
			argc++;
		(argc == 0) ? ft_error(NULL) : (0);
	}
	setup_info(info, argc);
	i = argc;
	while (i-- > 0)
	{
		info->a[i] = check_atoi(argv[i]);
		check_equal(info->a, i, argc);
	}
	return (info);
}

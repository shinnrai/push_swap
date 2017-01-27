/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofedorov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 14:36:17 by ofedorov          #+#    #+#             */
/*   Updated: 2016/12/08 14:36:19 by ofedorov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <libft.h>
# include <libftprintf.h>
# include <stdlib.h>
# include <unistd.h>

/*
**  c - color
**  d - display stacks
**  n - number of ops
**  s - print slow
**  q - quantity of each op
*/

typedef struct		s_info
{
	int				*a;
	int				*b;
	int				a_size;
	int				b_size;
	int				size;
	char			*ops;
	bool			reversed;
	bool			color;
	bool			display_stacks;
	bool			print_slow;
	bool			display_number;
	bool			each_op;
}					t_info;

# define INSTR_SA	0
# define INSTR_SB	1
# define INSTR_SS	2
# define INSTR_PA	3
# define INSTR_PB	4
# define INSTR_RA	5
# define INSTR_RB	6
# define INSTR_RR	7
# define INSTR_RRA	8
# define INSTR_RRB	9
# define INSTR_RRR	10

# define HOW_MANY_TO_ROTATE(a, size) (a) > ((size) / 2) ? (size) - (a) : (a)
# define CHOOSE_INSTR_A(a, size) (a) > ((size) / 2) ? (INSTR_RRA) : (INSTR_RA)
# define CHOOSE_INSTR_B(b, size) (b) > ((size) / 2) ? (INSTR_RRB) : (INSTR_RB)
# define HOW_MANY_TO_RR(a, b) MAX((a), (b))
# define HOW_MANY_TO_RRR(a, b, s_a, s_b) MAX((s_a) - (a), (s_b) - (b))

# define A_COLOR BRIGHT, GREEN, BLACK
# define B_COLOR BRIGHT, RED, BLACK
# define R_COLOR BRIGHT, BLUE, BLACK
# define DIS_COLOR BRIGHT, YELLOW, BLACK

t_info				*receive_values(int ac, char **av);
int					check_atoi(char *str);
void				push_swap(t_info *info);
void				push_to(t_info *info);

void				display_a(t_info *info);
void				display_b(t_info *info);
void				display_ab(t_info *info);
void				display_instr(int instr, bool color);

void				exec_instr_sa(t_info *info);
void				exec_instr_sb(t_info *info);
void				exec_instr_ss(t_info *info);
void				exec_instr_pa(t_info *info);
void				exec_instr_pb(t_info *info);
void				exec_instr_ra(t_info *info);
void				exec_instr_rb(t_info *info);
void				exec_instr_rr(t_info *info);
void				exec_instr_rra(t_info *info);
void				exec_instr_rrb(t_info *info);
void				exec_instr_rrr(t_info *info);

t_list				*find_excl_seq(t_info *info);
int					*calc_one(t_info *info, int i_a);
int					*get_ind(t_info *info);
void				add_instr(t_info *info, int instr);
void				exec_instr(t_info *info, int instr);
void				add_and_exec(t_info *info, int instr);
void				del_info(t_info **info);
void				del_rev_info(t_info **rev_info);
t_info				*reverse_info(t_info *info);
void				merge_infos(t_info *info, t_info *rev_info);
t_info				*copy_info(t_info *info);
void				end_rotate(t_info *info);
char				*optimize(char *ops);

int					get_next_instr(char **instr);

#endif

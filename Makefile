# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ofedorov <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/10/26 12:41:24 by ofedorov          #+#    #+#              #
#    Updated: 2017/01/18 15:08:11 by ofedorov         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PUSHSWAP	=	push_swap
CHECKER		=	checker

CC			=	gcc
CFLAGS		=	-Wall -Werror -Wextra

SRCSFL		+=	check_atoi.c display_stack.c end_rotate.c exec_instr.c \
				exec_instr_r.c exec_instr_rr.c exec_instr_s_p.c \
				get_ind.c info_utils.c push_to.c receive_values.c optimizer.c
PSMAIN		=	push_swap.c
CHECKERMAIN	=	checker.c

SRCSFD		=	srcs
OBJSFD		=	objs
INCLFD		=	includes libft/includes

SRCS		=	$(addprefix $(SRCSFD)/, $(SRCSFL))
OBJS		=	$(addprefix $(OBJSFD)/, $(SRCSFL:.c=.o))
OBJSPS		+=	$(OBJS)
OBJSPS		+=	$(addprefix $(OBJSFD)/, $(PSMAIN:.c=.o))
OBJSCHECKER	+=	$(OBJS)
OBJSCHECKER	+=	$(addprefix $(OBJSFD)/, $(CHECKERMAIN:.c=.o))
LIBFT		=	libft/libft.a

LIBFTLIB	=	-Llibft -lft

.PHONY: all clean fclean re

all: $(PUSHSWAP) $(CHECKER)

$(PUSHSWAP): $(OBJSPS)
	$(CC) $(CFLAGS) $(addprefix -I ,$(INCLFD)) $(OBJSPS) $(LIBFTLIB) -o $@

$(CHECKER): $(OBJSCHECKER)
	$(CC) $(CFLAGS) $(addprefix	-I ,$(INCLFD)) $(OBJSCHECKER) $(LIBFTLIB) -o $@

$(OBJSFD):
	mkdir $@

$(LIBFT): $(LIBFTFD)
	make -C $(LIBFTFD) re

$(OBJSFD)/%.o: $(SRCSFD)/%.c | $(OBJSFD)
	$(CC) $(CFLAGS) $(addprefix -I ,$(INCLFD)) -c $< -o $@

clean:
	rm -rf $(OBJS)
	rm -rf $(OBJSFD)

fclean: clean
	rm -rf $(PUSHSWAP)
	rm -rf $(CHECKER)

re: fclean all

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ofedorov <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/10/26 12:41:24 by ofedorov          #+#    #+#              #
#    Updated: 2017/01/19 11:03:35 by ofedorov         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PUSHSWAP	=	push_swap
CHECKER		=	checker

CC			=	gcc
CFLAGS		=	-Wall -Werror -Wextra

SRCSFL		+=	check_atoi.c display_stack.c end_rotate.c exec_instr.c \
				exec_instr_r.c exec_instr_rr.c exec_instr_s_p.c \
				get_ind.c info_utils.c push_to.c receive_values.c optimizer.c \
                get_next_instr.c
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

RED			=	\033[0;31m
GREEN		=	\033[0;32m
NC			=	\033[0m

.PHONY: all clean fclean re

all: $(PUSHSWAP) $(CHECKER)

$(PUSHSWAP): $(OBJSPS) $(LIBFT)
	@$(CC) $(CFLAGS) $(addprefix -I ,$(INCLFD)) $(OBJSPS) $(LIBFTLIB) -o $@
	@echo "$(GREEN)Pushswap created.$(NC)"

$(CHECKER): $(OBJSCHECKER) $(LIBFT)
	@$(CC) $(CFLAGS) $(addprefix -I ,$(INCLFD)) $(OBJSCHECKER) $(LIBFTLIB) -o $@
	@echo "$(GREEN)Checker created.$(NC)"

$(OBJSFD):
	@mkdir $@

$(LIBFT): $(LIBFTFD)
	@make -C libft re

$(OBJSFD)/%.o: $(SRCSFD)/%.c | $(OBJSFD)
	@$(CC) $(CFLAGS) $(addprefix -I ,$(INCLFD)) -c $< -o $@

clean:
	@rm -rf $(OBJS)
	@rm -rf $(OBJSFD)/$(PSMAIN:.c=.o) $(OBJSFD)/$(CHECKERMAIN:.c=.o)
	@echo "$(RED)Objects deleted$(NC)"
	@rm -rf $(OBJSFD)

fclean: clean
	@rm -rf $(PUSHSWAP)
	@echo "$(RED)Pushswap deleted.$(NC)"
	@rm -rf $(CHECKER)
	@echo "$(RED)Checker deleted.$(NC)"

re: fclean all

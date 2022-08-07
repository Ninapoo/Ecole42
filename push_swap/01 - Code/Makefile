# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cwan-chu <cwan-chu@student.42quebec.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/24 15:17:05 by cwan-chu          #+#    #+#              #
#    Updated: 2022/08/07 14:44:45 by cwan-chu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	push_swap
BONUS		=	checker

CC			=	clang
CFLAGS		=	-c -Wall -Wextra -Werror 

SDIR		=	srcs
ODIR		=	objs
BONUS_DIR	=	bonus_srcs
BONUS_ODIR	=	b_objs

INCLUDE		=	-I include

RM			=	rm -rf

SRCS		=	push_swap.c	\
				ft_atoi.c	\
				ft_split.c	\
				ps_algo.c	\
				ps_algo_one.c	\
				ps_algo_teen.c	\
				ps_algo_utils.c	\
				ps_allocate_memory.c \
				ps_avada_kedavra.c	\
				ps_check_error.c	\
				ps_count_int.c	\
				ps_is_success.c	\
				ps_make_stack.c	\
				ps_make_stack_utils.c	\
				ps_operations_push.c	\
				ps_operations_swap.c	\
				ps_print_error.c	\
				ps_run.c	\
				ps_sort_medium.c	\
				ps_sort_small.c	\
				ps_temp_stack.c	\
				ps_thresholds.c	
				
BONUS_SRCS	=	checker.c \
				b_checker_is_success.c \
				b_execute.c \
				b_run.c	\
				get_next_line_utils.c \
				get_next_line.c \
				ft_atoi.c	\
				ft_split.c	\
				ps_allocate_memory.c \
				ps_avada_kedavra.c	\
				ps_check_error.c	\
				ps_count_int.c	\
				ps_is_success.c	\
				ps_make_stack.c	\
				ps_make_stack_utils.c	\
				ps_operations_push.c	\
				ps_operations_swap.c	\
				ps_print_error.c	


OBJS		= 	$(SRCS:.c=.o)
B_OBJS		= 	$(BONUS_SRCS:.c=.o)

SFIX		= 	$(addprefix $(SDIR)/, $(SRCS))
OFIX		= 	$(addprefix $(ODIR)/, $(OBJS)) 
BFIX		= 	$(addprefix $(BONUS_DIR)/, $(BONUS_SRCS)) 
BOFIX 		=	$(addprefix $(BONUS_ODIR)/, $(B_OBJS))
 
VPATH		= 	$(SDIR) $(BONUS_DIR) 

all: 		$(NAME)
			@echo Makefile complete

$(ODIR)/%.o: %.c
			@$(CC) $(CFLAGS) $(INCLUDE) $< -o $@ 

$(ODIR):
			@mkdir -p $(ODIR)

$(NAME): 	$(ODIR) $(OFIX)
			@$(CC) $(OFIX) -o $(NAME)
			
			
bonus:			$(BONUS)
				@echo Makefile bonus complete

$(BONUS_ODIR)/%.o: %.c
				@$(CC) $(CFLAGS) $(INCLUDE) $< -o $@ 

$(BONUS_ODIR):
				@mkdir -p $(BONUS_ODIR)

$(BONUS): 		$(BONUS_ODIR) $(BOFIX) 
				@$(CC) $(BOFIX) -o $(BONUS)

clean: 
			@$(RM) $(ODIR)
			@$(RM) $(BONUS_ODIR)

fclean: 	clean
			@$(RM) $(NAME)
			@$(RM) $(BONUS)

re: 		clean all

.PHONY:		all bonus clean flcean re 
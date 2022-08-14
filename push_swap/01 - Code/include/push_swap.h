/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwan-chu <cwan-chu@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 19:08:26 by cwan-chu          #+#    #+#             */
/*   Updated: 2022/08/07 17:01:54 by cwan-chu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stddef.h>
# include <stdarg.h>
# include <limits.h>
//#include <stdio.h>

/*
Bottom points to the t_node below in the stack
Top points to the t_node above in the stack
*/
typedef struct s_node
{
	int				num;
	struct t_node	*bottom;
	struct t_node	*top;
}t_node;

typedef struct s_frame
{
	t_node	*ha;
	t_node	*hb;
	int		is_error;
	int		split_counter;
	long	atoi_num;
	int		nx;
	int		ny;
	int		num_y;
}t_frame;

void	algo(t_frame *frame);

//in algo_one.c
void	algo_one(t_frame *frame, int y);

//in algo_teen.c
void	algo_teen(t_frame *frame);

//in algo_utils.c
int		rotate_to_num(t_node *ha, int number);
void	ascending_order(t_frame *frame, int na, int nb);

//in print_error.c
int		print_error(void);
//void	print_stack(t_node *head);

//in avada_kedavra.c
void	avada_kedavra(t_frame *frame);
void	obliviate_frame(t_frame *frame);
int		obliviate_stack(t_node *head);

//in is_success.c
int		is_success(t_node *head);

//in push_btoa.c
void	push_btoa(t_frame *frame);

//in sort_medium.c
void	sort_medium(t_frame *frame, int na, int nb);
void	split_thresh(t_frame *frame);

//in sort_small.c
void	sort_small(t_frame *frame, int na, int nb);
void	sort_three_num(t_frame *frame, int na, int nb);
void	sort_othersmall(t_frame *frame, int num_min, int num_max);

//in thresholds.c
int		find_threshold(t_node *stack, int percentile);
int		find_i_max(t_node *temp);
int		find_i_min(t_node *temp);
int		find_i_max2(t_node *temp);

//in temp_stack.c
t_node	*temp_stack(t_node *head);
t_node	*make_temp(t_node *temp, int num);

//in count_int.c
int		count_int(t_node *head);

//in check_error.c
int		duplicate_not_found(t_frame *frame, int num);

//should be in utils/
void	ft_atoi(t_frame *frame, const char *str);
int		*ft_split(t_frame *frame, int *ptr, char const *s, char c);
int		ft_numwords(char const *s, char c);

//in make_stack_utils.c
t_node	*add_to_stack_bottom(t_node *head, int num);
void	add_to_stack_bottom2(t_frame *frame, int num);

//in make_stack.c
t_node	*create_stack(t_node *head, int num);
void	make_stack_many_args(t_frame *frame, char *str);
void	make_stack_few_args(t_frame *frame, char *str);

//in ps_allocate_memory.c
t_node	*malloc_t_node(t_frame *frame);
t_frame	*make_frame(void);

/*in run.c
i = 1 -> swap
i = 2 -> push
i = 3 -> rotate
i = 4 -> reverse rotate
*/
//t_node	*run(int i, t_node *ha, int na, t_node *hb,  int nb);
void	run(int i, t_frame *frame, int na, int nb);

//in operations_swap.c
void	swap(t_node *head);

//in operations_push.c
void	push(t_frame *frame, int na, int nb);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwan-chu <cwan-chu@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 19:08:26 by cwan-chu          #+#    #+#             */
/*   Updated: 2022/08/07 00:23:22 by cwan-chu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <stdlib.h>
# include <unistd.h>
# include <stddef.h>
# include <stdarg.h>
# include <limits.h>

typedef struct t_node
{
	int				num;
	struct t_node	*bottom;
	struct t_node	*top;
}t_node;

typedef struct t_frame
{
	t_node	*ha;
	t_node	*hb;
	int		is_error;
	int		read_check;
	int		gnl_count;
	long	atoi_num;
	int		stack_size;
}t_frame;

//in b_checker_is_success.c
void	checker_is_success(t_frame *frame);

//in b_execute.c
void	execute(t_frame *frame, char *line);
int		check_line(char *line, char *inst);

//in b_run.c
void	b_run(int i, t_frame *frame, int na, int nb);

//in get_next_line.c
char	*get_next_line(int fd);
char	*ft_temp_line(int fd, char *temp_line);
char	*ft_make_line(char *temp_line);
char	*ft_new_temp_line(char *temp_line);
int		ft_find_nl(char *temp_line);

//in get_next_line_utils.c
size_t	ft_strlen(char *str);
char	*ft_strjoin(char *s1, char *s2);

/* ***** Part of push_swap ***** */

//Some libft stuff
void	ft_atoi(t_frame *frame, const char *str);
int		*ft_split(t_frame *frame, int *ptr, char const *s, char c);
int		ft_numwords(char const *s, char c);

//in ps_allocate_memory.c
t_node	*malloc_t_node(t_frame *frame);
t_frame	*make_frame(void);

//in avada_kedavra.c
void	avada_kedavra(t_frame *frame);
void	obliviate_frame(t_frame *frame);
int		obliviate_stack(t_node *head);

//in ps_check_error.c
int		duplicate_not_found(t_frame *frame, int num);

//in ps_count_int.c
int		count_int(t_node *head);

//in is_success.c
int		is_success(t_node *head);

//in make_stack_utils.c
t_node	*create_stack(t_node *head, int num);
t_node	*add_to_stack_bottom(t_node *head, int num);
void	add_to_stack_bottom2(t_frame *frame, int num);

//in make_stack.c
void	make_stack_many_args(t_frame *frame, char *str);
void	make_stack_few_args(t_frame *frame, char *str);

//in operations_swap.c
void	swap(t_node *head);

//in operations_push.c
void	push(t_frame *frame, int na, int nb);

//in print_error.c
int		print_error(void);

#endif

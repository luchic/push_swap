/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nluchini <nluchini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 21:14:05 by nluchini          #+#    #+#             */
/*   Updated: 2025/08/06 16:05:40 by nluchini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sort.h"
#include "libft.h"
#include "ft_stack_operation.h"

static int	ft_check_is_sorted(t_stack *stack)
{
	t_dlist	*current;
	t_dlist	*next;

	if (!stack || stack->size < 2)
		return (1);
	current = stack->top;
	next = stack->top->next;
	while (next)
	{
		if (current->value > next->value)
			return (0);
		current = next;
		next = next->next;
	}
	return (1);
}

static int	ft_compare_top_max(t_stack *stack)
{
	t_dlist	*top;
	t_dlist	*next;

	if (!stack || stack->size < 2)
		return (0);
	top = stack->top;
	next = top->next;
	if (top->value > next->value)
		return (1);
	return (0);
}

static int	ft_compare_top_min(t_stack *stack)
{
	t_dlist	*top;
	t_dlist	*next;

	if (!stack || stack->size < 2)
		return (0);
	top = stack->top;
	next = top->next;
	if (top->value < next->value)
		return (1);
	return (0);
}

int	ft_find_min(t_stack *stack)
{
	t_dlist	*current;
	int		min;
	int		min_pos;
	int		pos;

	if (!stack || stack->size == 0)
		return (0);
	current = stack->top;
	min = current->value;
	pos = 0;
	min_pos = 0;
	while (current)
	{
		if (current->value < min)
		{
			min = current->value;
			min_pos = pos;
		}
		pos++;
		current = current->next;
	}
	return (min_pos);
}

static void	ft_skip(t_stack *stack, int iter)
{
	int	size;

	size = stack->size;
	if (((size + 1) / 2) > iter)
	{
		while (iter--)
			ft_ra(stack);
	}
	else
	{
		iter = size - iter;
		while (iter--)
			ft_rra(stack);
	}
}

static void	_brootforce_ft_sort(t_stack *stack_a, t_stack *stack_b)
{
	int	ind;

	while (stack_a->top->next)
	{
		ind = ft_find_min(stack_a);
		ft_skip(stack_a, ind);
		ft_pb(stack_a, stack_b);
	}
	while (stack_b->top)
	{
		ft_pa(stack_a, stack_b);
	}
}

static void	ft_sort_les_eq3(t_stack *stack_a)
{
	if (stack_a->size == 1)
		return ;
	if (stack_a->size == 2)
	{
		if (ft_compare_top_max(stack_a))
			ft_sa(stack_a);
		return ;
	}
	if (stack_a->top->value > stack_a->bottom->value
		&& stack_a->top->value > stack_a->top->next->value)
		ft_ra(stack_a);
	else if (stack_a->top->value > stack_a->bottom->value
		&& stack_a->top->value < stack_a->top->next->value)
		ft_rra(stack_a);
	if (ft_check_is_sorted(stack_a))
		return ;
	if (ft_compare_top_max(stack_a))
		ft_sa(stack_a);
	if (ft_check_is_sorted(stack_a))
		return ;
	ft_rra(stack_a);
	if (ft_compare_top_max(stack_a))
		ft_sa(stack_a);
}

static int	ft_is_max(t_stack *stack, int value)
{
	t_dlist	*current;

	if (!stack || stack->size == 0)
		return (0);
	current = stack->top;
	while (current)
	{
		if (current->value > value)
			return (0);
		current = current->next;
	}
	return (1);
}

static void	ft_merg_sorted_tail_4(t_stack *stack_a, t_stack *stack_b)
{
	if (ft_is_max(stack_a, stack_b->top->value))
		return (ft_pa(stack_a, stack_b), ft_ra(stack_a));
	if (stack_a->top->value >= stack_b->top->value)
		return (ft_pa(stack_a, stack_b));
	if (stack_a->top->next->value >= stack_b->top->value)
		return (ft_ra(stack_a), ft_pa(stack_a, stack_b), ft_rra(stack_a));
	else
	{
		ft_rra(stack_a);
		return (ft_pa(stack_a, stack_b), ft_ra(stack_a), ft_ra(stack_a));
	}
}

static void	ft_sort_les_eq5(t_stack *stack_a, t_stack *stack_b)
{
	int	index;

	index = ft_find_min(stack_a);
	ft_skip(stack_a, index);
	if (ft_check_is_sorted(stack_a))
		return ;
	ft_pb(stack_a, stack_b);
	if (stack_a->size == 4)
	{
		index = ft_find_min(stack_a);
		ft_skip(stack_a, index);
		ft_pb(stack_a, stack_b);
	}
	ft_sort_les_eq3(stack_a);
	ft_pa(stack_a, stack_b);
	if (stack_b->size == 1)
		ft_pa(stack_a, stack_b);
}

int ft_get_max(t_stack *stack)
{
	t_dlist	*current;
	int		max;

	if (!stack || stack->size == 0)
		return (-1);
	current = stack->top;
	max = current->value;
	while (current)
	{
		if (current->value > max)
			max = current->value;
		current = current->next;
	}
	return (max);
}

int ft_get_min(t_stack *stack)
{
	t_dlist	*current;
	int		min;

	if (!stack || stack->size == 0)
		return (-1);
	current = stack->top;
	min = current->value;
	while (current)
	{
		if (current->value < min)
			min = current->value;
		current = current->next;
	}
	return (min);
}

void __ft_random_sort(t_stack *stack_a, t_stack *stack_b)
{
	int size = stack_a->size;

	while (size / 2 < stack_a->size)
	{
		if (ft_compare_top_max(stack_a) && ft_compare_top_min(stack_b))
			ft_rr(stack_a, stack_b);
		else if (ft_compare_top_max(stack_a))
			ft_ra(stack_a);
		ft_pb(stack_a, stack_b);
	}
	// while (stack_b->size > 0)
	// {
	// 	if (ft_compare_top_max(stack_a) && ft_compare_top_min(stack_b))
	// 		ft_rr(stack_a, stack_b);
	// 	else if (ft_compare_top_max(stack_a))
	// 		ft_ra(stack_a);

	// 	if (stack_a->top->value > stack_b->top->value)
	// 		ft_ra(stack_a);
	// 	ft_pa(stack_a, stack_b);
	// }

	int max = ft_get_max(stack_a);
	while (stack_b->size > 0)
	{
		if(stack_a->top->value > stack_b->top->value || stack_a->top->value == max)
			ft_pa(stack_a, stack_b);
		else
			ft_ra(stack_a);
	}
	while (size / 2 < stack_a->size)
	{
		if (ft_compare_top_min(stack_a) && ft_compare_top_min(stack_b))
			ft_ss(stack_a, stack_b);
		else if (ft_compare_top_min(stack_a))
			ft_sa(stack_a);
		ft_pb(stack_a, stack_b);
	}
	max = ft_get_max(stack_a);
	while (stack_b->size > 0)
	{
		if(stack_a->top->value > stack_b->top->value || stack_a->top->value == max)
			ft_pa(stack_a, stack_b);
		else
			ft_ra(stack_a);
	}
}

int ft_top_a_is_max(t_stack *stack_a, t_stack *stack_b)
{
	if (!stack_a || !stack_b || stack_a->size == 0 || stack_b->size == 0)
		return (0);
	if (stack_a->top->value > stack_b->top->value)
		return (1);
	return (0);
}

void ft_sort_body(t_stack *stack_a, t_stack *stack_b, int max, int min)
{
	while (1)
	{

		
	}	
}

// void ft_random_sort(t_stack *stack_a, t_stack *stack_b)
// {
// 	int size = stack_a->size;
// 	int max;
// 	int min;
	
// 	// int count = 0;
// 	ft_pb(stack_a, stack_b);
// 	ft_pb(stack_a, stack_b);
// 	if (stack_b->top->value > stack_b->top->next->value)
// 	{
// 		max = stack_b->top->value;
// 		min = stack_b->top->next->value;
// 	}
// 	else
// 	{
// 		max = stack_b->top->next->value;
// 		min = stack_b->top->value;
// 	}
// 	ft_sort_body(stack_a, stack_b, max, min);
// }

void __ft_set_mmd(t_stack *stack, t_stack *stack_b)
{
	int div;
	int fir;
	int mid;
	int thd;

	div = stack->size / 3;

	if (stack->size < 3)
		return ;
	fir = stack->top->value;
	mid = stack->top->next->value;
	thd = stack->top->next->next->value;
	if (fir > mid && fir > thd)
		ft_ra(stack);
	else if (fir < mid && fir < thd)
	{
		ft_pb(stack, stack_b);
		ft_rb(stack_b);
	}else
		ft_pb(stack, stack_b);

	if (fir < mid && thd < mid)
		ft_ra(stack);
	else if (fir > mid && thd > mid)
	{
		ft_pb(stack, stack_b);
		ft_rb(stack_b);
	}else
		ft_pb(stack, stack_b);

	if (thd > mid && thd > fir)
		ft_ra(stack);
	else if (thd < mid && thd < fir)
	{
		ft_pb(stack, stack_b);
		ft_rb(stack_b);
	}else
		ft_pb(stack, stack_b);
}
int ft_check_st(t_stack *stack, int div)
{
	t_dlist	*current;

	if (!stack || stack->size < 3)
		return (1);
	current = stack->top;
	while (current)
	{
		if (current->value < div * 2)
			return (0);
		current = current->next;
	}
	return (1);
}

int ft_set_mmd(t_stack *stack, t_stack *stack_b, t_chunks chunks)
{
	int fir;

	// if (stack->size < 3)
	// 	return 1;
	fir = stack->top->value;
	
	if (fir >= chunks.max_min && fir <= chunks.max_max)
		ft_ra(stack);
	else if (fir >= chunks.mid_min && fir <= chunks.mid_max)
		ft_pb(stack, stack_b);
	else if (fir >= chunks.min_min && fir <= chunks.min_max)
	{	
		ft_pb(stack, stack_b);
		if (stack_b->size > 1)
			ft_rb(stack_b);
	}
	return (0);
}

int ft_set_mmd_mid(t_stack *stack_a, t_stack *stack_b, t_chunks chunks)
{
	int fir;

	// if (chunks.mid_max - chunks.mid_min < 3)
	// 	return 1;
	// fir = -1;
	// if (stack_b->top)
	fir = stack_b->top->value;
	
	if (fir >= chunks.max_min && fir <= chunks.max_max)
		ft_pa(stack_a, stack_b);
	else if (fir >= chunks.mid_min && fir <= chunks.mid_max)
	{	ft_pa(stack_a, stack_b);
		if (stack_a->size > 1)
			ft_ra(stack_a);
	}
	else if (fir >= chunks.min_min && fir <= chunks.min_max)
		ft_rb(stack_b);
	return (0);
}
int ft_set_mmd_min(t_stack *stack_a, t_stack *stack_b, t_chunks chunks)
{
	int fir;

	// if (chunks.mid_max - chunks.mid_min < 3)
	// 	return 1;
	fir = stack_b->bottom->value;

	if (fir >= chunks.max_min && fir <= chunks.max_max)
		ft_pa(stack_a, stack_b);
	else if (fir >= chunks.mid_min && fir <= chunks.mid_max)
	{	ft_pa(stack_a, stack_b);
		if (stack_a->size > 1)
			ft_ra(stack_a);
	}
	else if (fir >= chunks.min_min && fir <= chunks.min_max)
		ft_rb(stack_b);
	return (0);
}

int ft_set_mmd_bota(t_stack *stack_a, t_stack *stack_b, t_chunks chunks)
{
	int fir;

	// if (chunks.mid_max - chunks.mid_min < 3)
	// 	return 1;
	fir = stack_b->bottom->value;
	ft_rra(stack_a);
	if (fir >= chunks.mid_min && fir <= chunks.mid_max)
		ft_pb(stack_a, stack_b);
	else if (fir >= chunks.min_min && fir <= chunks.min_max)
	{
		ft_pb(stack_a, stack_b);
		if (stack_b->size > 1)
			ft_rb(stack_a);
	}
	return (0);
}

void ft_move_three_or_less(t_stack *stack_a, t_stack *stack_b, int num)
{
	ft_pa(stack_a, stack_b);
	if (num == 2)
	{
		ft_pa(stack_a, stack_b);
		if (stack_a->top->value > stack_a->top->next->value)
			ft_sa(stack_a);
		return ;
	}
	if (num == 3)
	{
		if (stack_b->top->value < stack_b->top->next->value)
			ft_sb(stack_b);
		if (stack_b->top->next->value > stack_a->top->value)
		{
			ft_ra(stack_a);
			ft_pa(stack_a, stack_b);
			ft_pa(stack_a, stack_b);
			ft_rra(stack_a);
		}
		else if (stack_b->top->next->value > stack_a->top->value)
		{
			ft_ra(stack_a);
			ft_pa(stack_a, stack_b);
			ft_rra(stack_a);
			ft_pa(stack_a, stack_b);
		}
		else if (stack_b->top->next->value < stack_a->top->value
			&& stack_b->top->value > stack_a->top->value)
		{
			ft_pa(stack_a, stack_b);
			ft_sa(stack_a);
			ft_pa(stack_a, stack_b);
		}
		else 
		{
			ft_pa(stack_a, stack_b);
			ft_pa(stack_a, stack_b);
		}
	}
}

void ft_rra_m(t_stack *stack, int num, void (*ft_r)(t_stack *))
{
	int i;

	i = 0;
	while (i < num)
	{
		ft_r(stack);
		i++;
	}
}

void ft_return(t_stack *stack_a, t_stack *stack_b, t_chunks chunks, t_pos pos)
{
	int i = 0;

	int mx = chunks.max_max - chunks.max_min + 1;
	if(stack_a->size <= 3)
		ft_sort_les_eq3(stack_a);
	else if (mx != 1)
	{
		if (ft_compare_top_max(stack_a))
			ft_sa(stack_a);
		if (mx == 3 && stack_a->top->next->value > stack_a->top->next->next->value)
		{
			ft_ra(stack_a);
			ft_sa(stack_a);
			ft_rra(stack_a);
			if (ft_compare_top_max(stack_a))
				ft_sa(stack_a);
		}
	}

	if(pos == TOP_A)
	{	
		ft_move_three_or_less(stack_a, stack_b, chunks.mid_max - chunks.mid_min + 1);
		ft_rra_m(stack_b, chunks.min_max - chunks.min_min + 1, ft_rrb);
		ft_move_three_or_less(stack_a, stack_b, chunks.min_max - chunks.min_min + 1);
	}
	if(pos == TOP_B || pos == BOTTOM_B)
	{
		if (chunks.mid_max - chunks.mid_min + 1 == 1)
			ft_rra(stack_a);
		else if (chunks.mid_max - chunks.mid_min + 1 == 2)
		{
			ft_rra(stack_a);
			ft_rra(stack_a);
			if (ft_compare_top_max(stack_a))
				ft_sa(stack_a);
		}
		else 
		{
			ft_rra(stack_a);
			ft_rra(stack_a);
			if (ft_compare_top_max(stack_a))
				ft_sa(stack_a);
			if (stack_a->bottom->value < stack_a->top->value)
				ft_rra(stack_a);
			else if (stack_a->bottom->value > stack_a->top->value
				&& stack_a->bottom->value < stack_a->top->next->value)
			{
				ft_rra(stack_a);
				ft_sa(stack_a);
			}
			else if (stack_a->bottom->value > stack_a->top->next->value)
			{
				
				ft_rra(stack_a);
				ft_sa(stack_a);
				ft_ra(stack_a);
				ft_sa(stack_a);
				ft_rra(stack_a);
			}
		}

		ft_rra_m(stack_b, chunks.min_max - chunks.min_min + 1, ft_rrb);
		ft_move_three_or_less(stack_a, stack_b, chunks.min_max - chunks.min_min + 1);
	}

	/* while (i < div + (size & 1 || size & 2))
	{
		ft_pa(stack_a, stack_b);
		i++;
	}
	i = 0;
	while (i < div)
	{
		if (stack_b->size > 1)
			ft_rrb(stack_b);
		ft_pa(stack_a, stack_b);
		i++;
	} */
	
}

void ft_push_tree(t_stack *stack_a, t_stack *stack_b, int div)
{
	if (div == 1)
	{
		ft_pa(stack_a, stack_b);
		return ;
	}

	if (div == 2)
	{
		if (stack_b->top->value > stack_b->top->next->value)
		{
			ft_pa(stack_a, stack_b);
			ft_pa(stack_a, stack_b);
		}
		else
		{
			ft_sb(stack_b);
			ft_pa(stack_a, stack_b);
			ft_pa(stack_a, stack_b);
		}
	}
	if(stack_b->top->value > stack_b->top->next->value
		&& stack_b->top->value > stack_b->top->next->next->value)
	{
		ft_pa(stack_a, stack_b);
		ft_pa(stack_a, stack_b);
		ft_pa(stack_a, stack_b);
	}
	else if  (stack_b->top->value < stack_b->top->next->value
		&& stack_b->top->value > stack_b->top->next->next->value)
	{
		ft_sb(stack_b);
		ft_pa(stack_a, stack_b);
		ft_pa(stack_a, stack_b);
		ft_pa(stack_a, stack_b);
	}
	else if (stack_b->top->value < stack_b->top->next->value
		&& stack_b->top->value < stack_b->top->next->next->value
		&& stack_b->top->next->value < stack_b->top->next->next->value)
	{
		ft_pa(stack_a, stack_b);
		ft_ra(stack_a);
		ft_sb(stack_b);
		ft_pa(stack_a, stack_b);
		ft_pa(stack_a, stack_b);
		ft_rra(stack_a);
	}
	else if (stack_b->top->value < stack_b->top->next->value
		&& stack_b->top->value < stack_b->top->next->next->value
		&& stack_b->top->next->value > stack_b->top->next->next->value)
	{
		ft_pa(stack_a, stack_b);
		ft_ra(stack_a);
		ft_pa(stack_a, stack_b);
		ft_pa(stack_a, stack_b);
		ft_rra(stack_a);
	}
	else if (stack_b->top->value > stack_b->top->next->value
		&& stack_b->top->value < stack_b->top->next->next->value)
	{
		ft_pa(stack_a, stack_b);
		ft_ra(stack_a);
		ft_sb(stack_b);
		ft_pa(stack_a, stack_b);
		ft_rra(stack_a);
		ft_pa(stack_a, stack_b);
	}
}

void ft_skip_treed(t_stack *stack, int div)
{
	int i = -1;
	while (++i < div)
		ft_rrb(stack);
}

t_chunks ft_set_chunks(t_chunks chunks, t_pos pos)
{
    int div;
	int shift;
	int s;
	t_chunks tmp;

	tmp = chunks;
	if (pos == TOP_A)
	{	
		s = tmp.max_max - tmp.max_min + 1;
		div = (s) / 3;
		shift = tmp.max_min;
		chunks.min_min = shift;
		chunks.min_max = shift + div - 1;
		chunks.mid_min = shift + div;
		if (s % 3 == 2)
			chunks.mid_max = shift + 2 * div;
		else
			chunks.mid_max = shift + 2 * div - 1;
		if (s % 3 == 2)
			chunks.max_min = shift + 2 * div + 1;
		else
			chunks.max_min = shift + 2 * div;
		chunks.max_max = tmp.max_max;
	}
	if (pos == TOP_B)
	{
		if (tmp.mid_max == tmp.mid_min)
		{
			chunks.min_min = tmp.mid_min;
			chunks.min_max = tmp.mid_max;
			chunks.mid_min = tmp.mid_min;
			chunks.mid_max = tmp.mid_max;
			chunks.max_min = tmp.mid_min;
			chunks.max_max = tmp.mid_max;
			return (chunks);
		}
		s = tmp.mid_max - tmp.mid_min + 1;
		div = (s) / 3;
		shift = tmp.mid_min;
		chunks.min_min = shift;
		chunks.min_max = shift + div - 1;
		chunks.mid_min = shift + div;
		if (s % 3 == 2)
			chunks.mid_max = shift + 2 * div;
		else
			chunks.mid_max = shift + 2 * div - 1;
		if (s % 3 == 2)
			chunks.max_min = shift + 2 * div + 1;
		else
			chunks.max_min = shift + 2 * div;
		chunks.max_max = tmp.mid_max;
	}
	if (pos == BOTTOM_B)
	{
		s = tmp.min_max - tmp.min_min + 1;
		div = (s) / 3;
		shift = tmp.min_min;
		chunks.min_min = shift;
		chunks.min_max = shift + div - 1;
		chunks.mid_min = shift + div;
		if (s % 3 == 2)
			chunks.mid_max = shift + 2 * div;
		else
			chunks.mid_max = shift + 2 * div - 1;
		if (s % 3 == 2)
			chunks.max_min = shift + 2 * div + 1;
		else
			chunks.max_min = shift + 2 * div;
		chunks.max_max = tmp.min_max;
	}
	return (chunks);
}
void ft_random_sort(t_stack *stack_a, t_stack *stack_b, t_chunks chunks, t_pos pos)
{	
	int count = 0;
	t_chunks tmp;
	tmp = ft_set_chunks(chunks, pos);
	int mx = tmp.max_max - tmp.min_min + 1;
	while (count < mx)
	{

		if (pos == TOP_A)
			ft_set_mmd(stack_a, stack_b, tmp);
		if (pos == TOP_B || pos == BOTTOM_B)
			ft_set_mmd_mid(stack_a, stack_b, tmp);
		count++;
	}
	if (mx <= 9)
		return (ft_return(stack_a, stack_b, tmp, pos));

	ft_random_sort(stack_a, stack_b, tmp, TOP_A);
	ft_random_sort(stack_a, stack_b, tmp, TOP_B);
	ft_rra_m(stack_b, tmp.min_max - tmp.min_min + 1, ft_rrb);
	ft_random_sort(stack_a, stack_b, tmp, BOTTOM_B);

}
void __new_ft_random_sort(t_stack *stack_a, t_stack *stack_b)
{
	t_chunks	chunks;
	ft_memset(&chunks, 0, sizeof(t_chunks));
	chunks.max_min = 0;
	chunks.max_max = stack_a->size - 1;
	ft_random_sort(stack_a, stack_b, chunks, TOP_A);
} 

void radix_sort(t_stack *stack_a, t_stack *stack_b, int bit)
{
	int i;
	int c = stack_a->size;
	
	int max = ft_get_max(stack_a);
	if (max < bit)
	{
		return ;
	}
	i = 0;
	while (i < c)
	{
		if(stack_a->top && stack_a->top->value & bit)
			ft_ra(stack_a);
		else
			ft_pb(stack_a, stack_b);
		i++;
	}
	int k = stack_b->size;
	i = 0;
	while (i < k)
	{
		ft_pa(stack_a, stack_b);
		i++;
	}
	radix_sort(stack_a, stack_b, bit << 1);
}

t_dlist *ft_get_max_node(t_stack *stack)
{
	t_dlist	*current;
	t_dlist	*max_node;

	if (!stack || stack->size == 0)
		return (NULL);
	current = stack->top;
	max_node = current;
	while (current)
	{
		if (current->value > max_node->value)
			max_node = current;
		current = current->next;
	}
	return (max_node);
}

t_dlist *max_node;

void	ft_sort(t_stack *stack_a, t_stack *stack_b)
{
	max_node = ft_get_max_node(stack_a);

	if (ft_check_is_sorted(stack_a))
		return ;
	if (stack_a->size <= 3)
		return (ft_sort_les_eq3(stack_a));
	else if (stack_a->size <= 5)
		return (ft_sort_les_eq5(stack_a, stack_b));
	// _brootforce_ft_sort(stack_a, stack_b);
	// ft_sort_les_eq5(stack_a, stack_b);
	__new_ft_random_sort(stack_a, stack_b);
	// radix_sort(stack_a, stack_b, 1);
}


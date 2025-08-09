/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nluchini <nluchini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 21:14:05 by nluchini          #+#    #+#             */
/*   Updated: 2025/08/09 13:00:57 by nluchini         ###   ########.fr       */
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
	return (top->value > next->value);
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
// TODO: Delete previase one 
// ===================== Utils funcitons =================
int ft_get_top(t_stack *stack)
{
	if (!stack || stack->size == 0)
		return (-1);
	return (stack->top->value);
}

int ft_get_bottom(t_stack *stack)
{
	if (!stack || stack->size == 0)
		return (-1);
	return (stack->bottom->value);
}

t_dlist *ft_get_top_node(t_stack *stack)
{
	if (!stack || stack->size == 0)
		return (NULL);
	return (stack->top);
}

t_dlist *ft_get_nnode(t_stack *stack, int n)
{
	t_dlist *current;
	int i;

	if (!stack || stack->size == 0 || n < 0 || n >= stack->size)
		return (NULL);
	current = stack->top;
	i = 0;
	while (current && i < n)
	{
		current = current->next;
		i++;
	}
	return (current);
}

int ft_get_nel(t_stack *stack, int n)
{
	t_dlist *cur;
	cur = ft_get_nnode(stack, n);
	if (!cur)
		return (-1);
	return (cur->value);
}

int ft_get_size_chunk(const t_chunks *chunks, t_type type)
{
	int size_chunk;

	if (type == MIN)
		size_chunk = chunks->min.max - chunks->min.min + 1;
	else if (type == MID)
		size_chunk = chunks->mid.max - chunks->mid.min + 1;
	else
		size_chunk = chunks->max.max - chunks->max.min + 1;
	return (size_chunk);
}

int ft_get_size_all_chunks(const t_chunks *chunks)
{
	int size;

	size = ft_get_size_chunk(chunks, MIN);
	size += ft_get_size_chunk(chunks, MID);
	size += ft_get_size_chunk(chunks, MAX);
	return (size);
}

// ===================== Move Values  =================\
// ====================================================|
// ====================================================/
int	ft_move_top_a(t_stack *stack_a, t_stack *stack_b, t_chunks chunks)
{
	int	fir;

	fir = ft_get_top(stack_a);
	if (fir == -1)
		return (-1);
	if (fir >= chunks.max.min && fir <= chunks.max.max)
		ft_ra(stack_a);
	else if (fir >= chunks.mid.min && fir <= chunks.mid.max)
		ft_pb(stack_a, stack_b);
	else if (fir >= chunks.min.min && fir <= chunks.min.max)
	{
		ft_pb(stack_a, stack_b);
		if (stack_b->size > 1)
			ft_rb(stack_b);
	}
	return (0);
}

int ft_move_top_b(t_stack *stack_a, t_stack *stack_b, t_chunks chunks)
{
	int fir;


	fir = ft_get_top(stack_b);
	if (fir == -1)
		return (-1);
	if (fir >= chunks.max.min && fir <= chunks.max.max)
		ft_pa(stack_a, stack_b);
	else if (fir >= chunks.mid.min && fir <= chunks.mid.max)
	{
		ft_pa(stack_a, stack_b);
		if (stack_a->size > 1)
			ft_ra(stack_a);
	}
	else if (fir >= chunks.min.min && fir <= chunks.min.max)
		ft_rb(stack_b);
	return (0);
}
int ft_move_bottom_a(t_stack *stack_a, t_stack *stack_b, t_chunks chunks)
{
	int fir;

	// if (chunks.mid_max - chunks.mid_min < 3)
	// 	return 1;
	fir = ft_get_bottom(stack_a);
	ft_rra(stack_a);
	if (fir >= chunks.mid.min && fir <= chunks.mid.max)
		ft_pb(stack_a, stack_b);
	else if (fir >= chunks.min.min && fir <= chunks.min.max)
	{
		ft_pb(stack_a, stack_b);
		if (stack_b->size > 1)
			ft_rb(stack_b);
	}
	return (0);
}

int ft_move_bottom_b(t_stack *stack_a, t_stack *stack_b, t_chunks chunks)
{
	int fir;

	// if (chunks.mid_max - chunks.mid_min < 3)
	// 	return 1;
	fir = ft_get_top(stack_b);
	if (fir >= chunks.max.min && fir <= chunks.max.max)
		ft_pa(stack_a, stack_b);
	if (fir >= chunks.mid.min && fir <= chunks.mid.max)
	{
		ft_pa(stack_a, stack_b);
		if (stack_a->size > 1)
			ft_ra(stack_a);
	}
	else if (fir >= chunks.min.min && fir <= chunks.min.max)
		ft_rb(stack_b);
	return (0);
}

// ===================== New Chunks Functions =====================
// TODO: The way i sort value could be differnet
void set_position(t_chunks *from, t_chunks *to, t_type type)
{
	to->max.pos = TOP_A;
	to->mid.pos = TOP_B;
	to->min.pos = BOTTOM_B;
}

int set_value(int *div, int *shift, t_chunks *chunks, t_type type)
{
	int size;

	if (type == MIN)
	{
		size = chunks->min.max - chunks->min.min + 1; 
		*div = size / 3;
		*shift = chunks->min.min;
	}
	else if (type == MID)
	{
		size = chunks->mid.max - chunks->mid.min + 1; 
		*div = size / 3;
		*shift = chunks->mid.min;
	}
	else
	{
		size = chunks->max.max - chunks->max.min + 1; 
		*div = size / 3;
		*shift = chunks->max.min;
	}
	return (size);
}

t_chunks ft_set_chunks_updated(t_chunks chunks, t_type type)
{
    int div;
	int shift;
	int size;
	t_chunks tmp;

	size = set_value(&div, &shift, &chunks, type);
	set_position(&chunks, &tmp, type);
	if (type == MIN)
		tmp.max.max = chunks.min.max;
	else if (type == MID)
		tmp.max.max = chunks.mid.max;
	else
		tmp.max.max = chunks.max.max;
	tmp.min.min = shift;
	tmp.min.max = shift + div - 1;
	tmp.mid.min = shift + div;
	if (size % 3 == 2)
		tmp.mid.max = shift + 2 * div;
	else
		tmp.mid.max = shift + 2 * div - 1;
	if (size % 3 == 2)
		tmp.max.min = shift + 2 * div + 1;
	else
		tmp.max.min = shift + 2 * div;
	return (tmp);
}

t_pos ft_get_position_all_chunks(t_stack *stack_a, t_stack *stack_b, t_chunks *chunks)
{
	int element;
	int size;
	int i;
	int is_found;

	is_found = 0;
	element = chunks->mid.min;
	size = ft_get_size_all_chunks(chunks);
	i = 0;
	while (i < size)
	{
		if(ft_get_nel(stack_b, i) == element)
		{
			is_found = 1;
			break ;
		}
		i++;
	}
	if (is_found)
		return (TOP_B);
	i = 0;
	while (i < size)
	{
		if(ft_get_nel(stack_a, i) == element)
		{
			is_found = 1;
			break ;
		}
		i++;
	}
	if (is_found)
		return (TOP_A);
	return (BOTTOM_A);
}

void ft_split_chnks(t_stack *stack_a, t_stack *stack_b, t_chunks *chunks, t_type type)
{
	int operations;
	int count;
	t_pos pos;

	operations = ft_get_size_all_chunks(chunks);
	count = 0;
	if (type == MID || type == MAX)
		pos = ft_get_position_all_chunks(stack_a, stack_b, chunks);

	while (count < operations)
	{
		if (type == MAX && pos == TOP_A)
			ft_move_top_a(stack_a, stack_b, *chunks);
		else if(type == MAX && pos == BOTTOM_A)
			ft_move_bottom_a(stack_a, stack_b, *chunks);
		else if (type == MID && pos == TOP_B)
			ft_move_top_b(stack_a, stack_b, *chunks);
		else if (type == MID && pos == BOTTOM_A)
			ft_move_bottom_a(stack_a, stack_b, *chunks);
		else if (type == MIN)
			ft_move_bottom_b(stack_a, stack_b, *chunks);
		count++;
	}
}
// ========================================================
// ============== Get current position of chunks ==========
// ========================================================
t_pos ft_get_max_position(t_stack *stack_a, t_chunks *chunks)
{
	int is_found;
	int value;
	int i;
	int size = ft_get_size_chunk(chunks, MAX);
	
	is_found = 0;
	value = chunks->max.min;
	i = 0;
	while (i < size)
	{
		if (ft_get_nel(stack_a, i) == value)
			is_found = 1;
		i++;
	}
	if (is_found)
		return (TOP_A);
	return (BOTTOM_A);
}

t_pos ft_get_mid_position(t_stack *stack_b, t_chunks *chunks)
{
	int is_found;
	int value;
	int i;
	int size = ft_get_size_chunk(chunks, MID);

	is_found = 0;
	value = chunks->mid.min;
	i = 0;
	while (i < size)
	{
		if (ft_get_nel(stack_b, i) == value)
			is_found = 1;
		i++;
	}
	if (is_found)
		return (TOP_B);
	return (BOTTOM_A);
}

t_pos ft_get_position(t_stack *stack_a, t_stack *stack_b, t_chunks *chunks, t_type type)
{
	if (type == MAX)
		return (ft_get_max_position(stack_a, chunks));
	if (type == MID)
		return (ft_get_mid_position(stack_b, chunks));
	return (TOP_A); // If not found, return TOP_A as default
}



// ========================================================
// ============== ft base case for sorting ================
// ========================================================

static int ft_is_sorted_top_dir(t_stack *stack, int n, int ascending)
{
    t_dlist *current;
    t_dlist *next;
	int i;

    if (!stack || stack->size < 2)
        return (1);
    current = stack->top;
    next = stack->top->next;
	i = 0;
	while (next && i < n - 1)
    {
        if (ascending && current->value > next->value)
            return (0);
        if (!ascending && current->value < next->value)
            return (0);
        current = next;
        next = next->next;
		i++;
    }
    return (1);
}

void ft_move_mid_bottoma_back(t_stack *stack_a, t_stack *stack_b, int size)
{
	if (size == 2)
	{
		ft_rra(stack_a);
		ft_rra(stack_a);
		if (ft_compare_top_max(stack_a))
			return (ft_sa(stack_a));
		return ;
	}
	ft_rra(stack_a);
	ft_rra(stack_a);
	if (ft_compare_top_max(stack_a))
		ft_sa(stack_a);
	if (ft_get_bottom(stack_a) < ft_get_top(stack_a))
		return (ft_rra(stack_a));
	else if (ft_get_bottom(stack_a) < ft_get_nel(stack_a, 1))
		return (ft_rra(stack_a), ft_sa(stack_a));
	ft_pb(stack_a, stack_b);
	ft_rra(stack_a);
	ft_sa(stack_a);
	ft_pa(stack_a, stack_b);
}

void ft_move_mid_topb_back(t_stack *stack_a, t_stack *stack_b, int size)
{
	if (size == 2 && ft_compare_top_min(stack_b))
		return (ft_sb(stack_b), ft_pa(stack_a, stack_b), ft_pa(stack_a, stack_b));
	else if (size == 2)
		return (ft_pa(stack_a, stack_b), ft_pa(stack_a, stack_b));
	ft_pa(stack_a, stack_b);
	ft_pa(stack_a, stack_b);
	if (ft_compare_top_max(stack_a))
		ft_sa(stack_a);
	if (ft_get_top(stack_b) < ft_get_top(stack_a))
		return (ft_pa(stack_a, stack_b));
	else if (ft_get_top(stack_b) < ft_get_nel(stack_a, 1))
		return (ft_pa(stack_a, stack_b), ft_sa(stack_a));
	ft_ra(stack_a);
	ft_pa(stack_a, stack_b);
	ft_sa(stack_a);
	ft_rra(stack_a);
}

void ft_mbot(t_stack *stack_a, t_stack *stack_b, int size)
{

}

void ft_move_max_back(t_stack *stack_a, t_stack *stack_b, t_chunks chunks)
{
	int size;
	if (stack_a->size <= 3)
		return ft_sort_les_eq3(stack_a);
	if (ft_get_position(stack_a, stack_b, &chunks, MAX) == BOTTOM_A)
	{
		size = ft_get_size_chunk(&chunks, MAX);
		if (size == 1)
			return ft_rra(stack_a);
		return ft_move_mid_bottoma_back(stack_a, stack_b, size);
	}

	size = ft_get_size_chunk(&chunks, MAX);
	if (size == 2 && ft_compare_top_max(stack_a))
		return (ft_sa(stack_a));
	if (ft_is_sorted_top_dir(stack_a, size, 1))
		return ;
	if (ft_compare_top_max(stack_a))
	{
		ft_sa(stack_a);
		if (ft_is_sorted_top_dir(stack_a, size, 1))
			return ;
	}
	if (ft_get_top(stack_a) < ft_get_nel(stack_a, 2))
		return (ft_ra(stack_a), ft_sa(stack_a), ft_rra(stack_a));
	else if (ft_get_top(stack_a) > ft_get_nel(stack_a, 2)
		&& ft_get_nel(stack_a, 1) > ft_get_nel(stack_a, 2))
	{
		ft_ra(stack_a);
		ft_sa(stack_a);
		ft_rra(stack_a);
		ft_sa(stack_a);
	}
}

void ft_move_mid_back(t_stack *stack_a, t_stack *stack_b, t_chunks chunks)
{
	int size;
	size = ft_get_size_chunk(&chunks, MID);
	if (size == 1 && chunks.mid.pos == TOP_B)
		return ft_pa(stack_a, stack_b);
	else if (size == 1 && chunks.mid.pos == BOTTOM_A)
		return ft_rra(stack_a);

	if (chunks.mid.pos == TOP_B)
		ft_move_mid_topb_back(stack_a, stack_b, size);
	else
		ft_move_mid_bottoma_back(stack_a, stack_b, size);
}

void ft_move_min_back_three(t_stack *stack_a, t_stack *stack_b)
{
	ft_pa(stack_a, stack_b);
	if (ft_compare_top_min(stack_b))
		ft_sb(stack_b);
	if (ft_get_bottom(stack_b) > ft_get_top(stack_b))
	{
		ft_rrb(stack_b);
		ft_pa(stack_a, stack_b);
		return (ft_pa(stack_a, stack_b), ft_pa(stack_a, stack_b));
	}
	else if (ft_get_bottom(stack_b) > ft_get_nel(stack_b, 1))
	{
		ft_pa(stack_a, stack_b);
		ft_rrb(stack_b);
		ft_pa(stack_a, stack_b);
		ft_pa(stack_a, stack_b);
		return ;
	}
	ft_pa(stack_a, stack_b);
	ft_pa(stack_a, stack_b);
	ft_pa(stack_a, stack_b);
}

void ft_move_min_back(t_stack *stack_a, t_stack *stack_b, t_chunks chunks)
{
// 	int size;
	int size;
	size = ft_get_size_chunk(&chunks, MIN);
	if (size == 1)
		return ft_pa(stack_a, stack_b);

	ft_move_mid_topb_back(stack_a, stack_b, size);
// 	size = ft_get_size_chunk(&chunks, MIN);
// 	if (size == 1)
// 		return (ft_rrb(stack_b), ft_pa(stack_a, stack_b));
// 	if (size == 2 )
// 	{
// 		if (ft_compare_top_min(stack_b))
// 			return (ft_sb(stack_b), ft_pa(stack_a, stack_b), ft_pa(stack_a, stack_b));
// 		return (ft_pa(stack_a, stack_b), ft_pa(stack_a, stack_b));
// 	}
// 	ft_move_min_back_three(stack_a, stack_b);
}


void ft_move_back(t_stack *stack_a, t_stack *stack_b, t_chunks chunks, t_type type)
{

	if (type == MAX)
		ft_move_max_back(stack_a, stack_b, chunks);
	else if (type == MID)
		ft_move_mid_back(stack_a, stack_b, chunks);
	else if (type == MIN)
		ft_move_min_back(stack_a, stack_b, chunks);
}

// ========================================================
// ========================================================
// ========================================================
void ft_skip_stack(t_stack *stack, int n, void (*ft_r)(t_stack *))
{
	if (n < 0)
		return ;
	while (n--)
		ft_r(stack);
}

void sort_core(t_stack *stack_a, t_stack *stack_b, t_chunks chunks, t_type type)
{
	int div;
	int shift;
	int size;
	t_chunks tmp;

	if (type == MIN && stack_b->size != ft_get_size_chunk(&chunks, MIN))
		ft_skip_stack(stack_b, ft_get_size_chunk(&chunks, MIN), ft_rrb);
	if (ft_get_size_chunk(&chunks, type) <= 3)
		return ft_move_back(stack_a, stack_b, chunks, type);

	tmp = ft_set_chunks_updated(chunks, type);
	
	ft_split_chnks(stack_a, stack_b, &tmp, type);
	if (type == MID && chunks.mid.pos == TOP_B || type == MIN)
		tmp.mid.pos = BOTTOM_A;


	sort_core(stack_a, stack_b, tmp, MAX);
	sort_core(stack_a, stack_b, tmp, MID);
	sort_core(stack_a, stack_b, tmp, MIN);
}

void ft_chunk_sort( t_stack *stack_a, t_stack *stack_b)
{
	t_chunks chunks;

	chunks.max.min = 0;
	chunks.max.max = stack_a->size - 1;
	chunks.max.pos = TOP_A;
	sort_core(stack_a, stack_b, chunks, MAX);
}

t_stack *sz;

void	ft_sort(t_stack *stack_a, t_stack *stack_b)
{
	if (ft_check_is_sorted(stack_a))
		return ;
	if (stack_a->size <= 3)
		return (ft_sort_les_eq3(stack_a));
	else if (stack_a->size <= 5)
		return (ft_sort_les_eq5(stack_a, stack_b));
	sz = stack_b;
	ft_chunk_sort(stack_a, stack_b);
	

	// t_chunks chunks;
	// chunks.max.min = 0;
	// chunks.max.max = stack_a->size - 1;
	// chunks.max.pos = TOP_A;
	// ft_move_max(stack_a, stack_b, chunks);
}
 
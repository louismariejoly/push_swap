/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   idiot_algo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljoly <ljoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/02 14:51:31 by ljoly             #+#    #+#             */
/*   Updated: 2017/05/05 17:01:23 by ljoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void		shift(t_stack *env, int len, int rank)
{
	if (rank < MED_RANK)
	{
		while (rank > 0)
		{
			do_op(env, RA);
			send_op(env, RA);
			rank--;
		}
	}
	else
	{
		while (rank + 1 < len)
		{
			do_op(env, RRA);
			send_op(env, RRA);
			rank++;
		}	
	}
}

static void		sort_a(t_stack *env, int min, int max)
{
	int			op;
	int			rank;

	op = 0;
	if ((rank = is_sort_not_ranked(env, 1)) > 0)
		shift(env, LEN_A, rank);
	else if (((A[0] != max && A[0] > A[1]) || (A[0] == min && A[1] == max))
			&& (op = SA))
		do_op(env, SA);
	else if ((op = RA))
		do_op(env, RA);
	if (op)
		send_op(env, op);
}

void			idiot_push_swap(t_stack *env, int min, int max)
{
	while (!is_sort(A, LEN_A, 0, 1))
		sort_a(env, min, max);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcalvie <lcalvie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 18:40:40 by lcalvie           #+#    #+#             */
/*   Updated: 2022/01/31 00:57:41 by lcalvie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_status(t_table *table, int status, long long time, unsigned int n)
{
	pthread_mutex_lock(&(table->mtx_talk));
	if (table->can_talk)
	{
		if (status == 0)
			printf("%lld %u has taken a fork\n", time, n);
		else if (status == 1)
			printf("%lld %u is eating\n", time, n);
		else if (status == 2)
			printf("%lld %u is sleeping\n", time, n);
		else
			printf("%lld %u is thinking\n", time, n);
	}
	pthread_mutex_unlock(&(table->mtx_talk));
}

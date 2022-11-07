/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcalvie <lcalvie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 18:40:40 by lcalvie           #+#    #+#             */
/*   Updated: 2022/02/01 12:50:29 by lcalvie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_status(int status, long long time, unsigned int n)
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

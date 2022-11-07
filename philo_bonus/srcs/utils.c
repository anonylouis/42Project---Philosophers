/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcalvie <lcalvie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 02:17:32 by lcalvie           #+#    #+#             */
/*   Updated: 2022/01/31 17:21:11 by lcalvie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi(char *str, unsigned int *n)
{
	int		i;
	long	n_long;

	i = 0;
	n_long = 0;
	while (str[i] >= '0' && str[i] <= '9' && n_long <= (long) UINT_MAX)
	{
		n_long = 10 * n_long + str[i] - '0';
		i++;
	}
	if (i == 0 || n_long > (long) UINT_MAX || str[i] != '\0')
		return (0);
	*n = (unsigned int) n_long;
	return (1);
}

long long	time_lld(t_table *table)
{
	struct timeval	current_time;
	long long		current_sec;
	long long		current_usec;
	long long		res;

	gettimeofday(&current_time, NULL);
	current_sec = current_time.tv_sec;
	current_usec = current_time.tv_usec;
	res = (current_sec - table->start_sec) * 1000;
	res += (current_usec - table->start_usec) / 1000;
	return (res);
}

unsigned int	ft_min(unsigned int a, unsigned int b)
{
	if (a <= b)
		return (a);
	return (b);
}

static int	ft_count_nb_letters(long n)
{
	int	i;

	if (n == 0)
		return (1);
	i = 0;
	while (n > 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(unsigned int n)
{
	int		i;
	char	*res;
	int		size;

	size = ft_count_nb_letters(n);
	res = malloc((size + 1) * sizeof(char));
	if (res == NULL)
		return (NULL);
	i = 0;
	while (n > 0 || i == 0)
	{
		res[size - 1 - i] = '0' + n % 10;
		i++;
		n /= 10;
	}
	res[size] = '\0';
	return (res);
}

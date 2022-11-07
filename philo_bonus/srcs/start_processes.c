/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_processes.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcalvie <lcalvie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 17:47:19 by lcalvie           #+#    #+#             */
/*   Updated: 2022/02/01 15:18:30 by lcalvie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static	void	create_child(t_philosopher *tab_philo,
			t_table *table, unsigned int i)
{
	int	child;

	child = fork();
	if (child == -1)
		exit(1);
	else if (child == 0)
	{
		routine(&(tab_philo[i]), table);
		exit(0);
	}
	else
		(table->tab_pid)[i] = child;
}

void	start_processes(t_philosopher *tab_philo, t_table *table)
{
	unsigned int	i;

	if (table->n == 1)
	{
		create_child(tab_philo, table, 0);
		return ;
	}
	i = 1;
	while (i < table->n)
	{
		create_child(tab_philo, table, i);
		i += 2;
	}
	usleep(table->t_eat * 500);
	i = 0;
	while (i < (table->n - 1))
	{
		create_child(tab_philo, table, i);
		i += 2;
	}
	if (table->n % 2 == 1)
	{
		usleep(table->t_eat * 1000);
		create_child(tab_philo, table, table->n - 1);
	}
}

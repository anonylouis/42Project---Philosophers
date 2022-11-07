/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcalvie <lcalvie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 02:19:08 by lcalvie           #+#    #+#             */
/*   Updated: 2022/02/01 13:59:55 by lcalvie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_table			*table;
	t_philosopher	*tab_philo;

	if (argc != 5 && argc != 6)
		return (0);
	table = init_table(argc, argv);
	if (table == NULL)
		return (1);
	tab_philo = init_tab_philo(table);
	if (tab_philo == NULL)
		return (1);
	start_processes(tab_philo, table);
	wait_processes(table);
	free_tab_philo(tab_philo, table->n);
	free_table(table);
	return (0);
}

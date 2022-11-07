/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcalvie <lcalvie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 02:17:30 by lcalvie           #+#    #+#             */
/*   Updated: 2022/02/01 14:10:54 by lcalvie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TABLE_H
# define TABLE_H

typedef struct s_table
{
	int				argc;
	unsigned int	n;
	unsigned int	t_death;
	unsigned int	t_eat;
	unsigned int	t_sleep;
	unsigned int	n_to_eat;
	long long		start_sec;
	long long		start_usec;
	int				*tab_pid;
	pthread_t		check_death;
	pthread_t		check_meal;
	sem_t			*forks;
	sem_t			*sem_death;
	sem_t			*sem_meal;
	sem_t			*sem_death_msg;
}		t_table;

#endif

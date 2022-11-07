/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcalvie <lcalvie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 02:17:30 by lcalvie           #+#    #+#             */
/*   Updated: 2022/02/01 14:29:37 by lcalvie          ###   ########.fr       */
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
	pthread_mutex_t	*forks;
	pthread_mutex_t	mtx_talk;
	int				can_talk;
	unsigned int	number_meal;
	pthread_mutex_t	mtx_number_meal;
	long long		start_sec;
	long long		start_usec;
	pthread_t		thread_stop;
}		t_table;

#endif

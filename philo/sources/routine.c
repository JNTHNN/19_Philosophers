/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgasparo <jgasparo@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 10:30:35 by jgasparo          #+#    #+#             */
/*   Updated: 2024/02/29 18:22:49 by jgasparo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	eating(t_philo *philo)
{
	// check si il a ces 2 fourchettes
	// le faire manger le temps delimite
	// lui faire tenir les 2 fourchettes
	pthread_mutex_lock(&philo->left_fork);
	write_s
}

void	thinking()
{
	
}

void	sleeping()
{
	
}

void	routine()
{
	// mange -> dort -> penser
}
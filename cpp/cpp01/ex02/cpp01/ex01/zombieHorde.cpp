/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpelliz <alpelliz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 16:27:21 by alpelliz          #+#    #+#             */
/*   Updated: 2024/01/18 17:23:44 by alpelliz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name )
{
	Zombie *horde = new Zombie[N];
	int		i = 0;
	
	while(i < N)
	{
		horde[i].set_name(name);
		i++;
	}
	i = 0;
	while (i < N)
	{
		horde[i].announce();
		i++;
	}
	return(horde);
}
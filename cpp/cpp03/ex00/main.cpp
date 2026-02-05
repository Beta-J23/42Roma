/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpelliz <alpelliz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 10:03:31 by alpelliz          #+#    #+#             */
/*   Updated: 2024/01/21 12:43:56 by alpelliz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ClapTrap.hpp"

int main()
{
	ClapTrap Pippo("Pippo");
	ClapTrap Jack("Jack");

	while(Jack.get_hit_points() > 0)
	{
		Pippo.attack(Jack.getname());
		Jack.takeDamage(Pippo.get_attack_damage());
	}
	Pippo.beRepaired(1);
	std::cout << "Pippo won, but in the next line will be equally DESTROOOOOOYED!!!" << std::endl;
	return(0);
}


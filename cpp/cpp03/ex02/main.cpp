/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpelliz <alpelliz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 10:03:31 by alpelliz          #+#    #+#             */
/*   Updated: 2024/01/21 14:29:07 by alpelliz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ClapTrap.hpp"
#include "includes/ScavTrap.hpp"
#include "includes/FragTrap.hpp"

int main()
{
	ClapTrap	Pippo("Pippo");
	ClapTrap	Jack("Frank");
	ScavTrap	John("John");
	FragTrap	Al("Al");
	
	
	while(Jack.get_hit_points() > 0)
	{
		Pippo.attack(Jack.getname());
		John.attack(Jack.getname());
		Jack.takeDamage(Pippo.get_attack_damage());
	}
	std::cout << "tacci tua Pippo " << John.getname() << " ci penso io!!!!" << std::endl;
	Al.attack(Pippo.getname());
	Pippo.takeDamage(Al.get_attack_damage());
	John.guardGate();
	Al.highFivesGuys();
	std::cout << "povero " << Jack.getname() << std::endl;
	Pippo.beRepaired(1);
	std::cout << "Pippo won, but in the next line will be equally DESTROOOOOOYED!!!" << std::endl;
	return(0);
}


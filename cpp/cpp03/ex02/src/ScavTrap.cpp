/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpelliz <alpelliz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 13:44:31 by alpelliz          #+#    #+#             */
/*   Updated: 2024/01/21 14:35:42 by alpelliz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ScavTrap.hpp"

ScavTrap::ScavTrap():ClapTrap(){};

ScavTrap::ScavTrap(std::string name):ClapTrap(name){
    std::cout << "ScavTrap " + _name + " constructor" << std::endl;
}

ScavTrap::~ScavTrap(){
	std::cout << "ScavTrap " << getname() << " get destrooooooyed, Not ClapTrap this is Scavtrap, not claptrap, this is scavtrap, tippopperopo popperopo" << std::endl;
};

void ScavTrap::attack(const std::string& target)
{
	{
	if (_energy_points <= 0 || _attack_damage <= 0)
	{
		std::cout << "Scavtrap " << _name << " have no points left and cannot do anything" << std::endl;
		return;
	}
		
	std::cout << "ScavTrap " << _name << " attacks " << target << " causing " << _attack_damage << " points of hit points! " << std::endl;
	//target.takeDamage(_attack_damage);
	_energy_points--;
	}
}

void ScavTrap::guardGate(){
	std::cout<< "ScavTrap " << _name << " is now in Gate keeper mode " << std::endl;
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpelliz <alpelliz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 10:03:02 by alpelliz          #+#    #+#             */
/*   Updated: 2024/01/21 12:41:33 by alpelliz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ClapTrap.hpp"

ClapTrap :: ClapTrap(void): _hit_points(10), _energy_points(10), _attack_damage(1)
{
	std::cout << "Claptrap " << _name << " have been created!!!!" << std::endl;
};

ClapTrap :: ClapTrap(std::string name): _hit_points(10), _energy_points(10), _attack_damage(1)
{
	_name = name;
	std::cout << "Claptrap " << _name << " have been created!!!!" << std::endl;
};

ClapTrap::~ClapTrap(){
	std::cout << "Claptrap " << _name << " have been destrooooyed!!!!" << std::endl;
};

std::string ClapTrap :: getname()
{
	return(_name);
}

int ClapTrap :: get_attack_damage()
{
	return _attack_damage;
}

int ClapTrap::get_energy_points()
{
	return _energy_points;
}

int ClapTrap::get_hit_points()
{
	return _hit_points;
}

void ClapTrap::attack(const std::string& target)
{
	if (_energy_points <= 0 || _hit_points <= 0)
	{
		std::cout << "Claptrap " << _name << " have no points left and cannot do anything" << std::endl;
		return;
	}
		
	std::cout << "ClapTrap " << _name << " attacks " << target << " causing " << _attack_damage << " points of hit points! " << std::endl;
	//target.takeDamage(_attack_damage);
	_energy_points--;
}

void ClapTrap::beRepaired(unsigned int amount){
	if (_energy_points <= 0 || _hit_points <= 0)
	{
		std::cout << "Claptrap " << _name << " have no points left and cannot do anything" << std::endl;
		return;
	}
	std::cout << "ClapTrap " << _name << " repairs itself of " << amount << " points " << std::endl;
	_hit_points += amount;
	_energy_points--;
};

void ClapTrap :: takeDamage(unsigned int amount){
	
	_hit_points -= amount;
	std::cout << "ClapTrap " << _name << " have been attacked and have " << _hit_points << " points of hit pooooinz! " << std::endl;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpelliz <alpelliz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 14:16:01 by alpelliz          #+#    #+#             */
/*   Updated: 2024/01/21 14:33:55 by alpelliz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ClapTrap.hpp"
#include "../includes/FragTrap.hpp"

FragTrap::FragTrap():ClapTrap(){};

FragTrap::FragTrap(std::string name):ClapTrap(name){
	_hit_points = 100;
	_energy_points = 100;
	_attack_damage = 30;
    std::cout << "FragTrap " + _name + " constructor" << std::endl;
}

FragTrap::~FragTrap(){
	std::cout << "FragTrap " << getname() << " get destrooooooyed, tunz tunz tunz" << std::endl;
};

void FragTrap::highFivesGuys()
{
	std::cout << "Frag says... High five Guys" << std::endl;
};


/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpelliz <alpelliz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 18:09:44 by alpelliz          #+#    #+#             */
/*   Updated: 2024/01/19 15:47:59 by alpelliz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB :: HumanB()
{};

HumanB :: ~HumanB(){}

std::string HumanB::getname()
{
	return(_name);
}

void HumanB :: setname(std::string name)
{
	_name = name;
}

HumanB :: HumanB(std::string name){
	
	//std::string str = weptype.getType();
	//_weapon.setType(str);
	_name = name;
}

void HumanB :: setWeapon(Weapon &weap)
{
	//_weapon = weap.getType();
	_weapon = &weap;
}

void HumanB::attack()
{
	std::cout << _name << " attacks with their " << _weapon->getType() << std::endl;
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpelliz <alpelliz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 18:10:42 by alpelliz          #+#    #+#             */
/*   Updated: 2024/01/19 15:54:07 by alpelliz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

//HumanA :: HumanA() : _weapon("pistoletta"){};
HumanA :: ~HumanA(){};

std::string HumanA::getname()
{
	return(_name);
}

void HumanA :: setname(std::string name)
{
    _name = name;
}

HumanA :: HumanA(std::string name, Weapon &weptype) : _name(name), _weapon(weptype) 
{
	//std::string str = weptype.getType();
	//_weapon.setType(str);
    //_name = name;
}

void HumanA::attack()
{
	std::cout << _name << " attacks with their " << _weapon.getType() << std::endl;
}
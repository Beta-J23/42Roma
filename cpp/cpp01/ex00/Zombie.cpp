/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpelliz <alpelliz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 12:47:18 by alpelliz          #+#    #+#             */
/*   Updated: 2024/01/18 16:58:24 by alpelliz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie() : _name("Default")
{
}

Zombie::Zombie(std::string zombie_name) : _name(zombie_name){}

void Zombie::announce()
{
    std::cout << _name << ":  BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::~Zombie()
{
    std::cout << _name << "Has been Destroooooyed" << std::endl;
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpelliz <alpelliz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 12:47:30 by alpelliz          #+#    #+#             */
/*   Updated: 2024/01/18 16:18:07 by alpelliz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie  *newZombie(std::string name);
void randomChump( std::string name );

int main(void)
{
	Zombie Zombie1("construtto");
    Zombie* zombie2 = newZombie("Lucio");
    Zombie1.announce();
    zombie2->announce();
    randomChump("Jack");
    delete zombie2;
}
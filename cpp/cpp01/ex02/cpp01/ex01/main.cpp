/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpelliz <alpelliz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 16:27:24 by alpelliz          #+#    #+#             */
/*   Updated: 2024/01/18 17:28:13 by alpelliz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name );

int main()
{
	int z;
	std::cout << "How many Zombies you want in the horde? ";
	std::cin >> z;
	Zombie *horde = zombieHorde(z, "Zombie");
	delete[] horde;
}
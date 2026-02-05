/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpelliz <alpelliz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 16:01:46 by alpelliz          #+#    #+#             */
/*   Updated: 2024/01/22 16:01:49 by alpelliz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/Animal.hpp"
#include "includes/Dog.hpp"
#include "includes/Cat.hpp"
#include "includes/Wrong_Cat.hpp"
#include "includes/Brain.hpp"

/*
int main()
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();
	delete meta;
	delete i;
	delete j;

	const Wrong_Animal* metak = new Wrong_Animal();
	const Wrong_Animal* k = new Wrong_Cat();
	std::cout << k->getType() << " " << std::endl;
	k->makeSound(); //will output the Wrong_cat sound!
	metak->makeSound();
	delete k;
	delete metak;

	return 0;
}*/

//THIS MAIN WILL GIVE A COMPILATION ERROR SINCE THIS IS AN ABSTRACT CLASS

int main()
{
	//Animal j = Dog();
	Animal *j = new Dog();
	const Animal* i = new Cat();
	const Animal *animals[20];
	int k = 0;
	int	n = 10;
	while (k < n)
	{
		if (k < n / 2)
			animals[k] = new Dog();
		else
			animals[k] = new Cat();
		k++;
	}

	k = 0;
	while (k < n)
	{
		delete animals[k];
		k++;
	}
	delete j;
	delete i;

	return 0;
}
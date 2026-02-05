/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpelliz <alpelliz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 14:01:37 by alpelliz          #+#    #+#             */
/*   Updated: 2024/01/15 14:42:00 by alpelliz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "phonebook.hpp"
#include <cstdio>

int add_routine()
{
	phonebook contact1;
	std::cout << "First name: " << std::endl;
	std::cin >> contact1.first_name;
	std::cout << "last name: " << std::endl;
	std::cin >> contact1.last_name;
	std::cout << "phone number: " << std::endl;
	std::cin >> contact1.phone_number;
	std::cout << "darkest secret: " << std::endl;
	std::cin >> contact1.darkest_secret;
	contact1.print_contact();
	return (0);
}

int search_routine()
{
	
	return (0);
}

int main()
{
	phonebook contact1;
	std::string input;

	//char input[10];
	std::cout << "Welcome to the phonebook!. Enter: \n \
	ADD to save a new contact; \n \
	SEARCH to display a specific contact;\n \
	EXIT to quit the program and delete all contacts!!!\n";
	while(1)
	{
		std::cin >> input;
		if (input == "ADD")
			add_routine();
		else if (input == "SEARCH")
			std::cout << "SEARCH" << std::endl;
		else if (input == "EXIT")
		{
			std::cout << "This will delete all your contact, If you want to continue type YES, if not type NO\n";
			std::cin >> input;
			if (input == "YES")
				break;
			else if (input == "NO")
				std::cout << "Welcome back" << std::endl;
			else
				std::cout << "Wrong input. Try again" << std::endl;
			// RIVEDI CICLO PER USCIRE.
		}
		else 
			std::cout << "Wrong input. Try again" << std::endl;
	}
}

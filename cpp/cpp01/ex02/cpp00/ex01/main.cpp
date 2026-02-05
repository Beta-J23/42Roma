/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpelliz <alpelliz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 18:12:11 by alpelliz          #+#    #+#             */
/*   Updated: 2024/01/18 12:10:31 by alpelliz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

int main()
{
	int i = 0;
	phonebook contact;
	std::string input;
	contact.total_contact = 0;
	std::cout << "Welcome to the phonebook!. Enter: \n \
	ADD to save a new contact; \n \
	SEARCH to display a specific contact;\n \
	EXIT to quit the program and delete all contacts!!!\n";
	while(1)
	{
		std::cout << "\n    Main Menu, press ADD || SEARCH || EXIT   \n" << std::endl;
		std::getline(std::cin, input);
		if (input == "ADD")
		{
			if (i == 8)
			{
				i = 0;
				add_routine(&contact, i);
				i++;
			}
			else
			{	
				add_routine(&contact, i);
				i++;
				if (contact.total_contact < 8)
					contact.total_contact++;
			}
		}
		else if (input == "SEARCH")
		{
			if(i > 0)
				std::cout << "     INDEX|FIRST NAME| LAST NAME|  NICKNAME" << std::endl;
			search_routine(&contact);
		}
		else if (input == "EXIT")
				break;
		else 
			std::cout << "Wrong input. Try again" << std::endl;
	}
}
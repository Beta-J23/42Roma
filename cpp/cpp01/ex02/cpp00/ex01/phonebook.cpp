/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpelliz <alpelliz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 14:01:37 by alpelliz          #+#    #+#             */
/*   Updated: 2024/01/19 09:55:49 by alpelliz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

std::string empty_checker(std::string name)
{
	std::string field;
	int x = 0;
	while (x == 0)
	{
		std::getline(std::cin, field);
		if (name == "Phone number:" && number_recognizer(field) == 1)
		{
			std::cout << "Only numbers in phone numbers please retype" << std::endl;
			std::cout << name << std::endl;
			x = 0;
		}
		else if (ft_strlen(field) == 0)
		{	
			std::cout << "field cannot be empty, please retype." <<std::endl;
			std::cout << name <<std::endl;
			x = 0;
		}
		else
			x = 1;
	}
	return(field);
}

int add_routine(phonebook *pb, int i)
{
	std::cout << "First name: " << std::endl;
	pb->contact[i].first_name = empty_checker("First name:");
	std::cout << "Last name: " << std::endl;
	pb->contact[i].last_name = empty_checker("Last name:");
	std::cout << "Nickname: " << std::endl;
	pb->contact[i].nickname = empty_checker("Nickname:");
	std::cout << "Phone number: " << std::endl;
	pb->contact[i].phone_number = empty_checker("Phone number:");
	std::cout << "Darkest secret: " << std::endl;
	pb->contact[i].darkest_secret = empty_checker("Darkest secret:");
	return (0);
}

int search_routine(phonebook *pb)
{
	int j = 0;
	int x = 0;
	std::string in; 
	while (j < pb->total_contact)
	{
		std::cout << contact_printer(std::to_string(j + 1));
		std::cout << '|';
		std::cout << contact_printer(pb->contact[j].first_name);
		std::cout << '|';
		std::cout << contact_printer(pb->contact[j].last_name);
		std::cout << '|';
		std::cout << contact_printer(pb->contact[j].nickname) << std::endl;
		j++;
	}
	std::cout << "insert index number to see contact details" << std::endl;
	std::getline(std::cin, in);
	if (std::cin.fail()) {
			std::cin.clear();
			std::cin.ignore();
		}
	if(ft_strlen(in) == 1 && (in[0] > 48 && in[0] < 57))
			x = in[0] - 48;
	while (x < 1 || x > 8)
	{
		std::cout << "Insert a number beetween 1 and 8" << std::endl;
		std::getline(std::cin, in);
		if(ft_strlen(in) == 1 && (in[0] > 48 && in[0] < 57))
		{
			x = in[0] - 48;
			break;
		}
	}
	if (x >= 1 && x <= 8)
	{
		if (x > pb->total_contact)
			std::cout << "Contact not found" << std::endl;
		else
			show_contact(pb, x - 1);
	}
	return (0);
}

int show_contact(phonebook *pb, int x)
{
	std::cout << "First name: " << pb->contact[x].first_name <<std::endl;
	std::cout << "Last name: " << pb->contact[x].last_name <<std::endl;
	std::cout << "Nickname: " << pb->contact[x].nickname <<std::endl;
	std::cout << "Phone number: " << pb->contact[x].phone_number <<std::endl;
	std::cout << "Darkest secret: " << pb->contact[x].darkest_secret <<std::endl;
	return(0);
}

std::string contact_printer(std::string str)
{
	int	i = 0;
	int j = 0;
	int x = 0;
	std::string mod_str;
	std::string second_str;
	
	x = ft_strlen(str);
	j = 10 - x;
	if (x > 9)
	{
		i = 0;
		mod_str = str.substr(0, 9);
		mod_str = mod_str + '.';
	}
	else
	{
		while(i < j)
		{
			mod_str = ' ' + mod_str;
			i++;
		}
		mod_str = mod_str + str;
	}
	return (mod_str);
}

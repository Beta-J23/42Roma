/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpelliz <alpelliz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 14:01:46 by alpelliz          #+#    #+#             */
/*   Updated: 2024/01/15 14:25:12 by alpelliz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include <iostream>

class phonebook{
	public:
		std::string		first_name;
		std::string		last_name;
		std::string		phone_number;
		std::string		darkest_secret;
		
		void print_contact() {
			std::cout << "contact name: " << first_name;
		}

};

#endif



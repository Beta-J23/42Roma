/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpelliz <alpelliz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 09:46:49 by alpelliz          #+#    #+#             */
/*   Updated: 2024/01/17 11:34:28 by alpelliz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

class contact{
	public:
		std::string		first_name;
		std::string		last_name;
		std::string		nickname;
		std::string		phone_number;
		std::string		darkest_secret;
		
		void print_contact() {
			std::cout << "contact name: " << first_name;
		}
};
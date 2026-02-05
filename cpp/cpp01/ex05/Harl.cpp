/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpelliz <alpelliz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 18:56:03 by alpelliz          #+#    #+#             */
/*   Updated: 2024/01/20 11:56:51 by alpelliz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl(void)
{}

Harl::~Harl(void)
{}

void Harl::debug(void)
{
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
}

void Harl::info(void)
{
	std::cout << "I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!" << std::endl;
}

void Harl::warning(void)
{
	std::cout << "I think I deserve to have some extra bacon for free. I've been coming for years whereas you started working here since last month." << std::endl;
}

void Harl::error(void)
{
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void Harl::complain(std::string level)
{
	//switch (level[0])
	int i = 0;
	{
		std::string case_array[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
		void (Harl::*function_pointer[4])() = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
		while (i < 4)
		{
			if (!case_array[i].compare(level))
				(this->*function_pointer[i])();
			i++;
		}
		/*
		case 'DEBUG':
			this->debug();
			break;
		case 'INFO':
			this->info();
			break;
		case 'WARNING':
			this->warning();
			break;
		case 'ERROR':
			this->error();
			break;
		default:
			std::cout << "Wrong level" << std::endl;
			break;*/
	}
}


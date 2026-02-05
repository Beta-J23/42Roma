/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpelliz <alpelliz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 16:37:57 by alpelliz          #+#    #+#             */
/*   Updated: 2024/01/20 11:13:14 by alpelliz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <fstream>

std::string		replace(std::string line, std::string s1, std::string s2)
{
	while (line.find(s1) != std::string::npos)
	{
		std::size_t pos = line.find(s1);
		line.erase(pos, s1.length());
		line.insert(pos, s2);
	}
	return (line);
}

int main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cout << "Insert 3 args: filename, s1 string to replace, s2 string that will replace" << std::endl;
		return(0);
	}
	std::string		file_name = argv[1];
	file_name += ".replace";
	std::ifstream	myfile(argv[1]);
	std::string		line;
	std::string		all_file;
	std::string		s1 = argv[2];
	std::string		s2 = argv[3];
	
	if (myfile.is_open())
	{
		std::getline(myfile, line, '\0');
		line += '\0';
		std::ofstream	result(file_name);
		result << replace(line, s1, s2);
		std::cout << "File: " << file_name << " created!" << std::endl;
		result.close();
	}
	else 
		std::cout << "unable to open file" << std::endl;
	myfile.close();
	return (0);
}
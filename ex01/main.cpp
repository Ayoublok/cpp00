/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayylaaba <ayylaaba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 16:39:08 by ayylaaba          #+#    #+#             */
/*   Updated: 2023/09/18 18:03:30 by ayylaaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int     main()
{
    std::string line;
    std::string type_line;
    Contact     data;
    PhoneBook   add;
    int         i;
    int         J;

    i = 0;
    while (1)
    {
        std::cout<<"\nEntre the command : ";
        std::getline(std::cin, line);
        if (std::cin.eof())
            exit(0);
        if (!line.compare("ADD") && !data.handle_noprintable(line))
        {
            type_line = data.check_fill_field("Entre the first_name : ", 0);
            data.catch_contact(0, type_line);
            type_line = data.check_fill_field("Entre the last_name : ", 0);
            data.catch_contact(1, type_line);
            type_line = data.check_fill_field("Entre the NICK_NAME : ", 0);
            data.catch_contact(2, type_line);
            type_line = data.check_fill_field("Entre the darkset secret : ", 0);
            data.catch_contact(3, type_line);
            type_line = data.check_fill_field("Entre the Phone Number : ", 1);
            data.catch_contact(4, type_line);
            add.set_cont(data);
            i++;
        }
        else if (!line.compare("SEARCH") && !data.handle_noprintable(line))
        {
            add.display_all_contact(i);
            std::cout<<"\nEntre the index : ";
            std::getline(std::cin, line);
            if (std::cin.eof() || data.handle_noprintable(line))
                exit(0);
            J = -1;
            while (line[++J])
            {
                if (!std::isdigit(line[J]))
                {
                    std::cout << "please entre only digit\n";
                    J = -1;
                    std::cout << "\nEntre the index : ";
                    std::getline(std::cin, line);
                    if (std::cin.eof() || data.handle_noprintable(line))
                        exit(0);
                    continue;
                }
            }
            while (line.empty() || (std::stoi(line) < 1 ||  std::stoi(line) > 8))
            {
                std::cout << "Something wrong !" << "\n";
                std::cout<<"\nEntre the index : ";
                std::getline(std::cin, line);
                if (std::cin.eof() || data.handle_noprintable(line))
                    exit(0);
            }
            add.display_one_contact(std::stoi(line));
        }
        else if (!line.compare("EXIT") && !data.handle_noprintable(line))
            data.exit_phone_book();
    }
}

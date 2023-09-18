/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayylaaba <ayylaaba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 16:35:40 by ayylaaba          #+#    #+#             */
/*   Updated: 2023/09/18 18:21:58 by ayylaaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

Contact     Contact::creat_contact()
{
    Contact NewContact;
    NewContact.first_name = get_intfo(0);
    NewContact.last_name = get_intfo(1);
    NewContact.nick_name = get_intfo(2);
    NewContact.darksecret = get_intfo(3);
    return (NewContact);
}

std::string    Contact::get_intfo(int c)
{    
    if (c == 0)
        return (first_name);
    if (c == 1)
        return (last_name);
    if (c == 2)
        return (nick_name);
    if (c == 3)
        return (darksecret);
    if (c == 4)
        return (phone_number);
    return (0);
}

void    Contact::catch_contact(int c, std::string str)
{    
    if (c == 0)
        first_name = str;
    if (c == 1)
        last_name = str;
    if (c == 2)
        nick_name = str;
    if (c == 3)
        darksecret = str;
    if (c == 4)
        phone_number = str;
}

std::string    Contact::check_fill_field(std::string str, int  x)
{
    std::string line;
    std::cout << str;
    std::getline(std::cin, line);
    if (std::cin.eof())
        exit (0);
    int i = -1;
    if (!x)
    {
        while (line.empty() || handle_noprintable(line))
        {
            std::cout << "please fill the field" << "\n";
            std::cout << str;
            std::getline(std::cin, line);
            if (std::cin.eof())
                exit (0);
        }
    }
    else
    {
        while (line[++i])
        {
            if (!std::isdigit(line[i])|| handle_noprintable(line))
            {
                std::cout << "please entre only digit\n";
                i = 0;
                std::cout << str;
                std::getline(std::cin, line);
                if (std::cin.eof())
                    exit (0);
                continue;
            }
        }
    }
    return (line);
}

int Contact::handle_noprintable(const std::string &str)
{
    int i;

    i = -1;
    while (str[++i])
    {
        if (!std::isprint(str[i]))
            return (1);
    }
    return (0);
}

void        Contact::exit_phone_book()
{
    std::cout << "you exit phonebook application now, GOODbye !" << "\n";
    exit (0);
}


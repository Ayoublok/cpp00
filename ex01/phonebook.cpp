/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayylaaba <ayylaaba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 15:33:21 by ayylaaba          #+#    #+#             */
/*   Updated: 2023/09/14 19:27:26 by ayylaaba         ###   ########.fr       */
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

void   PhoneBook::set_cont(Contact other)
{
    if (i < 8)
    {
        cont[i] = other;
        i++;
    }
    else
    {
        cont[j] = other;
        j = (j + 1) % 8;
    }
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

void    PhoneBook::display_all_contact(int x)
{
    int i;

    i = 0;
    if (x > 8)
        x = 8;
    std::cout << "|" << std::setw(10) << "index" << "|" << std::setw(10) <<"first name";
    std::cout << "|" << std::setw(10) <<"last name"  <<  "|"  << std::setw(10) << "nickname";
    std::cout  << "|" << std::setw(10) << "darksecret" << "|" << std::setw(10) <<"PhoneNumer" <<"|\n";
    while (i < x)
    {
        std::cout << "|" << std::setw(10) << i + 1  <<"|";
        if (cont[i].get_intfo(0).length() >= 10)
        {
            std::string first_name =  cont[i].get_intfo(0);
            first_name.resize(9);
            std::cout << first_name << "." << "|" ;
        }
        else
            std::cout << std::setw(10) << cont[i].get_intfo(0) << "|" ;   
        if(cont[i].get_intfo(1).length() >= 10)
        {
            std::string last_name = cont[i].get_intfo(1);
            last_name.resize(9);
            std::cout << last_name << "." << "|" ;
        }
        else
            std::cout << std::setw(10) << cont[i].get_intfo(1) << "|";
        if(cont[i].get_intfo(2).length() >= 10)
        {   
            std::string nickname = cont[i].get_intfo(2);
            nickname.resize(9);
            std::cout << nickname << "." << "|";
        }
        else 
            std::cout << std::setw(10) << cont[i].get_intfo(2) << "|";
        if(cont[i].get_intfo(3).length() >= 10)
        {   
            std::string darksecret = cont[i].get_intfo(3);
            darksecret.resize(9);
            std::cout << darksecret << "." << "|";
        }
        else 
            std::cout << std::setw(10) << cont[i].get_intfo(3) <<"|";
        if(cont[i].get_intfo(4).length() >= 10)
        {   
            std::string PhoneNumer = cont[i].get_intfo(4);
            PhoneNumer.resize(9);
            std::cout << PhoneNumer << "." << "|\n";
        }
        else 
            std::cout << std::setw(10) << cont[i].get_intfo(4) <<"|\n";
        i++;
    }
}

void    PhoneBook::display_one_contact(int index)
{
    index--;
    std::string str;
    str = cont[index].get_intfo(0);
    std::cout << "first name : " << str << "\n";
    str = cont[index].get_intfo(1);
    std::cout << "last name : " << str << "\n";
    str = cont[index].get_intfo(2);
    std::cout << "nickname : " << str << "\n";
    str = cont[index].get_intfo(3);
    std::cout << "darkest secreut : " << str << "\n";
    str = cont[index].get_intfo(4);
    std::cout << "phone number : " << str << "\n";
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
        while (line.empty())
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
            if (!std::isdigit(line[i]))
            {
                std::cerr << "please entre only digit\n";
                i = 0;
                std::cerr << str;
                std::getline(std::cin, line);
                continue;
            }
        }
    }
    return (line);

}

int             Contact::handle_noprintable(const std::string &str)
{
    int i;

    i = -1;
    while (str[++i])
    {
        if (std::isprint(str[i]))
            return (0);
    }
    return (1);
}

void        Contact::exit_phone_book()
{
    std::cout << "you exit phonebook application now, GOODbye !" << "\n";
    exit(0);
}

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
        if (std::cin.eof() || data.handle_noprintable(line))
            exit (0);
        if (!line.compare("ADD"))
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
        else if (!line.compare("SEARCH"))
        {
            add.display_all_contact(i);
            std::cout<<"\nEntre the index : ";
            std::getline(std::cin, line);
            if (std::cin.eof() || std::isprint(line[0]))
                exit (0);
            J = -1;
            while (line[++J])
            {
                if (!std::isdigit(line[J]))
                {
                    std::cerr << "please entre only digit\n";
                    J = -1;
                    std::cerr << "\nEntre the index : ";
                    std::getline(std::cin, line);
                    continue;
                }
            }
            while (line.empty() || (std::stoi(line) < 1 ||  std::stoi(line) > 8))
            {
                std::cerr << "Something wrong !" << "\n";
                std::cout<<"\nEntre the index : ";
                std::getline(std::cin, line);
            }
            add.display_one_contact(std::stoi(line));
        }
        else if (!line.compare("EXIT"))
            data.exit_phone_book();
    }
}

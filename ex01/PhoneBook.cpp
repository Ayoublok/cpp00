/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayylaaba <ayylaaba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 15:33:21 by ayylaaba          #+#    #+#             */
/*   Updated: 2023/09/18 18:16:41 by ayylaaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

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

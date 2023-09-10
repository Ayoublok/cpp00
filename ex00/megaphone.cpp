/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayylaaba <ayylaaba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 15:33:21 by ayylaaba          #+#    #+#             */
/*   Updated: 2023/09/10 16:30:41 by ayylaaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

class Contact
{
    private :
        std::string first_name;
        std::string last_name;
        std::string nick_name;
        std::string darksecret;
        std::string phone_number;
    public:
        void            catch_contact(int c, std::string str);
//        std::string     display_contact(int c);
        void            display_contact(int c);
};


void    Contact::catch_contact(int c, std::string str)
{    
    if (c == 0)
        first_name = str;
    else if (c == 1)
        last_name = str;
    else if (c == 2)
        nick_name = str;
    else if (c == 3)
        darksecret = str;
}

// std::string    Contact::display_contact(int c)
// {
//     if (c == 0)
//         return (first_name);
//     else if (c == 1)
//         return (last_name);
//     else if (c == 2)
//         return(nick_name);
//     else if (c == 3)
//        return (phone_number);
//     return (0);
// }
void    Contact::display_contact(int c)
{
    if (c == 0)
        std::cout << "first_name " << first_name << "\n";
    else if (c == 1)
        std::cout << "last_name " << last_name << "\n";
    else if (c == 2)
        std::cout << "nick_name " << nick_name << "\n";
    else if (c == 3)
        std::cout << "darksecret " << darksecret << "\n";
}

std::string    check_fill_field(std::string str, Contact data)
{
    std::string line;
    std::cout << str;
    std::getline(std::cin, line);
    while (line.empty())
    {
        std::cout << "please fill the field" << "\n";
        std::cout << str;
        std::getline(std::cin, line);
    }
    return (line);
}

void    display_all(Contact data)
{
    data.display_contact(0);
    data.display_contact(1);
    data.display_contact(2);
    data.display_contact(3);
}

int     main()
{
    std::string line;
    std::string type_line;
    std::string li;
    Contact     data;
    while (1)
    {
        std::cout<<"\nEntre the command : ";
        std::getline(std::cin, line);
        if (!line.compare("ADD"))
        {
            type_line = check_fill_field("Entre the first_name : ", data);
            data.catch_contact(0, type_line);
            type_line = check_fill_field("Entre the last_name : ", data);
            data.catch_contact(1, type_line);
            type_line = check_fill_field("Entre the NICK_NAME : ", data);
            data.catch_contact(2, type_line);
            type_line = check_fill_field("Entre the darkset secret : ", data);
            data.catch_contact(3, type_line);
            display_all(data);
        }
        else if (!line.compare("SEARCH"))
        {
            // MOST TO FILL.
        }
    }
}

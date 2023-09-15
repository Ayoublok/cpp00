/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayylaaba <ayylaaba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 16:09:30 by ayylaaba          #+#    #+#             */
/*   Updated: 2023/09/14 18:17:44 by ayylaaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <iostream>
#include <string>
#include <iomanip>
#include "PhoneBook.hpp"

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
		std::string     get_intfo(int c);
		std::string     check_fill_field(std::string str, int  x);
		Contact         creat_contact();
        void            exit_phone_book();
        int             handle_noprintable(const std::string &str);
};

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayylaaba <ayylaaba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 16:08:11 by ayylaaba          #+#    #+#             */
/*   Updated: 2023/09/14 16:15:12 by ayylaaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include <iostream>
#include <string>
#include <iomanip>
#include "Contact.hpp"
 
class	PhoneBook
{
	private:
		Contact cont[8];
        int     i = 0;
        int     j = 0; // ask about it
	public:
        void            set_cont(Contact other);
        void            display_all_contact(int x);
        void            display_one_contact(int x);
};

#endif
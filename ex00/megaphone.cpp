/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayylaaba <ayylaaba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 18:02:29 by ayylaaba          #+#    #+#             */
/*   Updated: 2023/09/14 15:45:55 by ayylaaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>

int     main(int ac, char **av)
{
  
    int     i;
    int     j;
    char    c;

    i = 1;
    if (ac >= 2)
    {
        while (i < ac)
        {
            j = 0;
            while (av[i][j])
            {
                if (islower(av[i][j]))
                {
                    c = std::toupper(av[i][j]); // fun c++ END OF LINE 
                    std::cout << c;
                }
                else
                    std::cout << av[i][j];
                j++; 
            }
            i++;
        }
    }
    else
        std :: cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
    std::cout << "\n";
}

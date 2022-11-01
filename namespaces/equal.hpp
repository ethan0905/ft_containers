/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   equal.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esafar <esafar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 17:05:06 by esafar            #+#    #+#             */
/*   Updated: 2022/11/01 17:24:41 by esafar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EQUAL_HPP
# define EQUAL_HPP

# include <iostream>

namespace ft
{
    template <class InputIterator1, class InputIterator2>
    bool equal(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2)
    {
        while (first1 != last1)
        {
            // std::cout << "OUTP: " << *first1 << " " << *first2 << std::endl;
            if (!(*first1 == *first2))
                return false; 
            ++first1;
            ++first2;
        }
        return true;
    }
}

#endif
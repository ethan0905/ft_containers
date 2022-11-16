/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enable_if.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: c2h6 <c2h6@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 19:03:00 by esafar            #+#    #+#             */
/*   Updated: 2022/11/15 15:23:43 by c2h6             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENABLE_IF_HPP
# define ENABLE_IF_HPP

#include <iostream>
// #include <type_traits>

#include "is_integral.hpp"

namespace ft
{
    template <bool B, class T = void>
    struct enable_if {};

    template <class T>
    struct enable_if<true, T> { typedef T type; };
}

// // for the test: 
// //// for std
// template <class T>
// typename std::enable_if<std::is_integral<T>::value,bool>::type
//   is_odd_std (T i) {return bool(i%2);}

// // 2. the second template argument is only valid if T is an integral type:
// template < class T,
//            class = typename std::enable_if<std::is_integral<T>::value>::type>
// bool is_even_std (T i) {return !bool(i%2);}

// //// for ft
// template <class T>
// typename ft::enable_if<ft::is_integral<T>::value,bool>::type
//   is_odd_ft (T i) {return bool(i%2);}

// // 2. the second template argument is only valid if T is an integral type:
// template < class T,
//            class = typename ft::enable_if<ft::is_integral<T>::value>::type>
// bool is_even_ft (T i) {return !bool(i%2);}

#endif
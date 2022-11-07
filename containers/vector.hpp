/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esafar <esafar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 17:56:32 by esafar            #+#    #+#             */
/*   Updated: 2022/11/07 14:31:05 by esafar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

#include <iostream>
#include <memory>
#include "stack.hpp"

// std::allocator allows us to allocate memory for our vector and to deallocate

namespace ft
{
    template<class T, class Allocator = std::allocator<T>>
    class vector {
        public:
            typedef T value_type;
            typedef Allocator allocator_type;
            typedef typename Base::pointer  pointer;
        private:
        public:
            explicit vector(const allocator_type &alloc = Allocator()) : {}
    };
}

#endif
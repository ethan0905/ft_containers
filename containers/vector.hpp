/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esafar <esafar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 17:56:32 by esafar            #+#    #+#             */
/*   Updated: 2022/11/08 16:34:10 by esafar           ###   ########.fr       */
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
    template<class T, class Allocator = std::allocator<T> >
    class vector {
        public:
            typedef T value_type;
            typedef Allocator allocator_type;
            typedef typename Allocator::pointer  pointer;
            typedef typename Allocator::size_type size_type;
            
        private:
            allocator_type _alloc;
            pointer _ptr;
            size_type _size;
            size_type _capacity;
            
        public:
            // Constructors
            explicit vector(const allocator_type& alloc = allocator_type()) : _alloc(alloc), _ptr(NULL), _size(0), _capacity(0) {}
            explicit vector(size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()) : _alloc(alloc), _ptr(NULL), _size(0), _capacity(0) {
                assign(n, val);
            }
    };
}

#endif
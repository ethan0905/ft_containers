/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esafar <esafar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 17:56:32 by esafar            #+#    #+#             */
/*   Updated: 2022/11/11 18:41:35 by esafar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

#include <iostream>
#include <memory>
#include "stack.hpp"
#include "../header/color.h"

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
            pointer _vector;
            size_type _size;
            size_type _capacity;
            
        public:
            // Constructors
            explicit vector(const allocator_type& alloc = allocator_type()) : _alloc(alloc), _vector(NULL), _size(0), _capacity(0) { std::cout << CYAN "Default constructor" END << std::endl; }
            explicit vector(size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()) : _alloc(alloc), _size(n), _capacity(n), _vector(_alloc.allocate(n)){
                std::cout << CYAN "Constructor with n and val" END << std::endl;
                for (size_type i = 0; i < n; i++)
                    _alloc.construct(_vector + i, val);
            }
            template <class InputIterator>
            vector(InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type()) : _alloc(alloc), _vector(NULL), _size(0), _capacity(0) {
                std::cout << CYAN "Constructor with iterators" END << std::endl;
                InputIterator it = first;
                
                while (it != last)
                {
                    push_back(*it);
                    it++;
                }
            }
            vector(const vector& x) : _alloc(x._alloc), _vector(NULL), _size(0), _capacity(0) {
                std::cout << CYAN "Copy constructor" END << std::endl;
                for (size_type i = 0; i < x._size; i++)
                    push_back(x._vector[i]);
            }
            ~vector() {
                std::cout << RED "Destructor" END << std::endl;
                for (size_type i = 0; i < _size; i++)
                    _alloc.destroy(_vector + i);
                _alloc.deallocate(_vector, _capacity);
            }
            // Operators
            vector& operator=(const vector& x) {
                std::cout << CYAN "Assignation = operator" END << std::endl;
                if (this != &x)
                {
                    for (size_type i = 0; i < _size; i++)
                        _alloc.destroy(_vector + i);
                        
                    _alloc.deallocate(_vector, _capacity);
                    _size = x._size;
                    _capacity = x._capacity;
                    _vector = _alloc.allocate(_capacity);

                    for (size_type i = 0; i < x._size; i++)
                        _alloc.construct(_vector + i, x._vector[i]); // push_back(x._vector[i]);
                }
                return (*this);
            }
            // push_back
            void push_back(const value_type& val) {
                if (_size == _capacity)
                    reserve(_capacity + 1);
                _alloc.construct(_vector + _size, val);
                _size++;
            }
            // reserve
            void reserve(size_type n) {
                if (n > _capacity) {
                    pointer tmp = _alloc.allocate(n);
                    for (size_type i = 0; i < _size; i++)
                        _alloc.construct(tmp + i, _vector[i]);
                    for (size_type i = 0; i < _size; i++)
                        _alloc.destroy(_vector + i);
                    _alloc.deallocate(_vector, _capacity);
                    _vector = tmp;
                    _capacity = n;
                }
            }
    };
}

#endif
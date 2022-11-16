/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: c2h6 <c2h6@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 17:56:32 by esafar            #+#    #+#             */
/*   Updated: 2022/11/15 15:22:49 by c2h6             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

#include <iostream>
#include <memory>
#include "stack.hpp"
#include "../namespaces/enable_if.hpp"
#include "../namespaces/is_integral.hpp"
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
                std::cout << CYAN "Constructor with n and val called" END << std::endl;
                for (size_type i = 0; i < n; i++)
                    _alloc.construct(_vector + i, val);
            }
            // use enable_if to check if the type is an iterator and is_integral to check if it's an integer
            template<class InputIterator>
			vector(InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type(), typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type* = NULL)
				: _alloc(alloc), _capacity(0), _size(0) {
                std::cout << CYAN "Constructor with iterators called" END << std::endl;
                for (InputIterator it = first; it != last; it++)
                    push_back(*it);
			}
            vector(const vector& x) : _alloc(x._alloc), _vector(NULL), _size(0), _capacity(0) {
                std::cout << CYAN "Copy constructor called" END << std::endl;
                for (size_type i = 0; i < x._size; i++)
                    push_back(x._vector[i]);
            }
            ~vector() {
                std::cout << RED "Destructor called" END << std::endl;
                for (size_type i = 0; i < _size; i++)
                    _alloc.destroy(_vector + i);
                _alloc.deallocate(_vector, _capacity);
            }
            // Operators
            vector& operator=(const vector& x) {
                std::cout << CYAN "Assignation = operator called" END << std::endl;
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
            // iterator
            class iterator {
                public:
                    typedef T value_type;
                    typedef T* pointer;
                    typedef T& reference;
                    typedef std::ptrdiff_t difference_type;
                    typedef std::random_access_iterator_tag iterator_category;
                private:
                    pointer _ptr;
                public:
                    iterator() : _ptr(NULL) {}
                    iterator(pointer ptr) : _ptr(ptr) {}
                    iterator(const iterator& it) : _ptr(it._ptr) {}
                    ~iterator() {}
                    iterator& operator=(const iterator& it) {
                        if (this != &it)
                            _ptr = it._ptr;
                        return (*this);
                    }
                    bool operator==(const iterator& it) const { 
                        return (_ptr == it._ptr);
                    }
                    bool operator!=(const iterator& it) const { 
                        return (_ptr != it._ptr);
                    }
                    bool operator<(const iterator& it) const { 
                        return (_ptr < it._ptr);
                    }
                    bool operator<=(const iterator& it) const { 
                        return (_ptr <= it._ptr);
                    }
                    bool operator>(const iterator& it) const { 
                        return (_ptr > it._ptr);
                    }
                    bool operator>=(const iterator& it) const { 
                        return (_ptr >= it._ptr);
                    }
                    iterator& operator++() { 
                        _ptr++;
                        return (*this);
                    }
                    iterator operator++(int) { 
                        iterator tmp(*this);
                        _ptr++;
                        return (tmp);
                    }
                    iterator& operator--() { 
                        _ptr--;
                        return (*this);
                    }
                    iterator operator--(int) { 
                        iterator tmp(*this);
                        _ptr--;
                        return (tmp);
                    }
                    iterator operator+(difference_type n) const { 
                        std::cout << YELLOW "N value: "  << n << END << std::endl;
                        return (iterator(_ptr + n));
                    }
                    iterator operator-(difference_type n) const { 
                        std::cout << YELLOW "N value: "  << n << END << std::endl;
                        return (iterator(_ptr - n));
                    }
                    iterator& operator+=(difference_type n) { 
                        _ptr += n;
                        return (*this);
                    }
                    iterator& operator-=(difference_type n) { 
                        _ptr -= n;
                        return (*this);
                    }
                    reference operator*() const { 
                        return (*_ptr);
                    }
                    pointer operator->() const { 
                        return (_ptr);
                    }
                    reference operator[](difference_type n) const { 
                        return (*(_ptr + n));
                    }
            };
            //begin and end
            iterator begin() {
                return (iterator(_vector));
            }
            iterator end() {
                return (iterator(_vector + _size));
            }
            
    };
}

#endif
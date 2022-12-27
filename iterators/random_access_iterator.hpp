/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random_access_iterator.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esafar <esafar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 13:51:28 by esafar            #+#    #+#             */
/*   Updated: 2022/12/27 16:09:06 by esafar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <iostream>
# include <string>
# include <memory>
# include "iterator.hpp"
// # include "../utils/utils.hpp"

namespace ft
{

	template <typename T, class not_const_T = T>
	class random_access_iterator : public ft::iterator< random_access_iterator_tag, T >
	{
		public:
			
			typedef	typename ft::iterator<random_access_iterator_tag, T>::iterator_category			iterator_category;
			typedef	typename ft::iterator<random_access_iterator_tag, T>::pointer					pointer;
			typedef	typename ft::iterator<random_access_iterator_tag, T>::reference					reference;
			typedef	typename ft::iterator<random_access_iterator_tag, not_const_T>::value_type		value_type;
			typedef	typename ft::iterator<random_access_iterator_tag, T>::difference_type			difference_type;
			
			random_access_iterator() : _ptr(NULL) {}
			random_access_iterator(pointer ptr) : _ptr(ptr) {}
			random_access_iterator(const random_access_iterator<not_const_T>& ref) : _ptr(ref.base()) {}
			virtual ~random_access_iterator() {}

			random_access_iterator & operator=(const random_access_iterator<not_const_T>& ref){
				if (this->base() != ref.base())
					this->_ptr = ref.base();
				return (*this);
			}
			random_access_iterator & operator+=(difference_type n){
				this->_ptr += n;
				return (*this);
			}
			random_access_iterator & operator-=(difference_type n){
				this->_ptr -= n;
				return (*this);
			}
			
			pointer				base() const { return this->_ptr; }

			reference 			operator*() const { return *_ptr; }
			pointer 			operator->()  { return _ptr; }
			reference			operator[](int i) { return this->_ptr[i]; }

			random_access_iterator& operator++() { _ptr++; return *this; }
			random_access_iterator operator++(int) { random_access_iterator tmp = *this; ++(_ptr); return (tmp); }
			random_access_iterator& operator--() { _ptr--; return *this; }
			random_access_iterator operator--(int) { random_access_iterator tmp = *this; --(_ptr); return (tmp); }

			friend random_access_iterator	operator+(const random_access_iterator& a, difference_type b) { return random_access_iterator(a.base() + b); }
			friend random_access_iterator	operator+(difference_type b, const random_access_iterator& a) { return random_access_iterator(a.base() + b); }
			friend random_access_iterator	operator-(const random_access_iterator& a, difference_type b) { return random_access_iterator(a.base() - b); }
			friend random_access_iterator	operator-(difference_type b, const random_access_iterator& a) { return random_access_iterator(a.base() - b); }
			friend difference_type	operator-(const random_access_iterator& a, const random_access_iterator& b) { return (a.base() - b.base()); }

			friend bool operator== (const random_access_iterator& a, const random_access_iterator& b) { return (a.base() == b.base()); }
			friend bool operator!= (const random_access_iterator& a, const random_access_iterator& b) { return (a.base() != b.base()); }
			friend bool operator<= (const random_access_iterator& a, const random_access_iterator& b) { return (a.base() <= b.base()); }
			friend bool operator>= (const random_access_iterator& a, const random_access_iterator& b) { return (a.base() >= b.base()); }
			friend bool operator< (const random_access_iterator& a, const random_access_iterator& b) { return (a.base() < b.base()); }
			friend bool operator> (const random_access_iterator& a, const random_access_iterator& b) { return (a.base() > b.base()); }
			
		private:
			pointer				_ptr;

	};
}

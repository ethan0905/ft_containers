/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_iterator.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esafar <esafar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 16:09:23 by esafar            #+#    #+#             */
/*   Updated: 2022/12/27 16:10:49 by esafar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <iostream>
# include <string>
# include <memory>
# include "iterator.hpp"

namespace ft
{
	template <typename Iter>
	class reverse_iterator
	{
		public:

		typedef				Iter											iterator_type;
		typedef	typename	ft::iterator_traits<Iter>::iterator_category	iterator_category;
		typedef	typename	ft::iterator_traits<Iter>::value_type			value_type;
		typedef	typename	ft::iterator_traits<Iter>::difference_type		difference_type;
		typedef	typename	ft::iterator_traits<Iter>::pointer				pointer;
		typedef	typename	ft::iterator_traits<Iter>::reference			reference;

		reverse_iterator() : _it() {}

		explicit reverse_iterator( iterator_type x ) { this->_it = x;}
		
		template< class U >
		reverse_iterator( const reverse_iterator<U>& other ): _it(other.base()) {}

		iterator_type base() const {
			return this->_it;
		}

		template <class U>
		reverse_iterator& operator=(const reverse_iterator<U>& rev_it){
			if (this->base() == rev_it.base())
				return (*this);
			this->_it = rev_it.base();
			return (*this);
		}

		reference operator*() const {
			iterator_type tmp = this->_it;
			return *(--tmp);
		}

		reverse_iterator operator+ (difference_type n) const{
			return (reverse_iterator(this->base() - n));
		}


		reverse_iterator& operator++() {--_it; return (*this);};
		reverse_iterator  operator++(int){reverse_iterator tmp = *this; --_it; return (tmp);};
		reverse_iterator& operator+= (difference_type n){
			this->_it -= n;
			return (*this);
		}
		reverse_iterator operator- (difference_type n) const{
			return (reverse_iterator(this->base() + n));
		}
		reverse_iterator& operator--() {++_it; return (*this);};
		reverse_iterator  operator--(int){reverse_iterator tmp = *this; ++_it; return (tmp);};
		reverse_iterator& operator-= (difference_type n){
			this->_it += n;
			return (*this);
		}
		pointer operator->() { return &(operator*()); }
		reference operator[] (difference_type n) const{
			return (this->base()[-n-1]);
		}

		private:
			iterator_type	_it;

	};

	template< class Iterator1, class Iterator2 >
	bool operator==( const ft::reverse_iterator<Iterator1>& lhs, const ft::reverse_iterator<Iterator2>& rhs ){
		return (rhs.base() == lhs.base());
	}
	template< class Iterator1, class Iterator2 >
	bool operator!=( const ft::reverse_iterator<Iterator1>& lhs, const ft::reverse_iterator<Iterator2>& rhs ){
		return (rhs.base() != lhs.base());
	}
	template< class Iterator1, class Iterator2 >
	bool operator<( const ft::reverse_iterator<Iterator1>& lhs, const ft::reverse_iterator<Iterator2>& rhs ){
		return (rhs.base() < lhs.base());
	}
	template< class Iterator1, class Iterator2 >
	bool operator<=( const ft::reverse_iterator<Iterator1>& lhs, const ft::reverse_iterator<Iterator2>& rhs ){
		return (rhs.base() <= lhs.base());
	}
	template< class Iterator1, class Iterator2 >
	bool operator>( const ft::reverse_iterator<Iterator1>& lhs, const ft::reverse_iterator<Iterator2>& rhs ){
		return (rhs.base() > lhs.base());
	}
	template< class Iterator1, class Iterator2 >
	bool operator>=( const ft::reverse_iterator<Iterator1>& lhs, const ft::reverse_iterator<Iterator2>& rhs ){
		return (rhs.base() >= lhs.base());
	}

	template< class Iter >
	reverse_iterator<Iter> operator+ (typename reverse_iterator<Iter>::difference_type n, const reverse_iterator<Iter>& it ){
		return (reverse_iterator<Iter>(it.base() - n));
	}

	template< class Iterator >
	typename reverse_iterator<Iterator>::difference_type operator-( const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs ){
		return (rhs.base() - lhs.base());
	}

	template <class It1, class It2>
	typename reverse_iterator<It1>::difference_type operator-( const reverse_iterator<It1>& lhs, const reverse_iterator<It2>& rhs)
	{ return rhs.base() - lhs.base(); }
}

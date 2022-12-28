/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: c2h6 <c2h6@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 13:58:31 by esafar            #+#    #+#             */
/*   Updated: 2022/12/28 12:39:41 by c2h6             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <cstddef> // ptrdiff_t

namespace ft {

  class input_iterator_tag  {};
  class output_iterator_tag {};
  class forward_iterator_tag       : public input_iterator_tag         {};
  class bidirectional_iterator_tag : public forward_iterator_tag       {};
  class random_access_iterator_tag : public bidirectional_iterator_tag {};

  template <class Category, class T, class Distance = ptrdiff_t, class Pointer = T*, class Reference = T&>
  class iterator {
    public:
    typedef T           value_type;
    typedef Distance    difference_type;
    typedef Pointer     pointer;
    typedef Reference   reference;
    typedef Category    iterator_category;
  };

  template <class Iterator>
  class iterator_traits {
    public:
    typedef typename Iterator::difference_type    difference_type;
    typedef typename Iterator::value_type         value_type;
    typedef typename Iterator::pointer            pointer;
    typedef typename Iterator::reference          reference;
    typedef typename Iterator::iterator_category  iterator_category;
  };

  template <class T>
  class iterator_traits<T*> {
    public:
    typedef ptrdiff_t                   difference_type;
    typedef T                           value_type;
    typedef T*                          pointer;
    typedef T&                          reference;
    typedef random_access_iterator_tag  iterator_category;
  };

  template <class T>
  class iterator_traits<const T*> {
    public:
    typedef ptrdiff_t                   difference_type;
    typedef T                           value_type;
    typedef const T*                    pointer;
    typedef const T&                    reference;
    typedef random_access_iterator_tag  iterator_category;
  };

  template <class Iterator>
  class reverse_iterator {
	
    protected:
		Iterator _base;

    public:
		typedef Iterator                                                iterator_type;
		typedef typename iterator_traits<Iterator>::iterator_category   iterator_category;
		typedef typename iterator_traits<Iterator>::value_type          value_type;
		typedef typename iterator_traits<Iterator>::difference_type     difference_type;
		typedef typename iterator_traits<Iterator>::pointer             pointer;
		typedef typename iterator_traits<Iterator>::reference           reference;

		reverse_iterator(void)                                 : _base(iterator_type()) {}
		explicit reverse_iterator(iterator_type it)            : _base(it) {}
		template <class Iter>
		reverse_iterator(const reverse_iterator<Iter>& rev_it) : _base(rev_it.base()) {}

		template <class U>
		reverse_iterator& operator=(const reverse_iterator<U>& other) {
		_base = other.base();
		return (*this);
		}

		iterator_type base(void) const { return (_base); }

		reference operator*(void) const {
		iterator_type tmp(_base);
		return (*--tmp);
		}
		pointer   operator->(void) const {
		return (&(operator*()));
		}
		reference operator[](difference_type n) const {
		return (base()[-n - 1]);
		}

		reverse_iterator operator+(difference_type n) const { return (reverse_iterator(base() - n)); }
		reverse_iterator operator-(difference_type n) const { return (reverse_iterator(base() + n)); }

		reverse_iterator& operator++(void) {
		--_base;
		return (*this);
		}
		reverse_iterator operator++(int) {
		reverse_iterator tmp(*this);
		_base--;
		return (tmp);
		}
		reverse_iterator& operator--(void) {
		++_base;
		return (*this);
		}
		reverse_iterator operator--(int) {
		reverse_iterator tmp(*this);
		_base++;
		return (tmp);
		}

		reverse_iterator& operator+=(difference_type n) {
		_base -= n;
		return (*this);
		}
		reverse_iterator& operator-=(difference_type n) {
		_base += n;
		return (*this);
		}
	};

  template <class Iterator1, class Iterator2>
  bool operator==(const reverse_iterator<Iterator1>& lhs, const reverse_iterator<Iterator2>& rhs) { return (lhs.base() == rhs.base()); }
  template <class Iterator1, class Iterator2>
  bool operator!=(const reverse_iterator<Iterator1>& lhs, const reverse_iterator<Iterator2>& rhs) { return (lhs.base() != rhs.base()); }
  template <class Iterator1, class Iterator2>
  bool operator< (const reverse_iterator<Iterator1>& lhs, const reverse_iterator<Iterator2>& rhs) { return (lhs.base() > rhs.base()); }
  template <class Iterator1, class Iterator2>
  bool operator> (const reverse_iterator<Iterator1>& lhs, const reverse_iterator<Iterator2>& rhs) { return (lhs.base() < rhs.base()); }
  template <class Iterator1, class Iterator2>
  bool operator<=(const reverse_iterator<Iterator1>& lhs, const reverse_iterator<Iterator2>& rhs) { return (lhs.base() >= rhs.base()); }
  template <class Iterator1, class Iterator2>
  bool operator>=(const reverse_iterator<Iterator1>& lhs, const reverse_iterator<Iterator2>& rhs) { return (lhs.base() <= rhs.base()); }

  template <class Iterator>
  reverse_iterator<Iterator> operator+(typename reverse_iterator<Iterator>::difference_type n, const reverse_iterator<Iterator>& rev_it) {
    return (rev_it + n);
  }

  template <class Iterator1, class Iterator2>
  typename reverse_iterator<Iterator1>::difference_type operator-(const reverse_iterator<Iterator1>& lhs, const reverse_iterator<Iterator2>& rhs) {
    return (rhs.base() - lhs.base());
  }

  template <typename T>
  class random_access_iterator : public iterator<random_access_iterator_tag, T> {
    public:
		typedef typename iterator<random_access_iterator_tag, T>::value_type          value_type;
		typedef typename iterator<random_access_iterator_tag, T>::difference_type     difference_type;
		typedef typename iterator<random_access_iterator_tag, T>::pointer             pointer;
		typedef typename iterator<random_access_iterator_tag, T>::reference           reference;
		typedef typename iterator<random_access_iterator_tag, T>::iterator_category   iterator_category;

    protected:
		pointer _ptr;

    public:
		random_access_iterator(void)                                 : _ptr(NULL) {}
		random_access_iterator(pointer ptr)                          : _ptr(ptr) {}
		random_access_iterator(const random_access_iterator<T>& ref) : _ptr(ref._ptr) {}

		operator random_access_iterator<const value_type>() const {
		return random_access_iterator<const value_type>(_ptr);
		}

		random_access_iterator& operator=(const random_access_iterator& ref) {
		if (this != &ref)
			_ptr = ref._ptr;
		return (*this);
		}

		virtual ~random_access_iterator() {}

		pointer base(void) const { return (_ptr); }

		reference operator* (void) const              { return (*_ptr); }
		pointer   operator->(void) const              { return (&(operator*())); }
		reference operator[](difference_type n) const { return (_ptr[n]); }

		random_access_iterator operator+(difference_type n) const { return (_ptr + n); }
		random_access_iterator operator-(difference_type n) const { return (_ptr - n); }

		random_access_iterator& operator++(void) {
		++_ptr;
		return (*this);
		}
		random_access_iterator operator++(int) {
		random_access_iterator tmp(*this);
		_ptr++;
		return (tmp);
		}
		random_access_iterator& operator--(void) {
		--_ptr;
		return (*this);
		}
		random_access_iterator operator--(int) {
		random_access_iterator tmp(*this);
		_ptr--;
		return (tmp);
		}

		random_access_iterator& operator+=(difference_type n) {
		_ptr += n;
		return (*this);
		}
		random_access_iterator& operator-=(difference_type n) {
		_ptr -= n;
		return (*this);
		}
	};

  template <typename T1, typename T2>
  bool operator==(const random_access_iterator<T1>& lhs, const random_access_iterator<T2>& rhs) { return (lhs.base() == rhs.base()); }
  template <typename T1, typename T2>
  bool operator!=(const random_access_iterator<T1>& lhs, const random_access_iterator<T2>& rhs) { return (lhs.base() != rhs.base()); }
  template <typename T1, typename T2>
  bool operator< (const random_access_iterator<T1>& lhs, const random_access_iterator<T2>& rhs) { return (lhs.base() < rhs.base()); }
  template <typename T1, typename T2>
  bool operator> (const random_access_iterator<T1>& lhs, const random_access_iterator<T2>& rhs) { return (lhs.base() > rhs.base()); }
  template <typename T1, typename T2>
  bool operator<=(const random_access_iterator<T1>& lhs, const random_access_iterator<T2>& rhs) { return (lhs.base() <= rhs.base()); }
  template <typename T1, typename T2>
  bool operator>=(const random_access_iterator<T1>& lhs, const random_access_iterator<T2>& rhs) { return (lhs.base() >= rhs.base()); }

  template <typename T>
  random_access_iterator<T> operator+(typename random_access_iterator<T>::difference_type n, const random_access_iterator<T>& rev_it) {
    return (rev_it + n);
  }

  template <typename T1, typename T2>
  typename random_access_iterator<T1>::difference_type operator-(const random_access_iterator<T1>& lhs, const random_access_iterator<T2>& rhs) {
    return (lhs.base() - rhs.base());
  }
}
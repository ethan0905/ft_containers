/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esafar <esafar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 14:02:26 by esafar            #+#    #+#             */
/*   Updated: 2022/12/27 16:07:56 by esafar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include <memory>

#include "../iterators/random_access_iterator.hpp"
#include "../iterators/reverse_iterator.hpp"
#include "../std_functions/enable_if.hpp"
#include "../std_functions/is_integral.hpp"
#include "../std_functions/lexicographical_compare.hpp"

// std::allocator allows us to allocate memory for our vector and to deallocate

namespace ft
{

	template<typename Iterator>
	std::ptrdiff_t distance(Iterator first, Iterator last) { //, typename ft::check_type<typename ft::iterator_traits<Iterator>::iterator_category>::type* = 0) {
		std::ptrdiff_t dist = 0;
		while (first != last) {
			++dist;
			++first;
		}
		return dist;
	}

	template <class T, class Alloc = std::allocator<T> > // generic template
	class vector
	{
		public:
			typedef T value_type;
			typedef Alloc allocator_type;
			typedef typename allocator_type::size_type size_type;
			typedef typename allocator_type::difference_type difference_type;
			typedef typename allocator_type::reference reference;
			typedef typename allocator_type::const_reference const_reference;
			typedef typename allocator_type::pointer pointer;
			typedef typename allocator_type::const_pointer const_pointer;
			typedef ft::random_access_iterator<value_type> iterator;
			typedef ft::random_access_iterator<const value_type, value_type> const_iterator;
			typedef ft::reverse_iterator<iterator> reverse_iterator;
			typedef ft::reverse_iterator<const_iterator> const_reverse_iterator;

		private:
			allocator_type	_alloc;		/*	allocator calss holding object	*/
			pointer			_array;		/*	Pointer on an array of T values	*/
			size_type		_size;		/*	current size of the obj 		*/
			size_type		_capacity;	/*	current capacity of the obj 	*/

			/*	Reallocate a vector with the newCapacity, and copy previous contents to the new one. 
			Previous allocator is destroyed calling the destrcutor */

			void _reallocateVec(size_type newCapacity)
			{
				pointer tmp = _alloc.allocate(newCapacity);		// create new array with newCap
				size_type size = _size;							// keep previous size
				for (size_type i = 0; i < size; i++)			
					_alloc.construct(&tmp[i], _array[i]);
				this->~vector();
				this->_array = tmp;
				this->_size = size;
				this->_capacity = newCapacity;
			}
		public:

            // Constructors :
            // Constructs an empty container, with no elements.
			explicit vector(const allocator_type &alloc = allocator_type()) : _alloc(alloc), _size(0), _capacity(0)
			{
				_array = _alloc.allocate(_capacity);
			}
		
			// Constructs a container with n elements. Each element is a copy of val.
			explicit vector(size_type n, const value_type &val = value_type(), const allocator_type &alloc = allocator_type()) : _alloc(alloc), _size(0), _capacity(n)
			{
				_array = _alloc.allocate(n);
				for (size_type i = 0; i < n; i++)
				{
					_alloc.construct(&_array[i], val);
					_size++;
				}
			}

			// Constructs a container with as many elements as the range [first,last), with each element constructed from its corresponding element in that range, in the same order.
			template <typename InputIterator>
			vector(InputIterator first, InputIterator last, const allocator_type &alloc = allocator_type(),
				typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type * = 0) : _alloc(alloc), _size(0), _capacity(0)
			{
				for (InputIterator it = first; it != last; it++)
					this->_size++;
				this->_capacity = _size;
				this->_array = _alloc.allocate(this->_capacity);
				int i = 0;
				for (InputIterator it = first; it != last; it++)
				{
					_alloc.construct(&_array[i], *it);
					i++;
				}
			}

			// Copy constructor
			vector(const vector &x) : _alloc(x._alloc), _size(x._size), _capacity(x._capacity)
			{
				this->_array = this->_alloc.allocate(x.capacity());
				for (size_type i = 0; i < x.size(); i++)
					this->_alloc.construct(&(this->_array[i]), x[i]);
			}

			// Returns a reference to the element at position n in the vector container.
			~vector()
			{
				this->clear();
				_alloc.deallocate(_array, this->capacity());
			}
		
		/* Assigns new contents to the container, replacing its current contents, and modifying its size accordingly. */
		vector &operator=(const vector &x)
		{
			if (*this != x)
			{
				this->clear();
				this->_alloc.deallocate(this->_array, this->capacity());

				this->_array = this->_alloc.allocate(x.capacity());
				this->_size = x.size();
				this->_capacity = x.capacity();

				for (size_type i = 0; i < x.size(); i++)
					this->_alloc.construct(&(this->_array[i]), x[i]);
			}
			return (*this);
		}

		// iterator
		iterator begin() { return (iterator(_array)); }
		const_iterator begin() const { return (const_iterator(_array)); }
		iterator end() { return (iterator(_array + this->size())); }
		const_iterator end() const { return (const_iterator(_array + this->size())); }

		reverse_iterator       rbegin() { return reverse_iterator(this->end()); }
		const_reverse_iterator rbegin()	 const{ return const_reverse_iterator(this->end());};
		reverse_iterator       rend() { return reverse_iterator(this->begin()); }
		const_reverse_iterator rend() const{ return const_reverse_iterator(this->begin());};


		size_type size() const { return (this->_size); }
		size_type max_size() const { return (this->_alloc.max_size()); }
		void resize(size_type n, value_type val = value_type())
		{
			if (n < _size) // shrink size
			{
				while (n < _size)
					pop_back();
			}
			else if (n > _size && n < _capacity) // add element but don't change capacity
			{
				for (size_type i = _size; i < n; i++)
					push_back(val);
			}
			else // create an _array with twice the previous capacity
			{
				this->reserve(n);	// Reserve a new array with new_capacity, and copy previous content to it.
				for (size_type i = _size; i < n; i++)
					_alloc.construct(&_array[i], val);
				this->_size = n;
			}
		}

		size_type capacity() const { return (this->_capacity); }

		// Return whether the vector is empty (i.e. whether its size is 0).
		bool empty() const { return (this->size() == 0); }

		// Requests that the vector capacity be at least enough to contain n elements.
		void reserve(size_type n)
		{
			if (n > this->max_size())
				throw std::length_error("size requested is greater than the maximum size (vector::max_size)\n");
			if (n > this->capacity())
				_reallocateVec(n);
		}

		// Operators
		reference operator[](size_type n) { return (_array[n]); }
		const_reference operator[](size_type n) const { return (_array[n]); }

		reference at(size_type n)
		{
			if (n < 0 || n >= this->size())
				throw std::out_of_range("Accessing out of range element in vector\n");
			return (_array[n]);
		}

		const_reference at(size_type n) const
		{
			if (n < 0 || n >= this->size())
				throw std::out_of_range("Accessing out of range element in vector\n");
			return (_array[n]);
		}

		reference front() { return (_array[0]); }
		const_reference front() const { return (_array[0]); }

		reference back() { return (_array[(this->size() - 1)]); }
		const_reference back() const { return (_array[(this->size() - 1)]); }

		template <class InputIterator>
		void	assign (InputIterator first, InputIterator last, typename enable_if<!is_integral<InputIterator>::value>::type* = 0) {
			this->clear();
			while (first != last) {
				push_back(*first);
				++first;
			}
		}
		void	assign(size_type n, const value_type& val) {
			this->clear();
			while (n) {
				push_back(val);
				--n;
			}
		}

		void push_back(const value_type &val)
		{
			if (_size + 1 > _capacity)
				(_capacity == 0) ? _reallocateVec(1) : _reallocateVec(_capacity * 2);
			_alloc.construct(&_array[_size++], val);
		}
		
		void pop_back()
		{
			if (_size > 0)
			{
				_alloc.destroy(&_array[_size - 1]);
				_size--;
			}
		}

		iterator insert (iterator position, const value_type& val) {
			size_type n = ft::distance(begin(), position);
			insert(position, 1, val);
			return (iterator(&this->_array[n]));
		}
		void insert (iterator position, size_type n, const value_type& val) {
			vector tmp(position, end());
			this->_size -= ft::distance(position, end());
			while (n) {
				push_back(val);
				--n;
			}
			iterator it = tmp.begin();
			while (it != tmp.end()) {
				push_back(*it);
				++it;
			}
		}
		template <class InputIterator>
		void insert (iterator position, InputIterator first, InputIterator last, typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type * = 0) {
			vector tmp(position, end());
			this->_size -= ft::distance(position, end());
			while (first != last) {
				push_back(*first);
				++first;
			}
			iterator it = tmp.begin();
			while (it != tmp.end()) {
				push_back(*it);
				++it;
			}
		}

		iterator erase(iterator position)
		{
			return erase(position, position + 1);
		}

		iterator erase(iterator first, iterator last)
		{
			size_type n = first - this->begin();
			size_type len = last - first;

			for (size_type i = n; i < this->_size && i + len < this->_size; i++)
			{
				(*this)[i] = (*this)[i + len];
			}
			for (difference_type i = 0; i < last - first; i++)
				this->pop_back();
			//vector<value_type>::iterator ret = this->begin() + n; 
			return this->begin() + n;
		}

		void clear()
		{
			while (_size > 0)
				pop_back();
		}

		void swap(vector &x)
		{
			allocator_type tmp_alloc = this->_alloc;
			pointer tmp_array = this->_array;
			size_type tmp_size = this->_size;
			size_type tmp_capacity = this->_capacity;

			this->_alloc = x._alloc;
			this->_array = x._array;
			this->_size = x._size;
			this->_capacity = x._capacity;

			x._alloc = tmp_alloc;
			x._array = tmp_array;
			x._size = tmp_size;
			x._capacity = tmp_capacity;
		}

		allocator_type get_allocator() const { return (this->_alloc); }
	};

	template <class T, class Alloc>
	void swap (vector<T,Alloc>& x, vector<T,Alloc>& y)
	{
		x.swap(y);
	}

	template <class T, class Alloc>
	bool operator== (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{
		if (lhs.size() != rhs.size())
			return (false);
		size_t i = 0;
		while (i < lhs.size())
		{
			if (lhs[i] != rhs[i])
				return (false);
			i++;
		}
		return (true);
	}

	template <class T, class Alloc>
	bool operator!= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{
		return(!(lhs==rhs));
	}

	template <class T, class Alloc>
	bool operator<  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{
		return (lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
	}
	template <class T, class Alloc>
	bool operator<= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{
		return ((lhs == rhs) || (lhs < rhs));
	}
	template <class T, class Alloc>
	bool operator>  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{
		return (!(lhs == rhs) && !(lhs < rhs));
	}

	template <class T, class Alloc>
	bool operator>= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{
		return (!(lhs < rhs));
	}
}

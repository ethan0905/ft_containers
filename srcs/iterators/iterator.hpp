/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esafar <esafar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 13:58:31 by esafar            #+#    #+#             */
/*   Updated: 2022/12/27 16:08:42 by esafar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <iostream>
# include <string>
# include <memory>

namespace ft
{
	template <
		class Category,               	// iterator::iterator_category
		class T,                        // iterator::value_type
		class Distance = std::ptrdiff_t,     // iterator::difference_type
		class Pointer = T*,             // iterator::pointer
		class Reference = T&            // iterator::reference
	>
	class iterator
	{
		public:
			typedef			T								value_type;
			typedef			Distance						difference_type;
			typedef			Pointer							pointer;
			typedef			Reference						reference;
			typedef			Category						iterator_category;
	};

	struct input_iterator_tag {};
	struct output_iterator_tag {};
	struct forward_iterator_tag : public input_iterator_tag {};
	struct bidirectional_iterator_tag : public forward_iterator_tag {};
	struct random_access_iterator_tag : public bidirectional_iterator_tag {};
	
	template< class Iter >
	struct iterator_traits
	{
		typedef	typename	Iter::difference_type				difference_type;
		typedef	typename	Iter::value_type					value_type;
		typedef	typename	Iter::pointer						pointer;
		typedef	typename	Iter::reference						reference;
		typedef	typename	Iter::iterator_category				iterator_category;
	};

	template< class T >
	struct iterator_traits<T*> 
	{
		typedef			std::ptrdiff_t						difference_type;
		typedef			T									value_type;
		typedef			T*									pointer;
		typedef			T&									reference;
		typedef			random_access_iterator_tag		iterator_category;
	};

	template< class T >
	struct iterator_traits<const T*>
	{
		typedef			std::ptrdiff_t						difference_type;
		typedef			T									value_type;
		typedef			const T*							pointer;
		typedef			const T&							reference;
		typedef			random_access_iterator_tag		iterator_category;
	};
}

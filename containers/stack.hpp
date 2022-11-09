/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esafar <esafar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 14:17:23 by esafar            #+#    #+#             */
/*   Updated: 2022/11/09 17:22:06 by esafar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_HPP
# define STACK_HPP

# include <iostream>
# include <vector>

// typedef allows us to give a new name to an existing data type
// explicit keyword allows only direct-initialization (avoid implicit conversions and copy initialization from braced-init-list)
// friend keyword allows a function to access private and protected members of a class

namespace ft
{
    template <class T, class Container = std::vector<T> >
    class stack
    {
        public:
            typedef T value_type;
            typedef Container container_type;

        private:
            container_type _container;

        public:
            // constructor/ destructor / operator=
            explicit stack(const container_type& ctnr = container_type()) : _container(ctnr) {}
            ~stack() {}
            stack& operator=(const stack& x) {
                _container = x._container;
                return (*this);
            }
            // element access
            value_type& top() {
                return (_container.back());
            }
            const value_type& top() const {
                return (_container.back());
            }
            // capacity
            bool empty() const {
                return (_container.empty());
            }
            size_t size() const {
                return (_container.size());
            }
            // modifiers
            void push(const value_type& val) {
                _container.push_back(val);
            }
            void pop() {
                _container.pop_back();
            }
            // relational operators
            friend bool operator==(const stack<T, Container>& lhs, const stack<T, Container>& rhs) {
                return (lhs._container == rhs._container);
            }
            friend bool operator!=(const stack<T, Container>& lhs, const stack<T, Container>& rhs) {
                return (lhs._container != rhs._container);
            }
            friend bool operator<(const stack<T, Container>& lhs, const stack<T, Container>& rhs) {
                return (lhs._container < rhs._container);
            }
            friend bool operator<=(const stack<T, Container>& lhs, const stack<T, Container>& rhs) {
                return (lhs._container <= rhs._container);
            }
            friend bool operator>(const stack<T, Container>& lhs, const stack<T, Container>& rhs) {
                return (lhs._container > rhs._container);
            }
            friend bool operator>=(const stack<T, Container>& lhs, const stack<T, Container>& rhs) {
                return (lhs._container >= rhs._container);
            }
    };
}

#endif
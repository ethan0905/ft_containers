/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_test.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esafar <esafar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 18:29:44 by esafar            #+#    #+#             */
/*   Updated: 2022/11/08 15:55:35 by esafar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <memory>
#include <vector>
#include "../header/color.h"

// # include "vector.hpp"

// max storage inside std::allocator<int> of size 1 is long int

int main(void)
{
    std::cout << YELLOW "==============STD::ALLOCATOR==============" END << std::endl;

    std::allocator<int> alloc;
    
    std::cout << WHITE "alloc.allocate(1)" << std::endl;
    int *p = NULL;
    
    p = alloc.allocate(1);

    std::cout << "Allocated *ptr: " << *p << std::endl << std::endl;

    std::cout << "alloc.construct(p, 42)" << std::endl;
    alloc.construct(p, 42);
    
    std::cout << "Allocated *ptr: " << *p << std::endl << std::endl;
    
    std::cout << "alloc.destroy(p)" << std::endl;
    alloc.destroy(p);

    std::cout << "Allocated *ptr: " << *p << std::endl << std::endl;

    std::cout << "alloc.deallocate(p, 1)" << END << std::endl;
    alloc.deallocate(p, 1);
    
    std::cout << YELLOW "==============STD::VECTOR<int>==============" END << std::endl;
    
    std::vector<int> v;
    
    std::cout << "v.push_back(i)" << std::endl;
    for (int i = 0; i < 10; i++)
        v.push_back(i);
    
    std::vector<int>::iterator it = v.begin(); 
    std::vector<int>::iterator ite = v.end();

    for (; it != ite; it++)
        std::cout << CYAN "*it = " << *it << END << std::endl;
    
    std::cout << "v.size(): " << v.size() << std::endl;
    std::cout << "v.capacity(): " << v.capacity() << std::endl;
    
    // // std::cout << "v.capacity(): " << v.capacity() << std::endl;
    // // std::cout << "v.max_size(): " << v.max_size() << std::endl;
    // // std::cout << "v.empty(): " << v.empty() << std::endl;
    // // std::cout << "v.front(): " << v.front() << std::endl;
    // // std::cout << "v.back(): " << v.back() << std::endl;
    // // std::cout << "v.at(5): " << v.at(5) << std::endl;
    // // std::cout << "v.data(): " << v.data() << std::endl;
    // // std::cout << "v.begin(): " << *v.begin() << std::endl;
    // // std::cout << "v.end(): " << *v.end() << std::endl;
    // // std::cout << "v.rbegin(): " << *v.rbegin() << std::endl;
    // // std::cout << "v.rend(): " << *v.rend() << std::endl;
    // // std::cout << "v.assign(1, 42)" << std::endl;
    // // v.assign(1, 42);
    
    // // vector::insert
    std::cout << "v.insert(v.begin(), 55)" << std::endl;
    v.insert(v.begin(), 55);

    std::vector<int>::iterator it2 = v.begin();
    std::vector<int>::iterator ite2 = v.end();

    for (; it2 != ite2; it2++)
        std::cout << CYAN "*it2 = " << *it2 << END << std::endl;
 
    std::cout << "v.insert(v.end(), 77)" << *v.end() << std::endl; 
    v.insert(v.end(), 77);
    
    std::vector<int>::iterator it3 = v.begin();
    std::vector<int>::iterator ite3 = v.end();
    
    for (; it3 != ite3; it3++)
        std::cout << CYAN "*it3 = " << *it3 << END << std::endl;

    // // vector::erase
    std::cout << "v.erase(v.begin())" << std::endl;
    v.erase(v.begin());

    std::vector<int>::iterator it4 = v.begin();
    std::vector<int>::iterator ite4 = v.end();
    
    for (; it4 != ite4; it4++)
        std::cout << CYAN "*it4 = " << *it4 << END << std::endl;
    
    std::cout << "v.erase(v.begin())" << std::endl;
    v.erase(v.begin(), v.end());

    std::vector<int>::iterator it5 = v.begin();
    std::vector<int>::iterator ite5 = v.end();
    
    for (; it5 != ite5; it5++)
        std::cout << CYAN "*it5 = " << *it5 << END << std::endl;
    
    return (0);
}
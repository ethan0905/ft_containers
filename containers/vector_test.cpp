/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_test.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esafar <esafar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 18:29:44 by esafar            #+#    #+#             */
/*   Updated: 2022/11/07 20:40:26 by esafar           ###   ########.fr       */
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
    std::vector<int>::iterator it = v.begin(); 
    
    std::cout << "v.push_back(i)" << std::endl;

    for (int i = 1; i <= 10; i++)
        v.push_back(i);

    std::vector<int>::iterator ite = v.end();

    for (; it != ite; it++)
        std::cout << CYAN "*it = " << *it << END << std::endl;
    
    // std::cout << "v.size(): " << v.size() << std::endl;
    // std::cout << "v.capaity(): " << v.capacity() << std::endl;

    // v.push_back(1);
    // v.push_back(2);
    // v.push_back(3);
    // v.push_back(4);

    // std::vector<int>::iterator it2 = v.begin();
    
    // for (; it2 != ite; it2++)
    //     std::cout << CYAN "*it = " << *it2 << END << std::endl;
    
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
    // std::cout << "v.insert(v.begin(), 70)" << std::endl;
    // v.insert(v.begin(), 70);

    // std::vector<int>::iterator it3 = v.begin();

    // for (; it3 != ite; it3++)
    //     std::cout << CYAN "*it = " << *it3 << END << std::endl;
 
    // std::cout << "v.insert(v.end(), 71)" << *v.end() << std::endl; 
    // v.insert(v.end(), 71);
    
    // std::vector<int>::iterator it4 = v.begin();
    
    // for (; it4 != ite; it4++)
    //     std::cout << CYAN "*it = " << *it4 << END << std::endl;

    // // vector::erase
    // // std::cout << "v.erase(v.begin())" << std::endl;
    // // v.erase(v.begin());
    // // v.erase(v.begin());
    // // v.erase(v.begin());
    // // v.erase(v.begin());
    
    // // for (int i = 0; i < 20; i++)
    // //     std::cout << "v[" << i << "]: " << v[i] << std::endl;
    
    return (0);
}
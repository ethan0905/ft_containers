/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_test.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esafar <esafar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 18:29:44 by esafar            #+#    #+#             */
/*   Updated: 2022/11/06 19:02:39 by esafar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <memory>

// max storage inside std::allocator<int> of size 1 is long int

int main(void)
{
    std::allocator<int> alloc;
    
    std::cout << "alloc.allocate(1)" << std::endl;
    int *p = alloc.allocate(1);

    std::cout << "Allocated *ptr: " << *p << std::endl << std::endl;

    std::cout << "alloc.construct(p, 42)" << std::endl;
    alloc.construct(p, 42);
    
    std::cout << "Allocated *ptr: " << *p << std::endl << std::endl;
    
    std::cout << "alloc.destroy(p)" << std::endl;
    alloc.destroy(p);

    std::cout << "Allocated *ptr: " << *p << std::endl << std::endl;

    std::cout << "alloc.deallocate(p, 1)" << std::endl;
    alloc.deallocate(p, 1);
    
    return (0);
}
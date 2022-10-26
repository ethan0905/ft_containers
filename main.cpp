/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esafar <esafar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 17:36:39 by esafar            #+#    #+#             */
/*   Updated: 2022/10/26 18:23:54 by esafar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
#include <iostream>

// test std::vector
int main(int ac, char **av)
{
    (void)ac;
    (void)av;
    
    // using ::iterator and ::reverse_iterator
    std::vector<int> v;
    std::vector<int>::iterator it;
    std::vector<int>::reverse_iterator rit;

    v.push_back(1);
    std::cout << "Max capacity: " << v.capacity() << std::endl;
    v.push_back(2);
    std::cout << "Max capacity: " << v.capacity() << std::endl;
    v.push_back(3);
    std::cout << "Max capacity: " << v.capacity() << std::endl;
    v.push_back(4);
    std::cout << "Max capacity: " << v.capacity() << std::endl;
    v.push_back(5);
    std::cout << "Max capacity: " << v.capacity() << std::endl;
    v.push_back(6);
    std::cout << "Max capacity: " << v.capacity() << std::endl;
    v.push_back(7);
    std::cout << "Max capacity: " << v.capacity() << std::endl;
    v.push_back(8);
    std::cout << "Max capacity: " << v.capacity() << std::endl;
    v.push_back(9);
    std::cout << "Max capacity: " << v.capacity() << std::endl;
    v.push_back(10);
    std::cout << "Max capacity: " << v.capacity() << std::endl;

    it = v.begin();
    rit = v.rbegin();
    while (it != v.end())
    {
        std::cout << *it << std::endl;
        it++;
    }
    while (rit != v.rend())
    {
        std::cout << *rit << std::endl;
        rit++;
    }

    std::cout << std::endl;
    std::cout << std::endl;

    // using insert() function
    std::vector<std::string> v2;
    std::vector<std::string>::iterator it2;
    
    v2.push_back("Hello");
    v2.push_back("World");
    v2.push_back("!");
    
    it2 = v2.begin();
    it2++;
    v2.insert(it2, "C++");
    it2 = v2.begin();
    while (it2 != v2.end())
    {
        std::cout << *it2 << std::endl;
        it2++;
    }
    
    // testing clear() function
    v.clear();
    it = v.begin();
    while (it != v.end())
    {
        std::cout << *it << std::endl;
        it++;
    }
    std::cout << "Max capacity: " << v.capacity() << std::endl;
    
    // testing erase() function
    v.erase(v.begin(), v.end());
    it = v.begin();
    while (it != v.end())
    {
        std::cout << *it << std::endl;
        it++;
    }
    std::cout << "Max capacity: " << v.capacity() << std::endl;

    return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esafar <esafar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 17:36:39 by esafar            #+#    #+#             */
/*   Updated: 2022/10/26 18:00:55 by esafar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
#include <iostream>
#include <string>

// test using std::vector
int main(int ac, char **av)
{
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
    return (0);
}

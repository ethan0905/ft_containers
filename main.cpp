/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esafar <esafar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 17:36:39 by esafar            #+#    #+#             */
/*   Updated: 2022/10/26 17:46:52 by esafar           ###   ########.fr       */
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
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);
    v.push_back(6);
    v.push_back(7);
    v.push_back(8);
    v.push_back(9);
    v.push_back(10);

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

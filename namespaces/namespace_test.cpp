/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   namespace_test.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esafar <esafar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 13:25:57 by esafar            #+#    #+#             */
/*   Updated: 2022/11/01 17:24:46 by esafar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "equal.hpp"
#include "lexicographical_compare.hpp"
#include "is_integral.hpp"

#include <vector>

int main()
{
    std::vector<int> v1;
    std::vector<int> v2;

    v1.push_back(1);
    v1.push_back(2);
    v1.push_back(3);
    v1.push_back(4);
    v1.push_back(5);

    v2.push_back(1);
    v2.push_back(2);
    v2.push_back(3);
    v2.push_back(4);
    v2.push_back(5);

    std::cout << "===============STD::EQUAL===============" << std::endl;

    if (std::equal(v1.begin(), v1.end(), v2.begin()))
        std::cout << "std::equal: true" << std::endl;
    else
        std::cout << "std::equal: false" << std::endl;

    if (ft::equal(v1.begin(), v1.end(), v2.begin()))
        std::cout << "ft::equal: true" << std::endl;
    else
        std::cout << "ft::equal: false" << std::endl;

    std::cout << std::endl;

    std::cout << "===============STD::LEXICO===============" << std::endl;

    if (std::lexicographical_compare(v1.begin(), v1.end(), v2.begin(), v2.end()))
        std::cout << "std::lexicographical_compare: true" << std::endl;
    else
        std::cout << "std::lexicographical_compare: false" << std::endl;
        
    if (ft::lexicographical_compare(v1.begin(), v1.end(), v2.begin(), v2.end()))
        std::cout << "ft::lexicographical_compare: true" << std::endl;
    else
        std::cout << "ft::lexicographical_compare: false" << std::endl;

    std::boolalpha(std::cout << std::endl);
    
    std::cout << "===============STD::IS_INTEGRAL===============" << std::endl;
    
    std::cout << "is_integral<int> : " << std::is_integral<int>::value << std::endl;
    std::cout << "is_integral<int> : " << ft::is_integral<int>::value << std::endl << std::endl;
    
    std::cout << "is_integral<char> : " << std::is_integral<char>::value << std::endl;
    std::cout << "is_integral<char> : " << ft::is_integral<char>::value << std::endl << std::endl;
    
    std::cout << "is_integral<float> : " << std::is_integral<float>::value << std::endl;
    std::cout << "is_integral<float> : " << ft::is_integral<float>::value << std::endl << std::endl;
    
    std::cout << "is_integral<double> : " << std::is_integral<double>::value << std::endl;
    std::cout << "is_integral<double> : " << ft::is_integral<double>::value << std::endl << std::endl;
    
    std::cout << "is_integral<std::string> : " << std::is_integral<std::string>::value << std::endl;
    std::cout << "is_integral<std::string> : " << ft::is_integral<std::string>::value << std::endl;

    return (0);
}
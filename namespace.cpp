/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   namespace.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esafar <esafar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 13:25:57 by esafar            #+#    #+#             */
/*   Updated: 2022/10/31 14:17:49 by esafar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>

// re-code equal from std (std::equal)
namespace ft
{
    template <class InputIterator1, class InputIterator2>
    bool equal(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2)
    {
        while (first1 != last1)
        {
            // std::cout << "OUTP: " << *first1 << " " << *first2 << std::endl;
            if (!(*first1 == *first2))
                return false; 
            ++first1;
            ++first2;
        }
        return true;
    }
}

// re-code lexicographical_compare from std (std::lexicographical_compare)
namespace ft
{
    template <class InputIterator1, class InputIterator2>
    bool lexicographical_compare(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, InputIterator2 last2)
    {
        while (first1 != last1)
        {
            // std::cout << "OUTP: " << *first1 << " " << *first2 << std::endl;
            if (first2 == last2 || *first2 < *first1)
                return false;
            else if (*first1 < *first2)
                return true;
            ++first1;
            ++first2;
        }
        return (first2 != last2);
    }
}

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

    if (std::equal(v1.begin(), v1.end(), v2.begin()))
        std::cout << "std::equal: true" << std::endl;
    else
        std::cout << "std::equal: false" << std::endl;

    if (ft::equal(v1.begin(), v1.end(), v2.begin()))
        std::cout << "ft::equal: true" << std::endl;
    else
        std::cout << "ft::equal: false" << std::endl;

    std::cout << std::endl;

    if (std::lexicographical_compare(v1.begin(), v1.end(), v2.begin(), v2.end()))
        std::cout << "std::lexicographical_compare: true" << std::endl;
    else
        std::cout << "std::lexicographical_compare: false" << std::endl;
        
    if (ft::lexicographical_compare(v1.begin(), v1.end(), v2.begin(), v2.end()))
        std::cout << "ft::lexicographical_compare: true" << std::endl;
    else
        std::cout << "ft::lexicographical_compare: false" << std::endl;

    return (0);
}
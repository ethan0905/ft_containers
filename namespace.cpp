/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   namespace.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esafar <esafar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 13:25:57 by esafar            #+#    #+#             */
/*   Updated: 2022/10/31 13:38:56 by esafar           ###   ########.fr       */
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
            if (!(*first1 == *first2))
                return false;
            ++first1;
            ++first2;
        }
        return true;
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

    if (ft::equal(v1.begin(), v1.end(), v2.begin()))
        std::cout << "v1 and v2 are: EQUAL" << std::endl;
    else
        std::cout << "v1 and v2 are: NOT equal" << std::endl;
    return (0);
}
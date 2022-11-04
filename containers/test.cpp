/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esafar <esafar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 15:00:54 by esafar            #+#    #+#             */
/*   Updated: 2022/11/04 15:51:35 by esafar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <stack>
// #include <vector>
// #include <list>
// #include <deque>

int main()
{
    std::cout << std::boolalpha;

    std::cout << "==============STD::STACK==============" << std::endl;
    
    std::stack<int> s;
    
    std::cout << "stack.empty(): " << s.empty() << std::endl << std::endl;

    for (int i = 0; i < 10; i++)
        s.push(i);
    
    std::cout << "stack.top(): " << s.top() << std::endl;
    std::cout << "stack.size(): " << s.size() << std::endl << std::endl;
    std::cout << "stack.pop()" << std::endl << std::endl;
    s.pop();
    std::cout << "stack.top(): " << s.top() << std::endl;
    std::cout << "stack.size(): " << s.size() << std::endl << std::endl;
    std::cout << "stack.empty(): " << s.empty() << std::endl << std::endl;
    
    return (0);
}
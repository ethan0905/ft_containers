/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esafar <esafar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 15:00:54 by esafar            #+#    #+#             */
/*   Updated: 2022/11/04 16:30:42 by esafar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <stack>
#include <vector>

int main(void)
{
    std::cout << std::boolalpha;

    std::cout << "==============STD::STACK==============" << std::endl;
    // test std::stack
    
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
    
    std::cout << "--------------------------------------" << std::endl;
        
    // test std::stack with a vector
    std::vector<int> v;
    

    std::cout << "vector.empty(): " << v.empty() << std::endl << std::endl;
    
    for (int i = 0; i < 10; i++)
        v.push_back(i);
    
    std::stack<int, std::vector<int> > s2(v);
    
    std::cout << "stack.top(): " << s2.top() << std::endl;
    std::cout << "stack.size(): " << s2.size() << std::endl << std::endl;
    std::cout << "stack.pop()" << std::endl << std::endl;
    s2.pop();
    std::cout << "stack.top(): " << s2.top() << std::endl;
    std::cout << "stack.size(): " << s2.size() << std::endl << std::endl;
    std::cout << "stack.empty(): " << s2.empty() << std::endl << std::endl;

    return (0);
}
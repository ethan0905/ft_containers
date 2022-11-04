/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esafar <esafar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 15:00:54 by esafar            #+#    #+#             */
/*   Updated: 2022/11/04 15:35:07 by esafar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <stack>
#include <vector>
#include <list>
#include <deque>

// main that test the std::stack

int main()
{
    std::stack<int> a;
    
    for (int i = 0; i < 10; i++)
        a.push(i);
    
    std::cout << "stack.top(): " << a.top() << std::endl;
    std::cout << "stack.size(): " << a.size() << std::endl << std::endl;
    std::cout << "stack.pop()" << std::endl << std::endl;
    a.pop();
    std::cout << "stack.top(): " << a.top() << std::endl;
    std::cout << "stack.size(): " << a.size() << std::endl << std::endl;
    std::cout << "stack.empty(): " << a.empty() << std::endl << std::endl;
    std::cout << "stack.top(): " << a.top() << std::endl;
    std::cout << "stack.size(): " << a.size() << std::endl;
    
    return (0);
}
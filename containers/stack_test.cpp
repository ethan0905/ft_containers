/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_test.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esafar <esafar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 15:00:54 by esafar            #+#    #+#             */
/*   Updated: 2022/12/19 13:38:35 by esafar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <stack>
#include <vector>

#include "stack.hpp"

int main(void)
{
    std::cout << std::boolalpha;

    std::cout << "==============STD::STACK<int>==============" << std::endl;
    
    std::stack<int> stack_std;
    ft::stack<int> stack_ft;

    std::cout << "std::stack.empty(): " << stack_std.empty() << std::endl;
    std::cout << "ft::stack.empty(): " << stack_ft.empty() << std::endl << std::endl;

    for (int i = 0; i <= 10; i++)
        stack_std.push(i);
    
    for (int i = 0; i <= 10; i++)
        stack_ft.push(i);
    
    std::cout << "std::stack.top(): " << stack_std.top() << std::endl;
    std::cout << "ft::stack.top(): " << stack_ft.top() << std::endl << std::endl;
    
    std::cout << "std::stack.size(): " << stack_std.size() << std::endl;
    std::cout << "ft::stack.size(): " << stack_ft.size() << std::endl << std::endl;
    
    std::cout << "std::stack.pop()" << std::endl;
    std::cout << "ft::stack.pop()" << std::endl << std::endl;
    
    stack_std.pop();
    stack_ft.pop();
    
    std::cout << "std::stack.top(): " << stack_std.top() << std::endl;
    std::cout << "ft::stack.top(): " << stack_ft.top() << std::endl << std::endl;
    
    std::cout << "std::stack.size(): " << stack_std.size() << std::endl;
    std::cout << "ft::stack.size(): " << stack_ft.size() << std::endl << std::endl;
    
    std::cout << "std::stack.empty(): " << stack_std.empty() << std::endl;
    std::cout << "ft::stack.empty(): " << stack_ft.empty() << std::endl << std::endl;
    
    std::cout << "==============STD::STACK<int, std::vector>==============" << std::endl;
        
    std::vector<int> vector_std;

    std::cout << "std::vector.empty(): " << vector_std.empty() << std::endl << std::endl;

    for (int i = 0; i <= 10; i++)
        vector_std.push_back(i);
    
    std::stack<int, std::vector<int> > stack2_std(vector_std);
    ft::stack<int, std::vector<int> > stack2_ft(vector_std);

    std::cout << "std::stack.empty(): " << stack2_std.empty() << std::endl;
    std::cout << "ft::stack.empty(): " << stack2_ft.empty() << std::endl << std::endl;
    
    std::cout << "std::stack.top(): " << stack2_std.top() << std::endl;
    std::cout << "ft::stack.top(): " << stack2_ft.top() << std::endl << std::endl;
    
    std::cout << "std::stack.size(): " << stack2_std.size() << std::endl;
    std::cout << "ft::stack.size(): " << stack2_ft.size() << std::endl << std::endl;
    
    std::cout << "std::stack.pop()" << std::endl;
    std::cout << "ft::stack.pop()" << std::endl << std::endl;
    
    stack2_std.pop();
    stack2_ft.pop();
    
    std::cout << "std::stack.top(): " << stack2_std.top() << std::endl;
    std::cout << "ft::stack.top(): " << stack2_ft.top() << std::endl << std::endl;
    
    std::cout << "std::stack.size(): " << stack2_std.size() << std::endl;
    std::cout << "ft::stack.size(): " << stack2_ft.size() << std::endl << std::endl;
    
    std::cout << "std::stack.empty(): " << stack2_std.empty() << std::endl;
    std::cout << "ft::stack.empty(): " << stack2_ft.empty() << std::endl << std::endl;

    return (0);
}
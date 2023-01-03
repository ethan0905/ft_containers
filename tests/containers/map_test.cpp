// #include "map.hpp"
#include <map>
#include <iostream>
#include "../../incls/color.hpp"

int main()
{
    std::map<int, int> map;

    std::cout << WHITE "std::map.empty() = " << map.empty() << END << std::endl << std::endl;

    map.insert(std::make_pair(1, 1));
    map.insert(std::make_pair(2, 2));
    map.insert(std::make_pair(3, 3));
    map.insert(std::make_pair(4, 4));
    map.insert(std::make_pair(5, 5));

    std::map<int, int>::iterator it = map.begin();

    ++it;
    map.erase(it);
    --it;
    map.erase(it);

    for (std::map<int, int>::iterator it = map.begin(); it != map.end(); ++it)
        std::cout << WHITE "std::map<" << it->first << ", " << it->second << ">" END << std::endl;

    // map.at() test
    std::cout << std::endl;
    for (std::map<int, int>::iterator it = map.begin(); it != map.end(); ++it)
        std::cout << WHITE "std::map.at(" << it->first << ") = " << map.at(it->first) << END << std::endl;

    // map.operator[] test
    std::cout << std::endl;
    for (std::map<int, int>::iterator it = map.begin(); it != map.end(); ++it)
        std::cout << WHITE "std::map[" << it->first << "] = " << map[it->first] << END << std::endl;
    
    // map.empty() test
    std::cout << std::endl;
    std::cout << WHITE "std::map.empty() = " << map.empty() << END << std::endl;

    // map.size() test
    std::cout << std::endl;
    std::cout << WHITE "std::map.size() = " << map.size() << END << std::endl;

    // map.max_size() test
    std::cout << WHITE "std::map.max_size() = " << map.max_size() << END << std::endl;

    // map.begin() test
    std::cout << std::endl;
    std::cout << WHITE "std::map.begin() = " << map.begin()->first << END << std::endl;

    // map.end() test
    std::cout << WHITE "std::map.end() = " << map.end()->first << END << std::endl;

    // map.rbegin() test
    std::cout << WHITE "std::map.rbegin() = " << map.rbegin()->first << END << std::endl;

    // map.rend() test
    std::cout << WHITE "std::map.rend() = " << map.rend()->first << END << std::endl;

    // map.find() test
    std::cout << std::endl;
    std::cout << WHITE "std::map.find(3) = " << map.find(3)->first << END << std::endl;

    // map.count() test
    std::cout << WHITE "std::map.count(3) = " << map.count(3) << END << std::endl;
    
    // map.equal_range() test
    std::cout << WHITE "std::map.equal_range(4) = " << map.equal_range(4).first->first << END << std::endl;

    // map.lower_bound() test
    std::cout << WHITE "std::map.lower_bound(4) = " << map.lower_bound(4)->first << END << std::endl;

    // map.upper_bound() test
    std::cout << WHITE "std::map.upper_bound(4) = " << map.upper_bound(4)->first << END << std::endl;

    // map.clear() test
    std::cout << std::endl;
    map.clear();
    std::cout << WHITE "std::map.clear()" END << std::endl;

    // map.empty() test
    std::cout << std::endl;
    std::cout << WHITE "std::map.empty() = " << map.empty() << END << std::endl;

    return (0);
}
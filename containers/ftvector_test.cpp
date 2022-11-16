#include "vector.hpp"

int main()
{
    ft::vector<int> vector_ft; // default constructor
    ft::vector<int> vector_ft2(5, 3); // value constructor
    std::vector<int> vector_ftstd2(5, 3); // value constructor
    ft::vector<int> vector_ft3(vector_ftstd2.begin(), vector_ftstd2.end()); // iterator constructor - need to fix
    ft::vector<int> vector_ft4(vector_ft2); // copy constructor
    ft::vector<int> vector_ft5 = vector_ft4; // copy constructor
    ft::vector<int> vector_ft6; // default constructor
    vector_ft6 = vector_ft5; // assignation = operator

    // std::cout << "vector_ft2: ";
    // for (ft::vector<int>::iterator it = vector_ft2.begin(); it != vector_ft2.end(); it++)
    //     std::cout << *it << " ";
    // std::cout << std::endl;

    // test iterators    
    std::cout << "vector_ft3: ";
    for (ft::vector<int>::iterator it = vector_ft3.begin(); it != vector_ft3.end(); it++)
        std::cout << *it << "\n";
    return (0);
}
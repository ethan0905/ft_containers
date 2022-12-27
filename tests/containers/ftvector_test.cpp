#include "../srcs/containers/vector.hpp"

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

    // test iterators    
    std::cout << "vector_ft6: ";
    for (ft::vector<int>::iterator it = vector_ft6.begin(); it != vector_ft6.end(); it++)
        std::cout << "vector[i]= " << *it << std::endl;
    return (0);
}
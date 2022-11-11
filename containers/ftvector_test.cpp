#include "vector.hpp"

int main()
{
    ft::vector<int> vector_ft; // default constructor
    ft::vector<int> vector_ft2(5, 42); // value constructor
    std::vector<int> vector_ftstd2(5, 42); // value constructor
    // ft::vector<int> vector_ft3(vector_ftstd2.begin(), vector_ftstd2.end()); // iterator constructor - need to fix
    ft::vector<int> vector_ft4(vector_ft2); // copy constructor
    ft::vector<int> vector_ft5 = vector_ft4; // copy constructor
    ft::vector<int> vector_ft6; // default constructor
    vector_ft6 = vector_ft5; // assignation = operator
    // test all vector functions

    // std::vector<int> vector_std;
    // std::vector<int> vector_std2(5, 42);
    // std::vector<int> vector_std3(vector_std2.begin(), vector_std2.end());
    // std::vector<int> vector_std4(vector_std3);
    // std::vector<int> vector_std5 = vector_std4;
    // std::vector<int> vector_std6;
    // vector_std6 = vector_std5;

    return (0);
}
#include "array_and_strings.h"
#include <stdint.h>
#include <iostream>
#include <exception>


int main()
{
    std::string str = "abcdef";
    std::string to_check = "fedcba";
    std::cout << "out: " << is_permutation(str, to_check) << std::endl;
    return 0;
}
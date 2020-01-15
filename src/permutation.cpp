#include "permutation.h"


void permutation(std::string str, std::string prefix)
{
    if (str.length() == 0)
    {
        std::cout << prefix << std::endl;
    }
    else
    {
        for (uint i = 0; i < str.length(); i++)
        {
            std::string rem = str.substr(0, i) + str.substr(i + 1);
            std::cout << "rem: " << rem << std::endl;
            permutation(rem, prefix + str[i]);
        }
    } 
}

void permutation(std::string str)
{
    permutation(str, "");
}
#include "sorts.hpp"

#include <iostream>
#include <cstdlib>

bool sorted(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
    for (std::vector<int>::iterator prev = begin, cur = begin; ++cur != end; ++prev)
    {
        if (*prev > *cur)
        {
            return false;
        }
    }
    return true;
}
void print(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
    for (std::vector<int>::iterator it = begin; it != end; ++it)
    {
        std::cout << *it << ' ';
    }
    std::cout << std::endl;
}
void rand(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
    srand((unsigned)time(NULL));

    for (std::vector<int>::iterator it = begin; it != end; ++it)
    {
        *it = rand();
    }
}
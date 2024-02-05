#pragma once

#include <string_view>
#include <vector>

namespace utility
{
    template <class ForwardIterator>
    std::pair<int, ForwardIterator> minElement(ForwardIterator begin, ForwardIterator end);

    template <class ForwardIterator>
    int cycleShift(ForwardIterator it1, ForwardIterator it2);

    // template <class ForwardIterator>
    // std::pair<int, ForwardIterator> lowerBound(ForwardIterator begin, ForwardIterator end, int value);
};

/*template <class ForwardIterator>
int utility::lowerBound(ForwardIterator begin, ForwardIterator end, int value)
{
    int compare = 0;
    ForwardIterator l = begin, r = end;
    while (r - l > 1)
    {
        ForwardIterator m = (l + r) / 2;
        ++compare;
        if (*m > value)
        {
            r = m;
        }
        else
        {
            l = m;
        }
    }
    return {compare, l};
}*/
#include <stdint.h>
static inline uint32_t log2(const uint32_t x)
{
    uint32_t y;
    asm("\tbsr %1, %0\n"
        : "=r"(y)
        : "r"(x));
    return y;
}
namespace sort
{
    template <class ForwardIterator>
    std::pair<int, int> selection(ForwardIterator begin, ForwardIterator end);

    template <class ForwardIterator>
    std::pair<int, int> binsertion(ForwardIterator begin, ForwardIterator end);

    template <class ForwardIterator>
    std::pair<int, int> insertion(ForwardIterator begin, ForwardIterator end);

    template <class ForwardIterator>
    std::pair<int, int> bubble(ForwardIterator begin, ForwardIterator end);

    template <class ForwardIterator>
    std::pair<int, int> shaker(ForwardIterator begin, ForwardIterator end);
}

bool sorted(std::vector<int>::iterator begin, std::vector<int>::iterator end);
void print(std::vector<int>::iterator begin, std::vector<int>::iterator end);
void rand(std::vector<int>::iterator begin, std::vector<int>::iterator end);

template <class ForwardIterator>
std::pair<int, ForwardIterator> utility::minElement(ForwardIterator begin, ForwardIterator end)
{
    int assign = 0;
    ForwardIterator result = begin;
    for (ForwardIterator it = begin; it != end; ++it)
    {
        if (*it < *result)
        {
            ++assign;
            result = it;
        }
    }
    return {assign, result};
}

template <class ForwardIterator>
int utility::cycleShift(ForwardIterator it1, ForwardIterator it2)
{
    int assign = 0;
    ForwardIterator prev = it2 - 1, cur = it2 - 1;
    for (; --cur >= it1; --prev)
    {
        ++assign;
        std::swap(*prev, *cur);
    }
    return assign;
}

template <class ForwardIterator>
std::pair<int, int> sort::selection(ForwardIterator begin, ForwardIterator end)
{
    int assign = end - begin, compare = 0;
    for (ForwardIterator it = begin; it != end; ++it)
    {
        compare += (end - it);
        auto m = utility::minElement(it, end);
        std::swap(*it, *(m.second));
    }
    return {assign, compare};
}

template <class ForwardIterator>
std::pair<int, int> sort::binsertion(ForwardIterator begin, ForwardIterator end)
{
    int assign = 0, compare = 0;
    for (ForwardIterator prev = begin, cur = begin; ++cur != end; ++prev)
    {
        ++compare;
        if (*prev > *cur)
        {
            compare += log2(cur - begin);
            assign += utility::cycleShift(std::lower_bound(begin, cur, *cur), cur + 1);
        }
    }
    return {assign, compare};
}

template <class ForwardIterator>
std::pair<int, int> sort::insertion(ForwardIterator begin, ForwardIterator end)
{
    int assign = 0, compare = 0;
    for (ForwardIterator prev = begin, cur = begin; ++cur != end; ++prev)
    {
        ++compare;
        if (*prev > *cur)
        {
            while (prev >= begin && *prev > *cur)
            {
                ++compare;
                --prev;
            }
            ++compare;
            assign += utility::cycleShift(prev + 1, cur + 1);
            prev = cur;
            --prev;
        }
    }
    return {assign, compare};
}

template <class ForwardIterator>
std::pair<int, int> sort::bubble(ForwardIterator begin, ForwardIterator end)
{
    int assign = 0, compare = 0;
    for (ForwardIterator it = begin; it != end; ++it)
    {
        for (ForwardIterator prev = begin, cur = begin; ++cur != end; ++prev)
        {
            ++compare;
            if (*prev > *cur)
            {
                ++assign;
                std::swap(*prev, *cur);
            }
        }
    }
    return {assign, compare};
}

template <class ForwardIterator>
std::pair<int, int> sort::shaker(ForwardIterator begin, ForwardIterator end)
{
    int assign = 0, compare = 0;
    for (ForwardIterator it = begin; it != end; ++it)
    {
        ++compare;
        if ((it - begin) % 2 == 0)
        {
            for (ForwardIterator prev = begin, cur = begin; ++cur != end; ++prev)
            {
                ++compare;
                if (*prev > *cur)
                {
                    ++assign;
                    std::swap(*prev, *cur);
                }
            }
        }
        else
        {
            for (ForwardIterator prev = end, cur = end; --cur != begin; --prev)
            {
                ++compare;
                if (*prev < *cur)
                {
                    ++assign;
                    std::swap(*prev, *cur);
                }
            }
        }
    }
    return {assign, compare};
}
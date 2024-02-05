#include "sorts.hpp"

#include <fstream>
#include <vector>

std::pair<long double, long double> get(int sort, std::vector<int> &v)
{
    long double assign = 0, compare = 0;
    for (int i = 0; i < 7; ++i)
    {
        std::pair<long double, long double> a;
        switch (sort)
        {
        case 0:
            a = sort::binsertion(v.begin(), v.end());
            break;
        case 1:
            a = sort::bubble(v.begin(), v.end());
            break;
        case 2:
            a = sort::insertion(v.begin(), v.end());
            break;
        case 3:
            a = sort::selection(v.begin(), v.end());
            break;
        case 4:
            a = sort::shaker(v.begin(), v.end());
            break;
        }
        assign += a.first / 7., compare += a.second / 7.;
    }
    return {assign, compare};
}

int main()
{
    std::vector<int> sz = {1024, 1001, 3241, 4353, 4555, 7432, 8432, 8435, 9321, 9340};
    std::vector<std::vector<long double>> assign(5, std::vector<long double>(10, 0)), compare(5, std::vector<long double>(10, 0));
    for (int j = 0; j < 10; ++j)
    {
        for (int i = 0; i < 5; ++i)
        {
            std::vector<int> v(sz[j], 0);
            rand(v.begin(), v.end());
            std::pair<long double, long double> a = get(i, v);
            assign[i][j] = a.first, compare[i][j] = a.second;
        }
    }
    std::ofstream out("data.csv");
    out << "Assign" << std::endl
        << ',';
    for (int i = 0; i < 10; ++i)
    {
        out << sz[i];
        if (i != 9)
        {
            out << ',';
        }
    }
    out << std::endl;
    for (int i = 0; i < 5; ++i)
    {
        switch (i)
        {
        case 0:
            out << "Binsertion,";
            break;
        case 1:
            out << "Bubble,";
            break;
        case 2:
            out << "Insertion,";
            break;
        case 3:
            out << "Selection,";
            break;
        case 4:
            out << "Shaker,";
            break;
        }
        for (int j = 0; j < 10; ++j)
        {
            out << assign[i][j];
            if (j != 9)
            {
                out << ',';
            }
        }
        out << std::endl;
    }
    out << "Compare" << std::endl
        << ',';
    for (int i = 0; i < 10; ++i)
    {
        out << sz[i];
        if (i != 9)
        {
            out << ',';
        }
    }
    out << std::endl;
    for (int i = 0; i < 5; ++i)
    {
        switch (i)
        {
        case 0:
            out << "Binsertion,";
            break;
        case 1:
            out << "Bubble,";
            break;
        case 2:
            out << "Insertion,";
            break;
        case 3:
            out << "Selection,";
            break;
        case 4:
            out << "Shaker,";
            break;
        }
        for (int j = 0; j < 10; ++j)
        {
            out << compare[i][j];
            if (j != 9)
            {
                out << ',';
            }
        }
        if (i != 4)
        {
            out << std::endl;
        }
    }
    out.close();
}
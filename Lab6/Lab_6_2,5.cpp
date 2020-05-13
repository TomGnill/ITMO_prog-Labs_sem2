#include <iostream>
#include<vector>
#include "OAlgo.h"


template<typename T1>
bool it_Equal(T1 value)
{
    return (value > 0 && value < 5);
}
template<typename T2>
bool It_SORTED(int x, int y)
{
    return x <= y;
}
template<typename T3>
bool It_palendrome(T3 x)
{
    return (x > 1 && x < 5);
}

int main()
{
    std::vector <int> array = {3,2,4,2,8,4,2,4,5};
    std::cout << ((is_sorted(array.begin(), array.end(), It_SORTED<int>)) ? "YES" : "NO") << std::endl;
    std::cout << ((any_of(array.begin(), array.end(), it_Equal<int>)) ? "YES" : "NO") << std::endl;
    std::cout << ((is_palendrome(array.begin(), array.end(),It_palendrome<int>))? "Yes" : "No") << std::endl;
}


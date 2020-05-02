#include <iostream>

//Task B.
template <typename T>
const T& min(const T& a, const T& b)
{
    return (a < b) ? a : b;
}

int main()
{
    double j = min(2.232, 6.321);
    std::cout << j;

    return 0;
}
  

//task G.

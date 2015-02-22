#include "Polynomial.h"
#include <iostream>

int main()
{
    Polynomial p(3);
    Polynomial p1(6);
    std::cin >> p;
    std::cin >> p1;
    std::cout << std::endl;
    std::cout << p << std::endl;
    std::cout << p1 << std::endl;
    std::cout << (p - p1) << std::endl;

    return 0;
}

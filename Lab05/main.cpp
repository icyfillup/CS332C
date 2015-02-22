#include "Polynomial.h"
#include <iostream>

void displayPoly(const Polynomial& poly1, const Polynomial& poly2);
void polyIsEqual(const Polynomial& poly1, const Polynomial& poly2);
void addPoly(const Polynomial& poly1, const Polynomial& poly2);
void diffPoly(const Polynomial& poly1, const Polynomial& poly2);
void negatePoly(const Polynomial& poly1, const Polynomial& poly2);
void scalarPoly(const Polynomial& poly1, const Polynomial& poly2);

int main()
{
    Polynomial poly1(5);
    Polynomial poly2(6);

    std::cin >> poly1;
    std::cin >> poly2;
    std::cout << std::endl;

    displayPoly(poly1, poly2);
    polyIsEqual(poly1, poly2);
    addPoly(poly1, poly2);
    diffPoly(poly1, poly2);
    negatePoly(poly1, poly2);
    scalarPoly(poly1, poly2);

    return 0;
}

void displayPoly(const Polynomial& poly1, const Polynomial& poly2)
{
    std::cout << "Poly 1:\t" << poly1 << std::endl;
    std::cout << "Poly 2:\t" << poly2 << std::endl;
    std::cout << std::endl;
}

void polyIsEqual(const Polynomial& poly1, const Polynomial& poly2)
{
    std::cout << "(poly1 == poly1):\t" << ((poly1 == poly1) ? "true" : "false")<< std::endl;
    std::cout << "(poly2 == poly2):\t" << ((poly2 == poly2) ? "true" : "false")<< std::endl;
    std::cout << "(poly1 == poly2):\t" << ((poly1 == poly2) ? "true" : "false")<< std::endl;
    std::cout << std::endl;
}

void addPoly(const Polynomial& poly1, const Polynomial& poly2)
{
    std::cout << "(poly1 + poly2):\t" << (poly1 + poly2) << std::endl;
    std::cout << "(poly2 + poly1):\t" << (poly2 + poly1) << std::endl;
    std::cout << std::endl;
}

void diffPoly(const Polynomial& poly1, const Polynomial& poly2)
{
    std::cout << "(poly1 - poly2):\t" << (poly1 - poly2) << std::endl;
    std::cout << "(poly2 - poly1):\t" << (poly2 - poly1) << std::endl;
    std::cout << std::endl;
}

void negatePoly(const Polynomial& poly1, const Polynomial& poly2)
{
    std::cout << "-poly1:\t" << -poly1 << std::endl;
    std::cout << "-poly2:\t" << -poly2 << std::endl;
    std::cout << std::endl;
}

void scalarPoly(const Polynomial& poly1, const Polynomial& poly2)
{
    std::cout << "poly1 * 2:\t" << poly1 * 2 << std::endl;
    std::cout << "poly2 * 5:\t" << poly1 * 5 << std::endl;
    std::cout << "7 * poly1:\t" << 7 * poly1 << std::endl;
    std::cout << "10 * poly2:\t" << 10 * poly1 << std::endl;
}

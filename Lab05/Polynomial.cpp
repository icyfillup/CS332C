#include "Polynomial.h"
#include <iostream>
#include <stdlib.h>

Polynomial::Polynomial(int degree) : size(degree + 1), values(new double[degree + 1])
{
    if(values == NULL)
    {
        std::cout << "ERROR: Insufficient memory.\n";
        exit(1);
    }
//    testing size of the array
//    for(int i = 0; i < size; i++)
//    {
//        std::cout << *(values + i) << std::endl;
//    }
};

Polynomial::Polynomial(const Polynomial &other)
{
    values = new double[other.size];
    for(int i = 0; i < other.size; i++)
    {
        *(values + i) = *(other.values + i);
    }
    size = other.size;
};

Polynomial::~Polynomial()
{
    delete [] values;
    values = 0;
};

std::ostream& operator <<(std::ostream& out, const Polynomial& other)
{
    bool empty = true;
    for(int i = 0; i < other.size; i++)
    {
        if(*(other.values + i) != 0)
        {
            empty = false;
        }
        else
        {
            if(empty && i == (other.size - 1))
            {
                out << 0;
            }
        }
    }
    return out;
}

std::istream& operator >>(std::istream& in, const Polynomial& other)
{
    for(int i = 0; i < other.size; i++)
    {

    }
    return in;
}

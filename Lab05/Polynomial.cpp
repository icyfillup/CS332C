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
            if(*(other.values + i) > 0)
            {
                if(empty)
                    out << *(other.values + i);
                else
                    out << " + " <<*(other.values + i);
            }
            else
            {
                if(empty)
                    out << "-" << -(*(other.values + i));
                else
                    out << " - " << -(*(other.values + i));
            }

            if(i < other.size - 1)
                out << "x^" << other.size - i - 1;

            empty = false;
        }
        else
        {
            if(empty && i == (other.size - 1))
                out << 0;
        }
    }

//    test if array has any values
//    for(int i = 0; i < other.size; i++)
//    {
//        out << *(other.values + i) << " ";
//    }
    return out;
}

std::istream& operator >>(std::istream& in, const Polynomial& other)
{
    std::cout << "Enter " << other.size << " coefficient:\t";
    for(int i = 0; i < other.size; i++)
    {
        in >> *(other.values + i);
    }
    return in;
}

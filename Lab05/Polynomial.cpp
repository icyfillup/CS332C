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
//    double *end_ptr = values + size;
//    for(double *i = values; i != end_ptr; i++)
//    {
//        std::cout << *i << std::endl;
//    }
};
Polynomial::~Polynomial()
{
    delete [] values;
    values = 0;
};

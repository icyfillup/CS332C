#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H
#include <iostream>

class Polynomial
{
    public:
        Polynomial(int degree);
        Polynomial(const Polynomial &other);
        ~Polynomial();

    private:
        double *values;
        int size;
};

#endif

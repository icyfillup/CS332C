#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H
#include <iostream>

class Polynomial
{
    public:
        Polynomial(int degree);
        Polynomial(const Polynomial &other);
        ~Polynomial();

        friend std::ostream& operator <<(std::ostream& out, const Polynomial& other);
        friend std::istream& operator >>(std::istream& in, const Polynomial& other);

    private:
        double *values;
        int size;
};

#endif

#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H
#include <iostream>

class Polynomial
{
    public:
        Polynomial(int degree);
        Polynomial(const Polynomial &other);
        ~Polynomial();

        bool operator ==(const Polynomial& other) const;
        const Polynomial operator +(const Polynomial& other) const;
        const Polynomial operator -(const Polynomial& other) const;
        const Polynomial operator -() const;
        friend const Polynomial operator *(const Polynomial& other, const int scalar);
        friend const Polynomial operator *(const int scalar, const Polynomial& other);
        friend std::ostream& operator <<(std::ostream& out, const Polynomial& other);
        friend std::istream& operator >>(std::istream& in, const Polynomial& other);

    private:
        double *values;
        int size;
};

#endif

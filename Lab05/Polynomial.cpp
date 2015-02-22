#include "Polynomial.h"
#include <iostream>
#include <stdlib.h>

bool DEBUG = false;

Polynomial::Polynomial(int degree) : size(degree + 1), values(new double[degree + 1])
{
    if(values == NULL)
    {
        std::cout << "ERROR: Insufficient memory.\n";
        exit(1);
    }
    if(DEBUG && false)
    {
//        testing size of the array
        for(int i = 0; i < size; i++)
        {
            std::cout << *(values + i) << std::endl;
        }
    }
};

Polynomial::Polynomial(const Polynomial &other)
{
    if(DEBUG)
        std::cout << "Copy Constructor has been flaged" << std::endl;

    values = new double[other.size];
    for(int i = 0; i < other.size; i++)
    {
        *(values + i) = *(other.values + i);
    }
    size = other.size;
};

Polynomial::~Polynomial()
{
    if(DEBUG)
        std::cout << "Destructor has been flaged" << std::endl;

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
    if(DEBUG && false)
    {
//        test if array has any values
        for(int i = 0; i < other.size; i++)
        {
            out << *(other.values + i) << " ";
        }
    }
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

bool Polynomial::operator ==(const Polynomial& other) const
{
    if(other.size != size)
        return false;

    for(int i = 0; i < size; i++)
    {
        if(*(values + i) != *(other.values + i))
        {
            return false;
        }
    }
    return true;
};

const Polynomial Polynomial::operator +(const Polynomial& other) const
{
    int newSize = (size <= other.size) ? other.size : size;
    int sum = 0;
    int offset = 0;
    Polynomial newPoly(newSize - 1);

    if(size <= other.size)
    {
        offset = other.size - size;

        for(int i = 0; i < newPoly.size; i++)
        {
            sum = *(other.values + i);
             if(offset <= i)
                sum += *(values + i - offset);
            *(newPoly.values + i) = sum;
        }
    }
    else
    {
        offset = size - other.size;

        for(int i = 0; i < newPoly.size; i++)
        {
            sum = *(values + i);
            if(offset <= i)
                sum += *(other.values + i - offset);
            *(newPoly.values + i) = sum;
        }
    }


    if(DEBUG && false)
        std::cout << "newSize: " << newSize << std::endl;

    return newPoly;
};

const Polynomial Polynomial::operator -(const Polynomial& other) const
{
    int newSize = (size <= other.size) ? other.size : size;
    int diff = 0;
    int offset = 0;
    Polynomial newPoly(newSize - 1);

    if(size <= other.size)
    {
        offset = other.size - size;

        for(int i = 0; i < newPoly.size; i++)
        {
             if(offset <= i)
                diff = *(values + i - offset);
            else
                diff = 0;

            diff -= *(other.values + i);
            *(newPoly.values + i) = diff;
        }
    }
    else
    {
        offset = size - other.size;

        for(int i = 0; i < newPoly.size; i++)
        {
            diff = *(values + i);
            if(offset <= i)
                diff -= *(other.values + i - offset);
            *(newPoly.values + i) = diff;
        }
    }


    if(DEBUG && false)
        std::cout << "newSize: " << newSize << std::endl;

    return newPoly;
}

const Polynomial Polynomial::operator -() const
{
    Polynomial newPoly(size - 1);
    for(int i = 0; i < size; i++)
    {
        *(newPoly.values + i) = -(*(values + i));
    }
    return newPoly;
}

const Polynomial operator *(const Polynomial& other, const int scalar)
{
    Polynomial newPoly(other.size - 1);

    for(int i = 0; i < newPoly.size; i++)
    {
        *(newPoly.values + i) = scalar * (*(other.values + i));
    }

    if(DEBUG && false)
        std::cout << "scalar: " << scalar << std::endl;

    return newPoly;
}

const Polynomial operator *(const int scalar, const Polynomial& other)
{
    return other * scalar;
}

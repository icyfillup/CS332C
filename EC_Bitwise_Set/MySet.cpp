#include "MySet.h"
#include <iostream>
#include <vector>

MySet::MySet(std::vector<int> other) : mySet(0)
{
    unsigned long long mask = 1;

    for(unsigned int i = 0; i < other.size(); i++)
    {
        mask = 1;
        mask <<= other[i];
        mySet |= mask;
    }
};

MySet::MySet(unsigned long long other) : mySet(other){};

bool MySet::add(int x)
{
    unsigned long long mask = 1;
    mask <<= x;

    mySet |= mask;
    if((mySet & mask) == 0)
        return true;
    else
        return false;
};

bool MySet::remove(int x)
{
    unsigned long long mask = 1;
    mask <<= x;

    if((mySet & mask) == 0)
        return false;
    else
    {
        mask = ~mask;
        mySet &= mask;
        return true;
    }
};

const MySet MySet::operator +(const MySet& other)const
{
    return MySet(other.mySet | mySet);
};

const MySet MySet::operator &(const MySet& other)const
{
    return MySet(other.mySet & mySet);
};

const MySet MySet::operator -(const MySet& other) const
{
    return MySet(mySet & ~(other.mySet));
};

bool MySet::operator ==(const MySet& other) const
{
    return (mySet & ~(other.mySet)) == 0;
};

bool MySet::operator >(const MySet& other) const
{
    return ((other.mySet & mySet) == other.mySet);
}

bool MySet::operator <(const MySet& other) const
{
    return ((mySet & other.mySet) == mySet);
}

int MySet::size() const
{
    int bitNum = sizeof(mySet) * 8;
    unsigned long long mask = 1;
    int count = 0;
    for(int i = 0; i < bitNum; i++)
    {
        if((mask & mySet) != 0)
            count++;
        mask <<= 1;
    }
    return count;
};

bool MySet::isEmpty() const
{
    return (mySet == 0);
};

std::ostream& operator << (std::ostream& out, const MySet& s)
{
    int bitNum = sizeof(s.mySet) * 8;
    unsigned long long mask = 1;

    for(int i = 0; i < bitNum; i++)
    {
        if(mask & s.mySet)
        {
            out << i << " ";
        }
        mask <<= 1;
    }
    return out;
};

#ifndef MYSET_H
#define MYSET_H
#include <iostream>
#include <vector>

class MySet
{
    public:
        MySet(std::vector<int> other);
        MySet(unsigned long long other);
        bool add(int x);
        bool remove(int x);
        const MySet operator +(const MySet& other) const;
        const MySet operator &(const MySet& other) const;
        const MySet operator -(const MySet& other) const;
        bool operator ==(const MySet& other) const;
        bool operator >(const MySet& other) const;
        bool operator <(const MySet& other) const;
        int size() const;
        bool isEmpty() const;
        friend std::ostream& operator <<(std::ostream& out, const MySet& s);

    private:
        unsigned long long mySet;

};

#endif

#ifndef MYSET_H
#define MYSET_H

#include <iostream>
#include <vector>


class MySet
{
    public:
        MySet();
        MySet(int userSize);
        MySet(std::vector<int> userList);

        bool add(int x);
        bool remove(int x);
        const MySet operator +(const MySet &x) const;
        const MySet operator -(const MySet &x) const;
        const MySet operator &(const MySet &x) const;
        bool operator ==(const MySet &x) const;
        bool operator >(const MySet &x) const;
        bool operator <(const MySet &x) const;
        bool isEmpty() const;
        friend std::ostream& operator << (std::ostream& outputStream, const MySet& s);

        int size() const{return set.size();}
        std::vector<int> getSet() const{return set;}
        void sort();
    private:
        std::vector<int> set;

        void duplicateChecker();
};

#endif


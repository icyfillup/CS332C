#include "MySet.h"
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>

MySet::MySet()
{
    srand(time(NULL));
    for(int i = 0; i < 10; i++)
    {
        set.push_back(rand() % 101);
    }
    duplicateChecker();
};

MySet::MySet(int userSize)
{
    srand(time(NULL));
    for(int i = 0; i < userSize; i++)
    {
        set.push_back(rand() % 101);
    }
    if(set.size() > 0)
        {duplicateChecker();}
};

MySet::MySet(std::vector<int> userList) : set(userList)
{

    if(set.size() > 0)
    {
        sort();
        for(int i = 0; i < set.size() - 1; i++)
        {
            if(set[i] == set[i + 1])
            {
                set.erase(set.begin() + i + 1);
                i--;
            }
        }
    }
};

bool MySet::add(int x)
{
    for(unsigned int i = 0; i < set.size(); i++)
    {
        if(set[i] == x)
        {
            return false;
        }
    }
    set.push_back(x);
    return true;
};

bool MySet::remove(int x)
{
    for(unsigned int i = 0; i < set.size(); i++)
    {
        if(set[i] == x)
        {
            set.erase(set.begin() + i);
            return true;
        }
    }
    return false;
};

const MySet MySet::operator +(const MySet &x) const
{
    std::vector<int> newSet;

    for(int i = 0; i < set.size(); i++)
    {
       newSet.push_back(set[i]);
    }
    for(int j = 0; j < x.size(); j++)
    {
       newSet.push_back(x.getSet()[j]);
    }

    return MySet(newSet);
}

const MySet MySet::operator -(const MySet &x) const
{
    std::vector<int> newSet;

    bool exist = false;

    for(int i = 0; i < set.size(); i++)
    {
        exist = false;
        for(int j = 0; j < x.size(); j++)
        {
            if(set[i] == x.getSet()[j])
            {
                std::cout << "Entered == : " << set[i] << std::endl;
                exist = true;
                break;
            }
        }

        if(!exist)
        {
            std::cout << "Entered exist : " << set[i] << std::endl;
            newSet.push_back(set[i]);
        }
    }

    return MySet(newSet);
}

const MySet MySet::operator &(const MySet &x) const
{
    std::vector<int> newSet;

    bool exist = false;

    for(int i = 0; i < set.size(); i++)
    {
        for(int j = 0; j < x.size(); j++)
        {
            if(set[i] == x.getSet()[j])
            {
                newSet.push_back(set[i]);
            }
        }
    }

    return MySet(newSet);
}

bool MySet::operator ==(const MySet &x) const
{
    if(set.size() != x.size())
    {
        return false;
    }

    bool exist = false;

    for(unsigned int i = 0; i < set.size(); i++)
    {
        exist = false;
        for(int j = 0; j < x.size(); j++)
        {
            if(set[i] == x.getSet()[j])
            {
                exist = true;
                break;
            }
        }

        if(!exist)
        {
            return false;
        }
    }
    return true;
}

bool MySet::operator >(const MySet &x) const
{
    if(set.size() < x.size())
    {
        return false;
    }

    bool exist = false;

    for(int j = 0; j < x.size(); j++)
    {
        exist = false;
        for(unsigned int i = 0; i < set.size(); i++)
        {
            if(set[i] == x.getSet()[j])
            {
                exist = true;
                break;
            }
        }
        if(!exist)
        {
            return false;
        }
    }
    return true;
}

bool MySet::operator <(const MySet &x) const
{
    if(set.size() > x.size())
    {
        return false;
    }

    bool exist = false;

    for(unsigned int i = 0; i < set.size(); i++)
    {
        exist = false;
        for(int j = 0; j < x.size(); j++)
        {
            if(set[i] == x.getSet()[j])
            {
                exist = true;
                break;
            }
        }

        if(!exist)
        {
            return false;
        }
    }
    return true;
}

bool MySet::isEmpty() const
{
    return set.size() == 0;
};

std::ostream& operator <<(std::ostream& outputStream, const MySet& s)
{
    for(unsigned int i = 0; i < s.set.size(); i++)
    {
        outputStream << s.set[i] << " ";
    }
    return outputStream;
};

void MySet::duplicateChecker()
{
    bool dupl = false;
    do
    {
        dupl = false;
        sort();
        for(unsigned int i = 0; i < set.size() - 1; i++)
        {
            if(set[i] == set[i + 1])
            {
                set[i + 1] = rand() % 101;
                dupl = true;
            }
        }
    }
    while(dupl);
}

void MySet::sort()
{
//not sure why but in empty set, this is failed. when i = 0 and set.size() = 0, (i < set.size() - 1) is read as true
    bool swap = false;
    do
    {
        swap = false;
        for(unsigned  int i = 0; i < set.size() - 1; i++)
        {
            if(set[i] > set[i + 1])
            {
                int temp = set[i];
                set[i] = set[i + 1];
                set[i + 1] = temp;
                swap = true;
            }
        }
    }
    while(swap);
}

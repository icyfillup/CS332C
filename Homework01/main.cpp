#include "MySet.h"
#include <iostream>
#include <stdlib.h>
#include <vector>

bool running;
const int LIST_SIZE = 2;
const int MENU_SIZE = 16;
bool DEBUG = false;

enum MySet_Init
{
    USER_INPUT,
    GIVEN_SIZE,
    FIXED_SIZE
};

void debugFunction();
void printMenu();
void MenuManager(short userInput, bool initSet[], MySet listOfSet[]);

void initMySet(MySet& set, MySet_Init state);
void addValue(MySet listOfSet[]);
void removeValue(MySet listOfSet[]);
void displaySet(MySet listOfSet[]);

int main()
{
//    debugFunction();
    running = true;
    bool initSet[LIST_SIZE] = {false, false};
    MySet listOfSet[LIST_SIZE] = {MySet(0), MySet(0)};
    short userInput = 0;

    while(running)
    {
        printMenu();
        std::cout << "===> ";
        std::cin >> userInput;
        std::cout << std::endl;

        if(userInput > 0 && userInput <= MENU_SIZE)
        {
            if(userInput > 6 && userInput < MENU_SIZE)
                if(initSet[0] && initSet[1])
                    MenuManager(userInput, initSet, listOfSet);
                else
                    std::cout << "Set 1 and/or Set 2 have not been initialized." << std::endl;
            else
                MenuManager(userInput, initSet, listOfSet);
        }


        if(DEBUG)
        {

            std::cout << "is Set 1 empty:\t" << listOfSet[0].isEmpty() << std::endl;
            std::cout << "Set 1:\t" << listOfSet[0] << std::endl;
            std::cout << "Set 2:\t" << listOfSet[1] << std::endl;
            std::cout << "listOfSet[0]: ";
            for(int j = 0; j < listOfSet[0].size(); j++)
            {
                std::cout << listOfSet[0].getSet()[j] << " ";
            }
        }
        std::cout << std::endl;
    }


    return 0;
}

void MenuManager(short userInput, bool initSet[], MySet listOfSet[])
{
    switch(userInput)
    {
        case 1:
            initSet[0] = true;
            initMySet(listOfSet[0], FIXED_SIZE);
            break;
        case 2:
            initSet[0] = true;
            initMySet(listOfSet[0], GIVEN_SIZE);
            break;
        case 3:
            initSet[0] = true;
            initMySet(listOfSet[0], USER_INPUT);
            break;
        case 4:
            initSet[1] = true;
            initMySet(listOfSet[1], FIXED_SIZE);
            break;
        case 5:
            initSet[1] = true;
            initMySet(listOfSet[1], GIVEN_SIZE);
            break;
        case 6:
            initSet[1] = true;
            initMySet(listOfSet[1], USER_INPUT);
            break;
        case 7:
            addValue(listOfSet);
            break;
        case 8:
            removeValue(listOfSet);
            break;
        case 9:
            std::cout << "Union Set:\t" << (listOfSet[0] + listOfSet[1]) << std::endl;
            break;
        case 10:
            std::cout << "Relative Compliment Set:\t" << (listOfSet[0] - listOfSet[1]) << std::endl;
            break;
        case 11:
            std::cout << "Intersection Set:\t" << (listOfSet[0] & listOfSet[1]) << std::endl;
            break;
        case 12:
            std::cout << ((listOfSet[0] == listOfSet[1]) ? "Both Sets are the same." : "Both Sets are different") << std::endl;
            break;
        case 13:
            std::cout << ((listOfSet[0] > listOfSet[1]) ? "Set 1 is a superset to Set 2" : "Set 1 is not a superset to Set 2") << std::endl;
            break;
        case 14:
            std::cout << ((listOfSet[0] < listOfSet[1]) ? "Set 2 is a superset to Set 1" : "Set 2 is not a superset to Set 1") << std::endl;
            break;
        case 15:
            displaySet(listOfSet);
            break;
        case 16:
            running = false;
            break;
    }
}

void initMySet(MySet& set, MySet_Init state)
{
    if(state == FIXED_SIZE)
        {set = MySet();}
    else if(state == GIVEN_SIZE)
    {
        int size = 0;
        do
        {
            std::cout << "Size of your set: ";
            std::cin >> size;
            if(size < 0)
            {
                std::cout << "Enter Non-Negative integer." << std::endl;
            }
        }
        while(size < 0);
        set = MySet(size);
    }
    else if(state == USER_INPUT)
    {
        std::vector<int> userList;
        int userNum = 0;
        do
        {
            std::cout << "Insert Num between 0 - 100 (enter out-of-bound number to esc): ";
            std::cin >> userNum;
            if(userNum >= 0 && userNum <= 100)
            {
                userList.push_back(userNum);
            }
        }
        while(userNum >= 0 && userNum <= 100);
        MySet s(userList);
        set = s;
    }
    else
    {
        std::cout << "Something went terribly wrong!!! Exit program.";
        exit(1);
    }
}

void addValue(MySet listOfSet[])
{
    int value = 0;
    int index = -1;

    do
    {
        std::cout << "Enter a value to add [0 ~ 100]: ";
        std::cin >> value;
    }
    while(!(value > -1 && value < 101));

    do
    {
        std::cout << "Which set do you want to add to?" << std::endl;
        std::cout << "0.\tSet 1" << std::endl;
        std::cout << "1.\tSet 2" << std::endl;
        std::cout << "====> ";
        std::cin >> index;
    }
    while(!(index > -1 && index < 2));

    if(listOfSet[index].add(value))
    {
        std::cout << value << " has been added to the set " << (index + 1) << std::endl;
    }
    else
    {
        std::cout << "There is alreay a " << value << " in the set " << (index + 1) << std::endl;
    }
    std::cout << std::endl;
}

void removeValue(MySet listOfSet[])
{
    int value = 0;
    int index = -1;

    do
    {
        std::cout << "Enter a value to remove [0 ~ 100]: ";
        std::cin >> value;
    }
    while(!(value > -1 && value < 101));

    do
    {
        std::cout << "Which set do you want to remove from?" << std::endl;
        std::cout << "0.\tSet 1" << std::endl;
        std::cout << "1.\tSet 2" << std::endl;
        std::cout << "====> ";
        std::cin >> index;
    }
    while(!(index > -1 && index < 2));

    if(listOfSet[index].remove(value))
    {
        std::cout << value << " has been remove to the set " << (index + 1) << std::endl;
    }
    else
    {
        std::cout << "There is no " << value << " in the set " << (index + 1) << std::endl;
    }
    std::cout << std::endl;
}

void displaySet(MySet listOfSet[])
{
    std::cout << "Set 1:\t" << listOfSet[0] << std::endl;
    std::cout << "Set 2:\t" << listOfSet[1] << std::endl;
}

void printMenu()
{
    std::cout << "************MySet Main Menu************" << std::endl;
    std::cout << "1. Generate a Default Set 1" << std::endl;
    std::cout << "2. Generate Set 1 Given the Size" << std::endl;
    std::cout << "3. Generate Set 1 With User Input" << std::endl;
    std::cout << "4. Generate a Default Set 2" << std::endl;
    std::cout << "5. Generate Set 2 Given the Size" << std::endl;
    std::cout << "6. Generate Set 2 With User Input" << std::endl;
    std::cout << "7. Add a Value" << std::endl;
    std::cout << "8. Remove a Value" << std::endl;
    std::cout << "9. Union" << std::endl;
    std::cout << "10. Relative Compliment" << std::endl;
    std::cout << "11. Intersection" << std::endl;
    std::cout << "12. Equality" << std::endl;
    std::cout << "13. Superset" << std::endl;
    std::cout << "14. Subset" << std::endl;
    std::cout << "15. Display Sets" << std::endl;
    std::cout << "16. Exit Program" << std::endl;
    std::cout << "***************************************" << std::endl;
}

void debugFunction()
{
    std::vector<int> lists;
    lists.push_back(1);
    lists.push_back(1);
    lists.push_back(9);
    lists.push_back(1);
    lists.push_back(3);
    lists.push_back(1);
    lists.push_back(6);
    lists.push_back(5);

    MySet s(lists);
    std::cout << s << std::endl;
}

#include "Weight.h"
#include <fstream>
#include <iostream>

const bool DEBUG = false;

void debugFunction();
void add(const Weight& w1, const Weight& w2, std::ofstream& sums);
void subtract(const Weight& w1, const Weight& w2, std::ofstream& differences);
void equal(const Weight& w1, const Weight& w2, std::ofstream& equalities);

int main()
{
    if(DEBUG)
    {
        debugFunction();
    }
    std::ifstream w1_Input;
    std::ifstream w2_Input;
    w1_Input.open("weights1.txt");
    w2_Input.open("weights2.txt");

    std::ofstream sums;
    std::ofstream differences;
    std::ofstream equalities;
    sums.open("sums.txt");
    differences.open("differences.txt");
    equalities.open("equalities.txt");

    Weight w1;
    Weight w2;

    while(w1_Input >> w1 && w2_Input >> w2)
    {
        add(w1, w2, sums);
        subtract(w1, w2, differences);
        equal(w1, w2, equalities);
        std::cout << std::endl;
    }
    std::cout << "sums.txt, differences.txt, equalities.txt have been created to store the values that have been shown.\n" << std::endl;
    return 0;
}

void add(const Weight& w1, const Weight& w2, std::ofstream& sums)
{
    sums << (w1 + w2) << std::endl;
    std::cout << "Sums: " << (w1 + w2) << std::endl;
}

void subtract(const Weight& w1, const Weight& w2, std::ofstream& differences)
{
    differences << (w1 - w2) << std::endl;
    std::cout << "Differences: " << (w1 - w2) << std::endl;
}

void equal(const Weight& w1, const Weight& w2, std::ofstream& equalities)
{
    equalities << ((w1 == w2) ? "True" : "False") << std::endl;
    std::cout << "Equalities: " << ((w1 == w2) ? "True" : "False")  << std::endl;
}

void debugFunction()
{
    std::ifstream input;
    input.open("weights1.txt");

    std::ofstream output;
    output.open("testOutput.txt");

    Weight w1;
    Weight w2;

    int counter = 0;
    while(input >> w1)
    {
        std::cout << w1 << std::endl;
        if(counter > 100)
        {
            std::cout << "looping too many times" << std::endl;
            break;
        }
        counter++;
    }
}


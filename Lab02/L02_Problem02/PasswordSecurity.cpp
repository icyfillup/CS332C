#include <iostream>
#include <ctime>
#include <cstdlib>

const short PIN_SIZE = 5;
const short KEY_PAD_SIZE = 10;
const int ACC_PIN[PIN_SIZE] = {3,6,2,1,1};
const int KEY_PAD[KEY_PAD_SIZE] = {0,1,2,3,4,5,6,7,8,9};

bool authentication(const int userPIN[], const int numPad[]);
void ranNumPadGen(int numPad[], short size);
int inputPIN();
void sortPin(int userPIN[], int userInput);
void printArray(const int ogArr[], short size);

int main()
{
    srand(time(NULL));
    int numPad[KEY_PAD_SIZE];
    ranNumPadGen(numPad, KEY_PAD_SIZE);

    std::cout << "PIN:\t";
    printArray(KEY_PAD, KEY_PAD_SIZE);

    std::cout << "NUM:\t";
    printArray(numPad, KEY_PAD_SIZE);

    int userPIN[PIN_SIZE];
    int userInput = inputPIN();
    sortPin(userPIN, userInput);

    bool hasAccess = authentication(userPIN, numPad);
    std::string security = (hasAccess == 0) ? "Dental" : "Valid";
    std::cout << "Access " << security << std::endl;

    return 0;
}

bool authentication(const int userPIN[], const int numPad[])
{
    bool isCorrect = true;
    int pinChecker[PIN_SIZE] = {numPad[ACC_PIN[0]], numPad[ACC_PIN[1]],
                                    numPad[ACC_PIN[2]], numPad[ACC_PIN[3]], numPad[ACC_PIN[4]]};

    for(unsigned short i = 0; i < PIN_SIZE; i++)
    {
        if(pinChecker[i] != userPIN[i])
        {
            isCorrect = false;
            break;
        }
    }
    return isCorrect;
}

void ranNumPadGen(int numPad[], short size)
{
    for(unsigned short i = 0; i < size; i++)
    {
        numPad[i] = rand() % 10;
    }
}

int inputPIN()
{
    int inputPIN = 0;
    do
    {
        std::cout << "Enter your PIN(5 Digits): ";
        std::cin >> inputPIN;
    }
    while(inputPIN < 0 || inputPIN > 100000);
    std::cout << std::endl;

    return inputPIN;
}

void sortPin(int userPIN[], int userInput)
{
    int distribtion = 10000;
    for(unsigned short i = 0; i < PIN_SIZE; i++)
    {
        userPIN[i] = userInput / distribtion;
        userInput %= distribtion;
        distribtion /= 10;
    }
}

void printArray(const int ogArr[], short size)
{
    for(unsigned short i = 0; i < size; i++)
    {
        std::cout << ogArr[i] << " ";
    }
    std::cout << std::endl;
}

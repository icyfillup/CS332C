#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>

const short SIZE = 5;

void function01(const int ogArr[]);
void function02(const int ogArr[]);
void function03(const int ogArr[]);
void function04(const int ogArr[]);
void function05(const int ogArr[]);
void function06(const int ogArr[]);
void function07(const int ogArr[]);
void function08(const int ogArr[]);
void function09(const int ogArr[]);
void printArray(const int arr[]);
void ranNumArr(int arr[]);
void copyArr(const int ogArr[], int nArr[]);
void sort(int arr[]);

int main()
{
    srand(time(NULL));
    int arr[SIZE];
    ranNumArr(arr);

    std::cout << "Original Array:\t";
    printArray(arr);
    function01(arr);
    function02(arr);
    function03(arr);
    function04(arr);
    function05(arr);
    function06(arr);
    function07(arr);
    function08(arr);
    function09(arr);


    return 0;
}

void function01(const int ogArr[])
{
    int arr[SIZE];
    copyArr(ogArr, arr);

    int temp = arr[0];
    arr[0] = arr[SIZE - 1];
    arr[SIZE - 1] = temp;
    std::cout << "Function 01:\t";
    printArray(arr);
}

void function02(const int ogArr[])
{
    int arr[SIZE];
    copyArr(ogArr, arr);

    int temp = arr[SIZE - 1];
    for(unsigned int i = SIZE - 1; i > 0; i--)
    {
        arr[i] = arr[i - 1];
    }
    arr[0] = temp;
    std::cout << "Function 02:\t";
    printArray(arr);
}

void function03(const int ogArr[])
{
    int arr[SIZE];
    copyArr(ogArr, arr);

    for(unsigned int i = 0; i < SIZE; i++)
    {
        if((arr[i] % 2) == 0)
            {arr[i] = 0;}
    }
    std::cout << "Function 03:\t";
    printArray(arr);
}

void function04(const int ogArr[])
{
    int arr[SIZE];
    copyArr(ogArr, arr);

    for(unsigned int i = 1; i < SIZE - 1; i++)
    {
        arr[i] = (ogArr[i - 1] <= ogArr[i + 1]) ? ogArr[i + 1]: ogArr[i - 1];
    }
    std::cout << "Function 04:\t";
    printArray(arr);
}

void function05(const int ogArr[])
{
    int arr[SIZE];
    short counter = 0;

    for(unsigned int i = 0; i < SIZE; i++)
    {
        if(ogArr[i] % 2 == 0)
        {
            arr[counter] = ogArr[i];
            counter++;
        }
    }
    for(unsigned int i = 0; i < SIZE; i++)
    {
        if(ogArr[i] % 2 == 1)
        {
            arr[counter] = ogArr[i];
            counter++;
        }
    }
    std::cout << "Function 05:\t";
    printArray(arr);
}

void function06(const int ogArr[])
{

    int arr[SIZE];
    copyArr(ogArr, arr);
    sort(arr);
    std::cout << "Function 06:\t";
    for(unsigned short i = 0; i < SIZE - 1; i++)
    {
        if(arr[i] < arr[i + 1])
        {
            std::cout << arr[i + 1] << std::endl;
            break;
        }
    }
}

void function07(const int ogArr[])
{
    int arr[SIZE];
    copyArr(ogArr, arr);
    sort(arr);
    std::cout << "Function 07:\t";
    printArray(arr);
}

void function08(const int ogArr[])
{
    bool adj = false;
    for(unsigned short i = 0; i < SIZE - 1; i++)
    {
        if(ogArr[i] == ogArr[i + 1])
        {
            adj = true;
            break;
        }
    }
    std::string isAdj = (adj == 0) ? "No adjacent duplicate element" : "Adjacent duplicate element";
    std::cout << "Function 08:\t" << isAdj << std::endl;
}

void function09(const int ogArr[])
{
    int arr[SIZE];
    copyArr(ogArr, arr);
    sort(arr);
    bool adj = false;
    for(unsigned short i = 0; i < SIZE - 1; i++)
    {
        if(arr[i] == arr[i + 1])
        {
            adj = true;
            break;
        }
    }
    std::string isAdj = (adj == 0) ? "No duplicate element" : "Duplicate element";
    std::cout << "Function 09:\t" << isAdj << std::endl;
}

void printArray(const int arr[])
{
    for(unsigned int i = 0; i < SIZE; i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << " " << std::endl;
}

void ranNumArr(int arr[])
{
    for(unsigned int i = 0; i < SIZE; i++)
    {
        int random = (rand() % 20) + 1;
        arr[i] = random;
    }
}

void copyArr(const int ogArr[], int nArr[])
{
    for(unsigned int i = 0; i < SIZE; i++)
    {
        nArr[i] = ogArr[i];
    }
}

void sort(int arr[])
{
    bool swap = false;
    do
    {
        swap = false;
        for(unsigned short i = 0; i < SIZE - 1; i++)
        {
            if(arr[i] > arr[i + 1])
            {
                int temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
                swap = true;
            }
        }
    }
    while(swap);
}

#include <iostream>
#include <ctime>
#include <cstdlib>

struct Point3D
{
    int x;
    int y;
    int z;
};

const short SIZE = 7;
Point3D ogArray[SIZE];

void translate();
void reflect();
void add3D_Points(Point3D arr[], short size);
void setPoint3D(Point3D& p, int x, int y, int z);
void readPoint3D(Point3D& p);
void setRan3D_Point(Point3D& p);
void printArray(const Point3D arr[], short size);
void copyArray(const Point3D ogArray[], Point3D newArray[], short size);

int main()
{
    srand(time(NULL));

    add3D_Points(ogArray, SIZE);

    bool running = true;
    int choose;
    std::cout << "3D Points\n" << std::endl;
    while(running)
    {
        std::cout << "1. Translate 3D Points" << std::endl;
        std::cout << "2. Reflect 3D Points" << std::endl;
        std::cout << "3. Display All 3D Points" << std::endl;
        std::cout << "0. Exit Program" << std::endl;
        do
        {
            std::cout << "===> ";
            std::cin >> choose;
        }
        while(choose < 0 || choose > 3);
        std::cout << std::endl;

        switch(choose)
        {
            case 1:
                translate();
                break;
            case 2:
                reflect();
                break;
            case 3:
                printArray(ogArray, SIZE);
                break;
            case 0:
                running = false;
                break;
        }
    }
    return 0;
}

void translate()
{
    Point3D arr[SIZE];
    copyArray(ogArray, arr, SIZE);

    int trans = 1;
    std::cout << "translation value: ";
    std::cin >> trans;

    for(unsigned short i = 0; i < SIZE; i++)
    {
        int x = arr[i].x + (trans * arr[i].x);
        int y = arr[i].y + (trans * arr[i].y);
        int z = arr[i].z + (trans * arr[i].z);
        setPoint3D(arr[i], x, y, z);
    }

    printArray(arr, SIZE);
}

void reflect()
{
    Point3D arr[SIZE];
    copyArray(ogArray, arr, SIZE);

    int choose;
    std::cout << "Which plane do you want to reflect?" << std::endl;
    std::cout << "1. xy-plane" << std::endl;
    std::cout << "2. yz-plane" << std::endl;
    std::cout << "3. xz-plane" << std::endl;
    do
    {
        std::cout << "===> ";
        std::cin >> choose;
    }
    while(choose < 1 || choose > 3);

    for(unsigned short i = 0; i < SIZE; i++)
    {
        switch(choose)
        {
            case 1:
                setPoint3D(arr[i], arr[i].x, arr[i].y, -arr[i].z);
                break;
            case 2:
                setPoint3D(arr[i], -arr[i].x, arr[i].y, arr[i].z);
                break;
            case 3:
                setPoint3D(arr[i], arr[i].x, -arr[i].y, arr[i].z);
                break;
        }
    }
    printArray(arr, SIZE);
}

void add3D_Points(Point3D arr[], short size)
{
    Point3D p;
    for(unsigned short i = 0; i < size; i++)
    {
        setRan3D_Point(p);
        arr[i] = p;
    }
}

void setPoint3D(Point3D& p, int x, int y, int z)
{
    p.x = x;
    p.y = y;
    p.z = z;
}

void readPoint3D(Point3D p)
{
    std::cout << "x: " <<  p.x << "\t";
    std::cout << "y: " <<  p.y << "\t";
    std::cout << "z: " <<  p.z << std::endl;
}

void setRan3D_Point(Point3D& p)
{
    int ranX = (rand() % 21) - 10;
    int ranY = (rand() % 21) - 10;
    int ranZ = (rand() % 21) - 10;

    setPoint3D(p, ranX, ranY, ranZ);
}

void printArray(const Point3D arr[], short size)
{
    for(unsigned short i = 0; i < size; i++)
    {
        std::cout << i << ":\t";
        readPoint3D(arr[i]);
    }
    std::cout << std::endl;
}

void copyArray(const Point3D ogArray[], Point3D newArray[], short size)
{
    for(unsigned short i = 0; i < size; i++)
    {
        newArray[i] = ogArray[i];
    }
}

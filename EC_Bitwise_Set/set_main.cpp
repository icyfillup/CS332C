#include "MySet.h"
#include <iostream>
#include <vector>

int main()
{

    std::vector<int> vec1 = {7, 13, 25, 27, 42, 56, 63};
    std::vector<int> vec2 = {7, 34, 42, 63};
    std::vector<int> vec3 = {};

    MySet s1(vec1);
    MySet s2(vec2);
    MySet s3(vec3);

    std::cout << "S1:\t\t" << s1 << std::endl;
    std::cout << "S2:\t\t" << s2 << std::endl;
    std::cout << "S3:\t\t" << s3 << std::endl << std::endl;

    s1.add(8);
    s1.add(8);
    s2.add(8);
    s2.add(8);

    std::cout << "S1 add:\t\t" << s1 << std::endl;
    std::cout << "S2 add:\t\t" << s2 << std::endl << std::endl;

    s1.remove(8);
    s2.remove(8);
    s1.remove(8);
    s2.remove(8);

    std::cout << "S1 remove:\t" << s1 << std::endl;
    std::cout << "S2 remove:\t" << s2 << std::endl << std::endl;

    std::cout << "S1 + S2:\t" << (s1 + s2) << std::endl;
    std::cout << "S1 & S2:\t" << (s1 & s2) << std::endl;
    std::cout << "S1 - S2:\t" << (s1 - s2) << std::endl;
    std::cout << "S2 - S1:\t" << (s2 - s1) << std::endl << std::endl;

    std::cout << "S1 == S1:\t" << ((s1 == s1) ? "true" : "false") << std::endl;
    std::cout << "S1 == S2:\t" << ((s1 == s2) ? "true" : "false") << std::endl << std::endl;

    std::cout << "S1 > S2:\t" << ((s1 > s2) ? "true" : "false") << std::endl;
    std::cout << "S1 < S2:\t" << ((s1 < s2) ? "true" : "false") << std::endl;
    std::cout << "S2 > S1:\t" << ((s2 > s1) ? "true" : "false") << std::endl;
    std::cout << "S2 < S1:\t" << ((s2 < s1) ? "true" : "false") << std::endl << std::endl ;

    std::cout << "S1 Size:\t" << s1.size() << std::endl;
    std::cout << "S2 Size:\t" << s2.size() << std::endl << std::endl;

    std::cout << "S1 Empty:\t" << (s1.isEmpty() ? "true" : "false") << std::endl;
    std::cout << "S2 Empty:\t" << (s2.isEmpty() ? "true" : "false") << std::endl;
    std::cout << "S2 Empty:\t" << (s3.isEmpty() ? "true" : "false") << std::endl << std::endl;

    return 0;
}

#include "Weight.h"
#include <iostream>

const int POUND_TO_OUNCE = 16;

Weight::Weight(int pounds, int ounces) : pounds(pounds), ounces(ounces)
    {

    }

Weight::Weight() : pounds(0), ounces(0)
    {

    }

const void Weight::output_d()
{
    std::cout << "Weight in Decimal: " << (pounds + (ounces / 16.0)) << " pounds" << std::endl;
}

const Weight operator +(const Weight& w1, const Weight& w2)
{
    int thisOunce = w1.ounces + (w1.pounds * POUND_TO_OUNCE);
    int otherOunce = w2.ounces + (w2.pounds * POUND_TO_OUNCE);

    int totalOunce = thisOunce + otherOunce;

    int convertedPounds = totalOunce / POUND_TO_OUNCE;
    int convertedOunces = totalOunce % POUND_TO_OUNCE;

    return Weight(convertedPounds, convertedOunces);
}

const Weight operator -(const Weight& w1, const Weight& w2)
{
    int thisOunce = w1.ounces + (w1.pounds * POUND_TO_OUNCE);
    int otherOunce = w2.ounces + (w2.pounds  * POUND_TO_OUNCE);

    int totalOunce = thisOunce - otherOunce;

    int convertedPounds = totalOunce / POUND_TO_OUNCE;
    int convertedOunces = totalOunce % POUND_TO_OUNCE;

    return Weight(convertedPounds, convertedOunces);
}

bool operator ==(const Weight& w1, const Weight& w2)
{
    int thisOunce = w1.ounces + (w1.pounds * POUND_TO_OUNCE);
    int otherOunce = w2.ounces + (w2.pounds * POUND_TO_OUNCE);

    return thisOunce == otherOunce;
}

std::ostream& operator <<(std::ostream& outputStream, const Weight& w2)
{
    outputStream << w2.pounds << " lbs " << w2.ounces << " oz";
    return outputStream;
}

std::istream& operator >>(std::istream& inputStream, Weight& w2)
{
    int pounds = 0, ounces = 0;
    inputStream >> pounds >> ounces;
    w2.setPounds(pounds);
    w2.setOunces(ounces);

    return inputStream;
}

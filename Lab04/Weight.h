#ifndef WEIGHT_H
#define WEIGHT_H

#include <iostream>

class Weight
{
    public:
        Weight(int pounds, int ounces); // Create a second constructor with input parameters for the amount of pounds and ounces.
        Weight(); //Create a default constructor that sets the weight amount to 0 pounds and 0 ounces.

        // getters
        int getPounds() const {return pounds;}
        int getOunces() const {return ounces;}
        //setters
        void setPounds(int poundValue){pounds = poundValue;}
        void setOunces(int ounceValue){ounces = ounceValue;}

        const void output_d(); //Add a function that returns the weight amount as a double in pounds.

        friend const Weight operator +(const Weight& w1, const Weight& w2); //Overload the operator + for Weight objects.
        friend const Weight operator -(const Weight& w1, const Weight& w2); //Overload the operator - for Weight objects.
        friend bool operator ==(const Weight& w1, const Weight& w2); //Overload the operator == for Weight objects.
        friend std::ostream& operator <<(std::ostream& outputStream, const Weight& w2);
        friend std::istream& operator >>(std::istream& inputStream, Weight& w2);

    private:
        int pounds;
        int ounces;
};

#endif

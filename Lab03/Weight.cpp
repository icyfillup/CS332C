#include <iostream>
#include <cstdlib>
#include <ctime>

const bool DEBUG = false;
const int POUND_TO_OUNCE = 16;
const short SIZE = 5;

class Weight
{
    public:
        Weight(int pounds, int ounces); // Create a second constructor with input parameters for the amount of pounds and ounces.
        Weight(); //Create a default constructor that sets the weight amount to 0 pounds and 0 ounces.

        // getters
        int getPounds() const {return pounds;}
        int getOunces() const {return ounces;}
        //setters
        void setPounds(int poundValue);
        void setOunces(int ounceValue);

        const void output(); //Add a function that prints out the weight information
        const void output_d(); //Add a function that returns the weight amount as a double in pounds.

        const Weight operator +(const Weight& w2) const; //Overload the operator + for Weight objects.
        const Weight operator -(const Weight& w2) const; //Overload the operator - for Weight objects.
        bool operator ==(const Weight& w2) const; //Overload the operator == for Weight objects.

    private:
        int pounds;
        int ounces;
};

void debugFunction();

int main()
{
    srand(time(NULL));
    Weight weightList[SIZE];
    if(false)
    {
        debugFunction();
    }

//############################################################################################

    short tempOunces = 0;
    short tempPounds = 0;

    for(unsigned int i = 0; i < SIZE; i++)
    {
        if(i % 2)
        {
            tempOunces = -51 + rand() % 100;
            tempPounds = -51 + rand() % 100;
            weightList[i] = Weight(tempPounds, tempOunces);
            std::cout << "Weight " << i << " second constructor created." << std::endl;
        }
        else
        {
            weightList[i] = Weight();
            std::cout << "Weight " << i << " default constructor created." << std::endl;
        }
    }
    std::cout << std::endl;

//############################################################################################

    for(unsigned int i = 0; i < SIZE; i++)
    {
        std::cout << "Weight " << i << " output:\t";
        weightList[i].output();
        std::cout << "Weight " << i <<" output_d:\t";
        weightList[i].output_d();
        std::cout << std::endl;
    }

//############################################################################################

    for(unsigned int i = 0; i < SIZE; i++)
    {
        std::cout << "Weight " << i << " getPounds() and getOunces: " <<
                            weightList[i].getPounds() << ", " << weightList[i].getOunces() << std::endl;
    }
    std::cout << std::endl;

//############################################################################################

    for(unsigned int i = 0; i < SIZE; i++)
    {
        tempOunces = -51 + rand() % 100;
        tempPounds = -51 + rand() % 100;
        weightList[i].setOunces(tempOunces);
        weightList[i].setPounds(tempPounds);
        std::cout << "Weight " << i << " set random pounds and ounces:\t";
        weightList[i].output();
    }
    std::cout << std::endl;

//############################################################################################

    short ranIndex1 = 0;
    short ranIndex2 = 0;
    for(unsigned int i = 0; i < 3; i++)
    {
        ranIndex1 = rand() % SIZE;
        ranIndex2 = rand() % SIZE;
        std::cout << "Weight " << ranIndex1 << " + " << "Weight " << ranIndex2 << " = ";
        Weight w = weightList[ranIndex1] + weightList[ranIndex2];
        w.output();
    }
    std::cout << std::endl;

//############################################################################################

    for(unsigned int i = 0; i < 3; i++)
    {
        ranIndex1 = rand() % SIZE;
        ranIndex2 = rand() % SIZE;
        std::cout << "Weight " << ranIndex1 << " - " << "Weight " << ranIndex2 << " = ";
        Weight w = weightList[ranIndex1] - weightList[ranIndex2];
        w.output();
    }
    std::cout << std::endl;

//############################################################################################

    for(unsigned int i = 0; i < 3; i++)
    {
        ranIndex1 = rand() % SIZE;
        ranIndex2 = rand() % SIZE;
        std::cout << "Does Weight " << ranIndex1 << " == " << "Weight " << ranIndex2 << ": " <<
                                            ((weightList[ranIndex1] == weightList[ranIndex2]) ? "Yes" : "No") << std::endl;
    }

    return 0;
}

// ################public################
Weight::Weight(int pounds, int ounces) : pounds(pounds), ounces(ounces)
    {

    }

Weight::Weight() : pounds(0), ounces(0)
    {

    }

const void Weight::output()
{
    std::cout << "Pounds: " << pounds << " | Ounces: " << ounces << std::endl;
}

const void Weight::output_d()
{
    std::cout << "Weight in Decimal: " << (pounds + (ounces / 16.0)) << " pounds" << std::endl;
}

void Weight::setPounds(int poundValue)
{
    pounds = poundValue;
}

void Weight::setOunces(int ounceValue)
{
    ounces = ounceValue;
}

const Weight Weight::operator +(const Weight& w2) const
{
    int thisOunce = ounces + (pounds * POUND_TO_OUNCE);
    int otherOunce = w2.getOunces() + (w2.getPounds() * POUND_TO_OUNCE);

    int totalOunce = thisOunce + otherOunce;

    if(DEBUG)
    {
        std::cout << "\n##################################\n" << std::endl;

        std::cout << thisOunce << " + " << otherOunce << " = " << totalOunce << std::endl;

        std::cout << "\n##################################\n" << std::endl;
    }


    int convertedPounds = totalOunce / POUND_TO_OUNCE;
    int convertedOunces = totalOunce % POUND_TO_OUNCE;

    return Weight(convertedPounds, convertedOunces);
}

const Weight Weight::operator -(const Weight& w2) const
{
    int thisOunce = ounces + (pounds * POUND_TO_OUNCE);
    int otherOunce = w2.getOunces() + (w2.getPounds() * POUND_TO_OUNCE);

    int totalOunce = thisOunce - otherOunce;

    if(DEBUG)
    {
        std::cout << "\n##################################\n" << std::endl;

        std::cout << thisOunce << " - " << otherOunce << " = " << totalOunce << std::endl;

        std::cout << "\n##################################\n" << std::endl;
    }

    int convertedPounds = totalOunce / POUND_TO_OUNCE;
    int convertedOunces = totalOunce % POUND_TO_OUNCE;

    return Weight(convertedPounds, convertedOunces);
}

bool Weight::operator ==(const Weight& w2) const
{
    int thisOunce = ounces + (pounds * POUND_TO_OUNCE);
    int otherOunce = w2.getOunces()+ (w2.getPounds()* POUND_TO_OUNCE);

    return thisOunce == otherOunce;
}

void debugFunction()
{
    Weight w(10, 20);
    Weight w1;
    std::cout << "Weight w (second constructor):  \t";
    w.output();
    std::cout << "Weight w2 (default constructor):\t";
    w1.output();
    std::cout << std::endl;

    std::cout << "test getPounds(w): " << w.getPounds() << std::endl;
    std::cout << "test getOnuces(w): " << w.getOunces() << std::endl;
    std::cout << std::endl;
    std::cout << "test getPounds(w1): " << w1.getPounds() << std::endl;
    std::cout << "test getOnuces(w1): " << w1.getOunces() << std::endl;
    std::cout << std::endl;

    w.setPounds(20);
    w.setOunces(10);
    w1.setPounds(20);
    w1.setOunces(10);
    std::cout << "test w setPounds(20) and setOnuces(10): \t";
    w.output();
    std::cout << "test w1 setPounds(20) and setOnuces(10):\t";
    w1.output();
    std::cout << std::endl;

    std::cout << "test w output_d:\t";
    w.output_d();
    std::cout << "test w1 output_d:\t";
    w1.output_d();
    std::cout << std::endl;

    std::cout << "w + w1 = w2:\t";
    Weight w2 = w + w1;
    w2.output();
    std::cout << "w - w1 = w3:\t";
    Weight w3 = w - w1;
    w3.output();
    std::cout << "w - w2 = w4:\t";
    Weight w4 = w - w2;
    w4.output();
    std::cout << "w4 + w1 = w5:\t";
    Weight w5 = w4 + w1;
    w5.output();
    std::cout << "w4 + w4 = w6:\t";
    Weight w6 = w4 + w4;
    w6.output();
    std::cout << "w6 - w4 = w7:\t";
    Weight w7 = w6 - w4;
    w7.output();
    std::cout << std::endl;

    std::cout << "Is w == w1: " << ((w == w1) ? "True" : "False") << std::endl;
    std::cout << "Is w == w2: " << ((w == w2) ? "True" : "False") << std::endl;
    std::cout << "Is w2 == w3: " << ((w == w2) ? "True" : "False") << std::endl;
    std::cout << "Is w5 == w3: " << ((w5 == w3) ? "True" : "False") << std::endl;
    std::cout << std::endl;

    std::cout << "test w2 output:\t";
    w2.output();
    std::cout << "test w4 output:\t";
    w4.output();
    std::cout << std::endl;

    std::cout << "test w5 output_d:\t";
    w5.output_d();
    std::cout << "test w6 output_d:\t";
    w6.output_d();
}


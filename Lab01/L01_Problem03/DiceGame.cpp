#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

void addDiceRoll(short& playerSum);
void AI_DiceRoll(short& compSum);

int main()
{
    srand(time(NULL));

    cout << "Welcome to the Game of Dice." << endl;
    cout << "Today, you will be facing off with your computer." << endl;
    cout << "Lets get started.\n" << endl;

    bool turn = true;
    short playerSum = 0;
    short compSum = 0;
    while(true)
    {
        if(turn)
        {
            cout << "\nIt is the Player turn." << endl;
            cout << "Right now, you have " << playerSum << " point(s)." << endl;
            addDiceRoll(playerSum);
            if(playerSum >= 100)
            {
                cout << "\nThe player has " << playerSum << "." << endl;
                cout << "You have won." << endl;
                break;
            }
        }
        else
        {
            cout << "\nIt is the Computer turn." << endl;
            cout << "Right now, the Computer has " << compSum << " point(s)." << endl;
            AI_DiceRoll(compSum);
            if(compSum >= 100)
            {
                cout << "\nThe computer has " << compSum << "." << endl;
                cout << "The computer has won." << endl;
                break;
            }
        }
        turn = !turn;
        cout << "\n########################################\n" << endl;
    }

    return 0;
}

void AI_DiceRoll(short& compSum)
{
    short sum = 0;
    short diceNum = 0;
    while(true)
    {
        diceNum = 1 + (rand() % 6);
        sum += diceNum;
        cout << "\nThe Computer rolled a " << diceNum << "." << endl;

        if(diceNum == 1)
        {
            sum = 0;
            cout << "All the points earned in this turn has been loss." << endl;
            break;
        }
        cout << "Currently has " << sum << " point(s)." << endl;

        if(sum < 20)
            cout << "Computer has decided to Roll Again" << endl;
        else
        {
            compSum += sum;
            cout << "Computer has decided to Hold" << endl;
            break;
        }
    }
}

void addDiceRoll(short& playerSum)
{
    enum Option
    {
        ROLL_AGAIN,
        HOLD
    };
    srand(time(NULL));

    short sum = 0;
    short diceNum = 0;
    short menuNum;
    Option choose;
    do
    {
        diceNum = 1 + (rand() % 6);
        sum += diceNum;
        cout << "\nYou rolled a " << diceNum << "." << endl;

        if(diceNum == 1)
        {
            sum = 0;
            cout << "All the points earned in this turn has been loss." << endl;
            break;
        }

        cout << "You currently have " << sum << " point(s)." << endl;

        while(true)
        {
            cout << "\n1. Roll Again\n2. Hold\n==> ";
            cin >> menuNum;

            if(menuNum == 1)
                choose = ROLL_AGAIN;
            else if(menuNum == 2)
            {
                choose = HOLD;
                playerSum += sum;
            }
            else
                continue;
            break;
        }
    }
    while(choose == ROLL_AGAIN);
}

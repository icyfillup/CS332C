#include <iostream>
#include <string>
#include <locale>
#include <ctime>
#include <cstdlib>

using namespace std;

const short ROCK = 1;
const short PAPER = 2;
const short SCISSORS = 3;

enum Status
{
    LOSE = -1,
    TIE = 0,
    WIN = 1
};

short computerInput();
short userInput();
void isWinner(short comp, string user, Status key1, Status key2, Status key3);
void conditionMsg(Status cond, string user, string comp);

int main()
{
    cout << "Rock, Paper, Scissors\n" << endl;

    short comp = computerInput();
    short user = userInput();

    switch(user)
    {
        case ROCK:
            isWinner(comp, "Rock", TIE, LOSE, WIN);
            break;
        case PAPER:
            isWinner(comp, "Paper", WIN, TIE, LOSE);
            break;
        case SCISSORS:
            isWinner(comp, "Scissors", LOSE, WIN, TIE);
            break;
    }
    return 0;
}

short computerInput()
{
    srand(time(NULL));

    short ran = 1 + (rand() % 3);

    return ran;
}

short userInput()
{
    bool wrongItem = false;
    string userItem;
    string userC_Item;
    short itemID;
    locale loc;

    do
    {
        userC_Item = "";
        wrongItem = false;
        cout << "Ready your Weapon: ROCK, PAPER or SCISSORS:\t";
        cin >> userItem;
        for (unsigned int i=0; i<userItem.length(); ++i)
            userC_Item += toupper(userItem[i],loc);

        if(userC_Item.compare("ROCK") == 0)
            itemID = ROCK;
        else if(userC_Item.compare("PAPER") == 0)
            itemID = PAPER;
        else if(userC_Item.compare("SCISSORS") == 0)
            itemID = SCISSORS;
        else
        {
            wrongItem = true;
            cout << "\nWrong Item to ready..." << endl;
        }
    }
    while(wrongItem);

    return itemID;
}

void isWinner(short comp, string user, Status key1, Status key2, Status key3)
{
    switch(comp)
    {
        case ROCK:
            conditionMsg(key1, user, "Rock");
            break;
        case PAPER:
            conditionMsg(key2, user, "Paper");
            break;
        case SCISSORS:
            conditionMsg(key3, user, "Scissors");
            break;
    }
}

void conditionMsg(Status cond, string user, string comp)
{
    cout << "\nYou draw " << user << ". The computer draw " << comp << "." << endl;
    switch(cond)
    {
        case LOSE:
            cout << "You Lose.";
            break;
        case TIE:
            cout << "Draw.";
            break;
        case WIN:
            cout << "You Win.";
            break;
    }
}






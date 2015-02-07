#include <iostream>
#include <cstdlib>

using namespace std;

enum Shooter
{
    JASON = 0,
    KYLE = 1,
    LENNY = 2
};

enum ShootingProb
{
//  with function "probFrom1To12", jason = 4/12, kyle = 6/12, lenny = 12/12
    JASON_ACC = 4,
    KYLE_ACC = 6,
    LENNY_ACC = 12,
    WRONG = -1
};

void simulation(bool jasonMiss, float duelingLimit);
string getShooter(Shooter ID);
ShootingProb getShootingProb(Shooter ID);
bool probFrom1To12(short range);
Shooter duel(bool miss);
void shoot(Shooter shooter,Shooter firstTarget, Shooter secondTarget, bool& firstLife, bool& secondLife);
void isDied(Shooter shooter,Shooter target, bool& life);
void isLastManStanding(Shooter shooter, Shooter firstTarget, Shooter secondTarget, bool& firstLife, bool& secondLife,
                            bool& hasWinner, Shooter& winner);

int main()
{
    srand(time(NULL));
    short choose;
    bool running = true;

    cout << "Dueling Doofuses\n" << endl;
    cout << "We have 3 Idiots, Jason, Kyle, and Lenny, about to shoot each other in a duel....." << endl;
    while(running)
    {
        cout << "\nHow do you want to simulate their duel?\n" << endl;

        cout << "(1) => One Duel." << endl;
        cout << "(2) => One Duel where Jason miss first shot." << endl;
        cout << "(3) => 100000 Duels." << endl;
        cout << "(4) => 100000 Duels where Jason miss first shot." << endl;
        cout << "(0) => End Simulation" << endl;
        cout << "===>  ";
        cin >> choose;

        if(choose == 1)
        {simulation(false, 1.0);}
        else if(choose == 2)
        {simulation(true, 1.0);}
        else if(choose == 3)
        {simulation(false, 100000.0);}
        else if(choose == 4)
        {simulation(true, 100000.0);}
        else if(choose == 0)
        {
            running = false;
            exit(0);
        }
    }

    return 0;
}

void simulation(bool jasonMiss, float duelingLimit)
{
    int jasonWins = 0;
    int kyleWins = 0;
    int lennyWins = 0;
    for(int i = 0; i < duelingLimit; i++)
    {
        Shooter winner = duel(jasonMiss);
        if(winner == JASON)
            {jasonWins++;}
        else if(winner == KYLE)
            {kyleWins++;}
        else if (winner == LENNY)
            {lennyWins++;}
    }

    cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(2);
    cout << "Jason has won "<< jasonWins << "/" << duelingLimit << " duels or " << ((jasonWins/duelingLimit) * 100)  << endl;
    cout << "Kyle has won "<< kyleWins << "/" << duelingLimit << " duels or " << ((kyleWins/duelingLimit) * 100)  << endl;
    cout << "Lenny has won "<< lennyWins << "/" << duelingLimit << " duels or " << ((lennyWins/duelingLimit) * 100)  << endl;
}

Shooter duel(bool jasonMiss)
{
    bool jasonLife = true;
    bool kyleLife = true;
    bool lennyLife = true;
    bool hasWinner = false;
    Shooter winner;

    short counter = 0;

    while(!hasWinner)
    {
        if(jasonLife)
        {
            if(jasonMiss)
                {jasonMiss = false;}
            else
                {isLastManStanding(JASON, LENNY, KYLE, lennyLife, kyleLife, hasWinner, winner);}
        }
        if(kyleLife)
            {isLastManStanding(KYLE, LENNY, JASON, lennyLife, jasonLife, hasWinner, winner);}
        if(lennyLife)
            {isLastManStanding(LENNY, KYLE, JASON, kyleLife, jasonLife, hasWinner, winner);}

//      if there is an infinite loop......
        if(counter > 10)
            break;
        counter++;
    }

//    cout << "\n############################################\n"<< endl;
    return winner;
}

string getShooter(Shooter ID)
{
    if(ID == 0)
        {return "Jason";}
    else if(ID == 1)
        {return "Kyle";}
    else if(ID == 2)
        {return "Lenny";}
    else
        {return "NONEXISTING ID";}
}

ShootingProb getShootingProb(Shooter ID)
{
    if(ID == 0)
        {return JASON_ACC;}
    else if(ID == 1)
        {return KYLE_ACC;}
    else if(ID == 2)
        {return LENNY_ACC;}
    else
        {return WRONG;}
}

bool probFrom1To12(short range)
{
    return (rand() % 12) < range;
}

void isLastManStanding(Shooter shooter, Shooter firstTarget, Shooter secondTarget, bool& firstLife, bool& secondLife,
                            bool& hasWinner, Shooter& winner)
{
    if(firstLife || secondLife)
    {
//        cout << getShooter(shooter) << " turn." << endl;
        shoot(shooter, firstTarget, secondTarget, firstLife, secondLife);
    }
    else
    {
        winner = shooter;
        hasWinner = true;
//        cout << getShooter(shooter) << " is the last man Standing." << endl;
    }
}

void shoot(Shooter shooter,Shooter firstTarget, Shooter secondTarget, bool& firstLife, bool& secondLife)
{
    if(firstLife)
        {isDied(shooter, firstTarget, firstLife);}
    else if(secondLife)
        {isDied(shooter, secondTarget, secondLife);}
}

void isDied(Shooter shooter,Shooter target, bool& life)
{
//    cout << getShooter(shooter) << " is aiming at " << getShooter(target) << ". | prob: " << getShootingProb(shooter) << endl;
    if(probFrom1To12(getShootingProb(shooter)))
    {
        life = false;
       /* cout << getShooter(shooter) << " has shot " << getShooter(target) << "." << endl;
        cout << getShooter(target) << " is died.\n" << endl;*/
    }
    else
    {
 //       cout << getShooter(shooter) << " has miss " << getShooter(target) << ".\n" << endl;
    }
}

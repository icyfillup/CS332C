#include <iostream>
#include <ctime>
#include <cstdlib>

enum Slot
{
    PLAYER1,
    PLAYER2,
    EMTPY
    // Spelled empty wrong...
};

const short SIZE = 3;
const short OPTION_SIZE = 2;

void SetupState(bool compAI);
void PlayState(Slot board[][SIZE], bool compAI);
void setupBoard(Slot board[][SIZE], short size);
void printBoard(const Slot board[][SIZE], short size);
std::string getSlotToken(Slot s);
bool isSlotEmtpy(const Slot board[][SIZE], short x, short y);
bool checkBoardOfWinner(const Slot board[][SIZE], short size);
bool hasHorizontal(const Slot board[][SIZE], short size);
bool hasVertical (const Slot board[][SIZE], short size);
bool hasDiagonal (const Slot board[][SIZE]);
bool isTie(const Slot board[][SIZE], short size);
void setPosition(Slot board[][SIZE], Slot s, short x, short y);
void userInput(short coor[][OPTION_SIZE], short size, Slot board[][SIZE]);
void compInput(short coor[][OPTION_SIZE], Slot board[][SIZE]);

int main()
{
    srand(time(NULL));
    short choose = 0;

    std::cout << "Tic-Tac-Toe Game\n" << std::endl;
    std::cout << "1. Player 1 VS Player 2" << std::endl;
    std::cout << "2. Player 1 VS Computer" << std::endl;
    std::cout << "0. Exit" << std::endl;
    do
    {
        std::cout << "====> ";
        std::cin >> choose;
    }
    while(choose < 0 ||choose > 2);
    std::cout << std::endl;

    switch(choose)
    {
        case 0:
            break;
        case 1:
            SetupState(false);
            break;
        case 2:
            SetupState(true);
            break;
    }

    return 0;
}

void SetupState(bool compAI)
{
    /*Slot board[SIZE][SIZE] = {
                                {EMTPY,EMTPY,EMTPY},
                                {EMTPY,EMTPY,EMTPY},
                                {EMTPY,EMTPY,EMTPY}
                                                    };*/
    Slot board[SIZE][SIZE];
    setupBoard(board, SIZE);
    PlayState(board, compAI);
}

void PlayState(Slot board[][SIZE], bool compAI)
{

    bool running = true;
    bool currentPlayer = true;
    short coor[1][OPTION_SIZE] = {{0,0}};

    while(running)
    {
        printBoard(board, SIZE);
        if(currentPlayer == 1)
        {
            std::cout << "Player 1's Turn" << std::endl;
            userInput(coor, OPTION_SIZE, board);
            setPosition(board, PLAYER1, coor[0][0], coor[0][1]);
            if(checkBoardOfWinner(board, SIZE))
            {
                std::cout << "\nPlayer 1 Wins";
                running = false;
            }
        }
        else
        {
            if(compAI)
            {
                std::cout << "Computer's Turn" << std::endl;
                compInput(coor, board);
                setPosition(board, PLAYER2, coor[0][0], coor[0][1]);
                if(checkBoardOfWinner(board, SIZE))
                {
                    std::cout << "\nComputer Wins";
                    running = false;
                }
            }
            else
            {
                std::cout << "Player 2's Turn" << std::endl;
                userInput(coor, OPTION_SIZE, board);
                setPosition(board, PLAYER2, coor[0][0], coor[0][1]);
                if(checkBoardOfWinner(board, SIZE))
                {
                    std::cout << "\nPlayer 2 Wins";
                    running = false;
                }
            }
        }
        currentPlayer = !currentPlayer;
        if(running && isTie(board, SIZE))
        {
            running = false;
            std::cout << "\nTIE!!!!!" << std::endl;
        }
        std::cout << std::endl;
    }
    printBoard(board, SIZE);
}

void setupBoard(Slot board[][SIZE], short size)
{
    for(unsigned short x = 0; x < size; x++)
        for(unsigned short y = 0; y < size; y++)
            board[x][y] = EMTPY;
}

void printBoard(const Slot board[][SIZE], short size)
{
    for(unsigned short x = 0; x < size; x++)
    {
        for(unsigned short y = 0; y < size; y++)
            {std::cout << " | " << getSlotToken(board[x][y]);}
        std::cout << " |" << std::endl;
    }
}

std::string getSlotToken(Slot s)
{
    if(s == PLAYER1)
        {return "X";}
    else if(s == PLAYER2)
        {return "O";}
    else
        {return " ";}
}

bool isSlotEmtpy(const Slot board[][SIZE], short x, short y)
{
    if(board[x][y] == EMTPY)
        {return true;}
    else
        {return false;}
}

bool checkBoardOfWinner(const Slot board[][SIZE], short size)
{
    return hasHorizontal(board, size) || hasVertical (board, size) || hasDiagonal (board);
}

bool hasHorizontal(const Slot board[][SIZE], short size)
{
    bool check = false;
    for(unsigned short x = 0; x < size; x++)
    {
        if(board[x][0] != EMTPY)
            if(board[x][0] == board[x][1] && board[x][1] == board[x][2])
                {check = true;}
    }
    return check;
}

bool hasVertical (const Slot board[][SIZE], short size)
{
    bool check = false;
    for(unsigned short y = 0; y < size; y++)
    {
        if(board[0][y] != EMTPY)
            if(board[0][y] == board[1][y] && board[1][y] == board[2][y])
                {check = true;}
    }
    return check;
}

bool hasDiagonal (const Slot board[][SIZE])
{
    bool check = false;
    if(board[1][1] != EMTPY)
    {
        if(board[0][0] == board[1][1] && board[1][1] == board[2][2])
            {check = true;}
        if(board[2][0] == board[1][1] && board[1][1] == board[0][2])
            {check = true;}
    }
    return check;
}

bool isTie(const Slot board[][SIZE], short size)
{
    for(unsigned short x = 0; x < size; x++)
        for(unsigned short y = 0; y < size; y++)
            if(board[x][y] == EMTPY)
            {
                return false;
                break;
            }
    return true;
}

void setPosition(Slot board[][SIZE], Slot s, short x, short y)
{
    board[x][y] = s;
}

void userInput(short coor[][OPTION_SIZE], short size, Slot board[][SIZE])
{
    bool check;
    do
    {
        check = false;
        std::cout << "Enter coor from 1 - 3" << std::endl;
        std::cout << "===> ";
        std::cin >> coor[0][0];
        std::cin >> coor[0][1];

        coor[0][0] -= 1;
        coor[0][1] -= 1;

        for(unsigned short i = 0; i < size; i++)
        {
            if(coor[0][i] < 0 || coor[0][i] > 2)
            {
                std::cout << "Wrong Coordinate\n" << std::endl;
                check = true;
            }
        }

        if(!check && !isSlotEmtpy(board, coor[0][0], coor[0][1]))
        {
            std::cout << "Space Occupied\n" << std::endl;
            check = true;
        }
    }
    while(check);
}

void compInput(short coor[][OPTION_SIZE], Slot board[][SIZE])
{
    bool check;
    do
    {
        check = false;
        coor[0][0] = rand() % 3;
        coor[0][1] = rand() % 3;

        if(!isSlotEmtpy(board, coor[0][0], coor[0][1]))
            {check = true;}
    }
    while(check);
}


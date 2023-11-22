#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <iomanip>
#include <time.h>
#include <unistd.h>
using namespace std;

class TicTacToe
{
public:
    char mat[3][3];
    int row, column;
    char turn = 'X';
    bool draw = false;
    int winner = 0;
    int counter = 0;
    ;
    TicTacToe()
    {
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                mat[i][j] = '_';
            }
        }
    }
    void Display()
    {
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                cout << mat[i][j] << " ";
            }

            cout << " " << endl;
        }
    }
    void playerTurn()
    {
        if (turn == 'X')
        {
            cout << "Player - 1 [X] turn : \nPlease enter desired row followed by desired column from 1 to 3" << endl;
        }
        else if (turn == 'O')
        {
            cout << "Player - 2 [O] turn : \nPlease enter desired row followed by desired column from 1 to 3" << endl;
        }
        cin >> row >> column;
        if (row < 1 || row > 3 || column < 1 || column > 3)
        {
            cout << "Sorry this is an invalid input" << endl;
            playerTurn();
        }

        if (turn == 'X' && mat[row - 1][column - 1] != 'X' && mat[row - 1][column - 1] != 'O')
        {
            mat[row - 1][column - 1] = 'X';
            counter++;
            turn = 'O';
        }
        else if (turn == 'O' && mat[row - 1][column - 1] != 'X' && mat[row - 1][column - 1] != 'O')
        {
            mat[row - 1][column - 1] = 'O';
            counter++;
            turn = 'X';
        }
        else
        {
            cout << "Box already filled! Please choose another!!";
            playerTurn();
        }
        Display();
    }
    bool gameover()
    {
        // checking the win for Simple Rows and Simple Column
        if (counter > 4)
        {
            for (int i = 0; i < 3; i++)
            {
                if (mat[i][0] == mat[i][1] && mat[i][0] == mat[i][2] || mat[0][i] == mat[1][i] && mat[0][i] == mat[2][i])
                {
                    if ((mat[i][0] == 'X' && mat[i][1] == 'X' && mat[i][2] == 'X') || (mat[0][i] == 'X' && mat[1][i] == 'X' && mat[2][i] == 'X'))
                    {
                        winner = 1;
                    }
                    else if ((mat[i][0] == 'O' && mat[i][1] == 'O' && mat[i][2] == 'O') || (mat[0][i] == 'O' && mat[1][i] == 'O' && mat[2][i] == 'O'))
                    {
                        winner = 2;
                    }
                    return true;
                }
            }
        }
        // checking the win for both diagonal
        if (counter > 4)
        {
            if (mat[0][0] == mat[1][1] && mat[0][0] == mat[2][2] || mat[0][2] == mat[1][1] && mat[0][2] == mat[2][0])
            {
                if ((mat[0][0] == 'X' && mat[1][1] == 'X' && mat[2][2] == 'X') || (mat[0][2] == 'X' && mat[1][1] == 'X' && mat[2][0] == 'X'))
                {
                    winner = 1;
                }
                else if ((mat[0][0] == 'O' && mat[1][1] == 'O' && mat[2][2] == 'O') || (mat[0][2] == 'O' && mat[1][1] == 'O' && mat[2][0] == 'O'))
                {
                    winner = 2;
                }
                return true;
            }
        }
        // Checking the game is draw
        if (counter > 8)
        {
            draw = true;
            return true;
        }
        // Checking if the game can continue
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (mat[i][j] != 'X' && mat[i][j] != 'O')
                {
                    return false;
                }
            }
        }
        return false;
    }
};

int main()
{

    TicTacToe game1;
    cout << "Welcome to TicTacToe..." << endl;
    cout << "    FOR 2 PLAYERS    " << endl;
    cout << "PLAYER 1 is X     PLAYER 2 is O" << endl;
    game1.Display();

    while (game1.gameover() == false && game1.draw == false)
    {
        game1.playerTurn();
        sleep(1);
    }

    if (game1.gameover() == true && game1.draw == false)
    {
        if (game1.winner == 1)
            cout << "  Congratulations! Player with 'X' has won the game";
        else if (game1.winner == 2)
        {
            cout << "  Congratulations! Player with 'O' has won the game";
        }
    }
    if (game1.draw == true)
    {
        cout << "GAME DRAW!!!" << endl;
    }
}

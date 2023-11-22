#include <iostream>
using namespace std;

class playerInfo
{
public:
    char playerName[81];
    char playerID;
};

int PlayerDrop(char board[][10], playerInfo activePlayer);
void CheckBelow(char board[][10], playerInfo activePlayer, int dropChoice);
void DisplayBoard(char board[][10]);
int CheckFour(char board[][10], playerInfo activePlayer);
int FullBoard(char board[][10]);
void PlayerWin(playerInfo activePlayer);

int main()
{
    playerInfo playerOne, playerTwo;
    char board[9][10];
    int trueWidth = 7;
    int trueLength = 6;
    int dropChoice, win, full;

    cout << "Let's Play Connect 4" << endl
         << endl;
    cout << "Player One please enter your name: ";
    cin >> playerOne.playerName;
    playerOne.playerID = 'X';
    cout << "Player Two please enter your name: ";
    cin >> playerTwo.playerName;
    playerTwo.playerID = 'O';

    full = 0;
    win = 0;
    DisplayBoard(board);
    do
    {
        dropChoice = PlayerDrop(board, playerOne);
        CheckBelow(board, playerOne, dropChoice);
        DisplayBoard(board);
        win = CheckFour(board, playerOne);
        if (win == 1)
        {
            PlayerWin(playerOne);
            break;
        }

        dropChoice = PlayerDrop(board, playerTwo);
        CheckBelow(board, playerTwo, dropChoice);
        DisplayBoard(board);
        win = CheckFour(board, playerTwo);
        if (win == 1)
        {
            PlayerWin(playerTwo);
            break;
        }

        full = FullBoard(board);
        if (full == 7)
        {
            cout << "The board is full, it is a draw!" << endl;
            break;
        }
    } while (win != 1);

    return 0;
}

// Drops a player's token into the board
int PlayerDrop(char board[][10], playerInfo activePlayer)
{
    int dropChoice;
    cout << activePlayer.playerName << "'s Turn ";
    do
    {
        cout << "Please enter a number between 1 and 7 to indicate which column to drop in: ";
        cin >> dropChoice;

        if (board[1][dropChoice] == 'X' || board[1][dropChoice] == 'O')
        {
            cout << "That column is full. ";
            dropChoice = 0;
            continue;
        }
    } while (dropChoice < 1 || dropChoice > 7);

    return dropChoice;
}

// Checks up a column until it finds an empty spot, during then it adds an X/O
void CheckBelow(char board[][10], playerInfo activePlayer, int dropChoice)
{
    int length, turn;
    length = 6;
    turn = 0;

    do
    {
        if (board[length][dropChoice] != 'X' && board[length][dropChoice] != 'O')
        {
            board[length][dropChoice] = activePlayer.playerID;
            turn = 1;
        }
        else
            --length;
    } while (turn != 1);
}

// Displays the setup of the board during the game
void DisplayBoard(char board[][10])
{
    int rows = 6, columns = 7;

    for (int i = 1; i <= rows; i++)
    {
        cout << "|";
        for (int j = 1; j <= columns; j++)
        {
            if (board[i][j] != 'X' && board[i][j] != 'O')
                board[i][j] = '*';

            cout << board[i][j];
        }

        cout << "|" << endl;
    }
}

// Checks to see if there is a connect 4, and if so the player wins
int CheckFour(char board[][10], playerInfo activePlayer)
{
    char XO;
    int win;

    XO = activePlayer.playerID;
    win = 0;

    for (int i = 8; i >= 1; --i)
    {

        for (int j = 9; j >= 1; --j)
        {

            if (board[i][j] == XO &&
                board[i - 1][j - 1] == XO &&
                board[i - 2][j - 2] == XO &&
                board[i - 3][j - 3] == XO)
            {
                win = 1;
            }

            if (board[i][j] == XO &&
                board[i][j - 1] == XO &&
                board[i][j - 2] == XO &&
                board[i][j - 3] == XO)
            {
                win = 1;
            }

            if (board[i][j] == XO &&
                board[i - 1][j] == XO &&
                board[i - 2][j] == XO &&
                board[i - 3][j] == XO)
            {
                win = 1;
            }

            if (board[i][j] == XO &&
                board[i - 1][j + 1] == XO &&
                board[i - 2][j + 2] == XO &&
                board[i - 3][j + 3] == XO)
            {
                win = 1;
            }

            if (board[i][j] == XO &&
                board[i][j + 1] == XO &&
                board[i][j + 2] == XO &&
                board[i][j + 3] == XO)
            {
                win = 1;
            }
        }
    }
    return win;
}

// Checks to see if the board is full
int FullBoard(char board[][10])
{
    int full;
    full = 0;

    for (int i = 1; i <= 7; ++i)
    {
        if (board[1][i] != '*')
            ++full;
    }

    return full;
}

// Returns a statement saying which player won
void PlayerWin(playerInfo activePlayer)
{
    cout << endl
         << activePlayer.playerName << " Connected Four, You Win!" << endl;
}
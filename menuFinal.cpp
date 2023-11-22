#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <iomanip>
#include <time.h>
#include <unistd.h>
#include <string>
#include <fstream>
#include <random>
using namespace std;

class conn{
    public: 

    class playerInfo{
    public:
        char playerName[81];
        char playerID;
    };

    conn(){
        int PlayerDrop(char board[][10], playerInfo activePlayer);
        void CheckBelow(char board[][10], playerInfo activePlayer, int dropChoice);
        void DisplayBoard(char board[][10]);
        int CheckFour(char board[][10], playerInfo activePlayer);
        int FullBoard(char board[][10]);
        void PlayerWin(playerInfo activePlayer);
    }
    
    void sun(){
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

    }

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

    void PlayerWin(playerInfo activePlayer)
    {
        cout << endl
             << activePlayer.playerName << " Connected Four, You Win!" << endl;
    }
};

class tic{
    public: 
    class TicTacToe{
    public:
        char mat[3][3];
        int row, column;
        char turn;
        bool draw;
        int winner;
        int counter;
        
        TicTacToe()
        {
            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    mat[i][j] = '_';
                }
            }
            turn = 'X';
            draw = false;
            winner = 0;
            counter = 0;
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

    void sun()
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
                cout << "  Congratulations! Player with 'X' has won the game" << endl;
            else if (game1.winner == 2)
            {
                cout << "  Congratulations! Player with 'O' has won the game"<< endl;
            }
        }
        if (game1.draw == true)
        {
            cout << "GAME DRAW!!!" << endl;
        }
    }

};

class hang{
public:
    string WORDBANK;

    // Function Prototypes
    hang(){
        WORDBANK = "wordbank.txt";
        void display(int lives);
    }


    void sun()
    {
        string word = getRandWord();
        string hiddenword = "";
        char guess;
        char guessArray[26];
        int lives;
        int difficulty;

        // Ask the user for what difficulty they want
        cout << "What difficulty do you want?" << endl;
        cout << "1. Easy (8 Lives)" << endl;
        cout << "2. Medium (6 Lives)" << endl;
        cout << "3. Hard (4 Lives)" << endl;
        cout << "4. Impossible (2 Lives)" << endl;
        cout << "Enter a number: ";
        cin >> difficulty;

        // Set the number of lives based on the difficulty
        switch (difficulty)
        {
        case 1:
            lives = 8;
            break;
        case 2:
            lives = 6;
            break;
        case 3:
            lives = 4;
            break;
        case 4:
            lives = 2;
            break;
        default:
            lives = 8;
            break;
        }

        // Create the hidden word
        for (int i = 0; i < word.length(); i++)
        {
            if (word[i] == ' ')
            {
                hiddenword += " ";
            }
            else
            {
                hiddenword += "_";
            }
        }

        cout << "Welcome to Hangman!" << endl;
        // Loop until the user runs out of lives or guesses the word
        while (lives > 0)
        {
            // Display the hangman and the hidden word
            display(lives);
            cout << hiddenword << endl;
            cout << "Guess a letter: ";
            cin >> guess;
            // Check if the player has already guessed the letter
            if (guessArray[guess - 'a'] == guess)
            {
                cout << "You already guessed that letter!" << endl;
                continue;
            }
            // Add the letter to the array of guessed letters
            guessArray[guess - 'a'] = guess;
            // Check if the letter is in the word. If so update the hidden word, if not decrement lives
            for (int i = 0; i < word.length(); i++)
            {
                if (word[i] == guess)
                {
                    hiddenword[i] = guess;
                }
            }
            if (word.find(guess) == string::npos)
            {
                lives--;
            }
            // Check if the player has won
            if (hiddenword == word)
            {
                cout << "You win!" << endl;
                break;
            }
        }
        // If the player runs out of lives, display the hangman and the word
        if (lives == 0)
        {
            display(lives);
            cout << "You lose!" << endl;
            cout << "The word was " << word << endl;
        }
    }

    void display(int lives)
    {
        if (lives == 8)
        {
            cout << " _______" << endl;
            cout << " |     " << endl;
            cout << " |     " << endl;
            cout << " |     " << endl;
            cout << " |     " << endl;
            cout << " |     " << endl;
            cout << " |     " << endl;
            cout << "_|_" << endl;
        }
        if (lives == 7)
        {
            cout << " _______" << endl;
            cout << " |     |" << endl;
            cout << " |     " << endl;
            cout << " |     " << endl;
            cout << " |     " << endl;
            cout << " |     " << endl;
            cout << " |     " << endl;
            cout << "_|_" << endl;
        }
        if (lives == 6)
        {
            cout << " _______" << endl;
            cout << " |     |" << endl;
            cout << " |     |" << endl;
            cout << " |     " << endl;
            cout << " |     " << endl;
            cout << " |     " << endl;
            cout << " |     " << endl;
            cout << "_|_" << endl;
        }
        else if (lives == 5)
        {
            cout << " _______" << endl;
            cout << " |     |" << endl;
            cout << " |     |" << endl;
            cout << " |     O" << endl;
            cout << " |     " << endl;
            cout << " |     " << endl;
            cout << " |     " << endl;
            cout << "_|_" << endl;
        }
        else if (lives == 4)
        {
            cout << " _______" << endl;
            cout << " |     |" << endl;
            cout << " |     |" << endl;
            cout << " |     O" << endl;
            cout << " |     |" << endl;
            cout << " |     " << endl;
            cout << " |     " << endl;
            cout << "_|_" << endl;
        }
        else if (lives == 3)
        {
            cout << " _______" << endl;
            cout << " |     |" << endl;
            cout << " |     |" << endl;
            cout << " |     O" << endl;
            cout << " |    /|" << endl;
            cout << " |     " << endl;
            cout << " |     " << endl;
            cout << "_|_" << endl;
        }
        else if (lives == 2)
        {
            cout << " _______" << endl;
            cout << " |     |" << endl;
            cout << " |     |" << endl;
            cout << " |     O" << endl;
            cout << " |    /|\\" << endl;
            cout << " |     " << endl;
            cout << " |     " << endl;
            cout << "_|_" << endl;
        }
        else if (lives == 1)
        {
            cout << " _______" << endl;
            cout << " |     |" << endl;
            cout << " |     |" << endl;
            cout << " |     O" << endl;
            cout << " |    /|\\" << endl;
            cout << " |    /" << endl;
            cout << " |     " << endl;
            cout << "_|_" << endl;
        }
        else if (lives == 0)
        {
            cout << " _______" << endl;
            cout << " |     |" << endl;
            cout << " |     |" << endl;
            cout << " |     O" << endl;
            cout << " |    /|\\" << endl;
            cout << " |    / \\" << endl;
            cout << " |     " << endl;
            cout << "_|_" << endl;
        }
    }

    string getRandWord()
    {
        ifstream fin;
        fin.open(WORDBANK);
        string word;
        int count = 0;
        while (fin >> word)
        {
            count++;
        }
        fin.close();
        fin.open(WORDBANK);
        int randNum = rand() % count;
        for (int i = 0; i < randNum; i++)
        {
            fin >> word;
        }
        fin.close();
        return word;
    }
};

class mine{
public:
    char table[10][10];                // the game table visible ot the player
    char table_mine_positions[10][10]; // table with the positions of the mines and the number of each cell
    char symbol;                       // the input symbol, it can be 'o' or f'
    int flag_counter;
    int mines_flagged_counter;
    bool end_game_lose;
    time_t time_since_epoch;
    time_t game_time;

    mine(){
        flag_counter = 0;
        mines_flagged_counter = 0;
        end_game_lose = false;
        time_since_epoch = time(0);
    }

    void cell_number(int i, int j)
    {
        if (i >= 0 && i < 10 && j >= 0 && j < 10 && table_mine_positions[i][j] != 'X')
            table_mine_positions[i][j]++;
    }

    void create_mine_positions()
    {
        int counter = 0;
        srand(time(NULL));

        for (int i = 0; i < 10; i++)
            for (int j = 0; j < 10; j++)
                table_mine_positions[i][j] = '0';

        int i = 0;
        int j = 0;
        while (counter < 10)
        {
            int i = rand() % 10;
            int j = rand() % 10;
            if (table_mine_positions[i][j] == '0')
            {
                table_mine_positions[i][j] = 'X';

                cell_number(i - 1, j);
                cell_number(i + 1, j);
                cell_number(i, j - 1);
                cell_number(i, j + 1);
                cell_number(i - 1, j - 1);
                cell_number(i - 1, j + 1);
                cell_number(i + 1, j - 1);
                cell_number(i + 1, j + 1);
                counter++;
            }
        }
    }

    void create_table()
    {
        for (int i = 0; i < 10; i++)
            for (int j = 0; j < 10; j++)
                table[i][j] = '*';
    }

    void print_table(char arr[10][10])
    {
        cout << "    ";
        for (int i = 0; i < 10; i++)
            cout << setw(3) << i;

        cout << endl
             << "  ";
        for (int i = 0; i < 32; i++)
            cout << "_";
        cout << " (j)" << endl;

        for (int i = 0; i < 10; i++)
        {
            cout << setw(3) << i << "|";
            for (int j = 0; j < 10; j++)
                cout << setw(3) << arr[i][j];
            cout << endl;
        }
        cout << " (i)" << endl;
    }

    void open_cell()
    {
        int i, j;

        do
            cin >> i >> j;
        while (i < 0 || i > 9 || j < 0 || j > 9);

        if (table_mine_positions[i][j] == 'X')
        {
            table[i][j] = 'X';
            end_game_lose = true;

            for (int i = 0; i < 10; i++)
                for (int j = 0; j < 10; j++)
                    if (table_mine_positions[i][j] == 'X')
                        table[i][j] = 'X';
        }
        else
            reveal(i, j);
    }

    void place_or_remove_flag()
    {
        int i, j;
        do
            cin >> i >> j;
        while (i < 0 || i > 9 || j < 0 || j > 9);

        if (table[i][j] == '*')
        {
            table[i][j] = 'F';
            flag_counter++;

            if (table_mine_positions[i][j] == 'X')
                mines_flagged_counter++;
        }

        else if (table[i][j] == 'F')
        {
            table[i][j] = '*';
            flag_counter--;
            if (table_mine_positions[i][j] == 'X')
                mines_flagged_counter--;
        }
    }

    void input_symbol()
    {
        cin >> symbol;
        switch (symbol)
        {
        case 'o':
            open_cell();
            break;
        case 'f':
            place_or_remove_flag();
            break;
        default:
            input_symbol();
        }
    }

    void reveal(int i, int j)
    {
        if (table[i][j] == '*' && table_mine_positions[i][j] != 'X' && i >= 0 && i < 10 && j >= 0 && j < 10)
        {
            table[i][j] = table_mine_positions[i][j];

            if (table_mine_positions[i][j] == '0')
            {
                reveal(i, j - 1);
                reveal(i, j + 1);
                reveal(i - 1, j - 1);
                reveal(i + 1, j - 1);
                reveal(i + 1, j + 1);
                reveal(i - 1, j + 1);
                reveal(i - 1, j);
                reveal(i + 1, j);
            }
        }
    }

    bool end_game_win_check()
    {
        if (flag_counter == 10 && mines_flagged_counter == 10)
            return 1;
        else
            return 0;
    }

    void game()
    {
        create_table();
        create_mine_positions();

        while (!end_game_lose && !end_game_win_check())
        {
            game_time = time(0);
            print_table(table);
            cout << endl
                 << "Flags:" << flag_counter << endl;
            cout << "Time:" << game_time - time_since_epoch << endl;
            input_symbol();
        }

        if (end_game_lose){
            print_table(table);
            cout << endl
                 << "GAME OVER" << endl;
        }

        else if (end_game_win_check()){
            cout << "Time to complete:" << game_time - time_since_epoch << endl;
            cout << endl
                 << "YOU WIN!" << endl;
        }
            
    }

    void sun()
    {
        cout
            << "\n------------------------------------------------------"
            << endl
            << "Welcome to Minesweeper!\n"
            << endl
            << "Goal: flag all of the bombs and open all the open cells"
            << endl
            << "Hint: upon opening a cell, the number will indicate how \nmany bombs are within the 8 cells around its perimeter "
            << endl
            << "------------------------------------------------------"
            << "\nRules:\n"
            << endl
            << "Enter 'o' to open a cell, then enter i and j value \nof the location of cell (ex. o 3 4 - opens (3,4))\n "
            << endl
            << "Enter 'f' to flag or remove a flag from a cell, then \nenter value of i and j to the location (ex. f 3 4) "
            << endl
            << "------------------------------------------------------"
            << endl;

        game();
    }

};

class ArcadeMachine{
public:
    float hangmanPrice, tictactoePrice, minesweeperPrice, connect4Price; // attributes
    int AlphaCoin, hangman, tictactoe, minesweeper, connect4;

    ArcadeMachine()
    {
        AlphaCoin = 5;

        hangmanPrice = 5;
        tictactoePrice = 7;
        minesweeperPrice = 5;
        connect4Price = 8;

    }
    
    void hGame(){
        hang play;
        play.sun();
    }

    void tGame(){
        tic play;
        play.sun();
    }

    void mGame(){
        mine play;
        play.sun();
    }
    
    void cGame(){
        conn play;
        play.sun();
    }

    void hangmanPurchase()
    {
        int coins;

        cout << "-------------------------------------" << endl;
        cout << "The price of hangman is: " << hangmanPrice << "CC" << endl;
        cout << "Please insert coins: " << endl;
        cin >> coins;

        if (coins < hangmanPrice)
        {
            cout << "\nSorry, not enough coins\nRefund: " << coins << "CC" << endl;
            cout << "If you want more coins visit the refill coins dungeon!" << endl;
            cout << "-------------------------------------" << endl;
        }
        else if (AlphaCoin < hangmanPrice)
        {
            cout << "\nSorry, not enough coins\nRefund: " << coins << "CC" << endl;
            cout << "If you want more coins visit the refill coins dungeon!" << endl;
            cout << "-------------------------------------" << endl;
        }
        else
        {
            cout << "Success!" << endl;
            cout << "\nChange Due: " << coins - hangmanPrice << "CC" << endl;

            AlphaCoin = AlphaCoin - 5;
            hGame();
        }
        menuChoice();
    }

    void tictactoePurchase()
    {
        int coins;

        cout << "-------------------------------------" << endl;
        cout << "The price of Tic-tac-toe is: " << tictactoePrice << "CC" << endl;
        cout << "Please insert coins: " << endl;
        cin >> coins;

        if (coins < tictactoePrice )
        {
            cout << "\nSorry, not enough coins\nRefund: " << coins << "CC" << endl;
            cout << "If you want more coins visit the refill coins dungeon!" << endl;
            cout << "-------------------------------------" << endl;
        }
        else if (AlphaCoin < tictactoePrice)
        {
            cout << "\nSorry, not enough coins\nRefund: " << coins << "CC" << endl;
            cout << "If you want more coins visit the refill coins dungeon!" << endl;
            cout << "-------------------------------------" << endl;
        }
        else
        {
            cout << "Success!" << endl;
            cout << "\nChange Due: " << coins - tictactoePrice << "CC" << endl;
            cout << "-------------------------------------" << endl;

            AlphaCoin = AlphaCoin - 7;
            tGame();
        }
        menuChoice();
    }

    void minesweeperPurchase()
    {
        int coins;

        cout << "-------------------------------------" << endl;
        cout << "The price of Minesweeper is: " << minesweeperPrice << "CC" << endl;
        cout << "Please insert coins: " << endl;
        cin >> coins;

        if (coins < minesweeperPrice)
        {
            cout << "\nSorry, not enough coins\nRefund: " << coins << "CC" << endl;
            cout << "If you want more coins visit the refill coins dungeon!" << endl;
            cout << "-------------------------------------" << endl;
        }
        else if (AlphaCoin < minesweeperPrice)
        {
            cout << "\nSorry, not enough coins\nRefund: " << coins << "CC" << endl;
            cout << "If you want more coins visit the refill coins dungeon!" << endl;
            cout << "-------------------------------------" << endl;
        }
        else
        {
            cout << "Success!" << endl;
            cout << "\nChange Due: " << coins - hangmanPrice << "CC" << endl;
            cout << "-------------------------------------" << endl;

            AlphaCoin = AlphaCoin - 5;
            mGame();
        }
        menuChoice();
    }

    void connect4Purchase()
    {
        int coins;

        cout << "-------------------------------------" << endl;
        cout << "The price of Connect 4 is: " << connect4Price << "CC" << endl;
        cout << "Please insert coins: " << endl;
        cin >> coins;

        if (coins < connect4Price)
        {
            cout << "\nSorry, not enough coins\nRefund: " << coins << "CC" << endl;
            cout << "If you want more coins visit the refill coins dungeon!" << endl;
            cout << "-------------------------------------" << endl;
        }
        else if( AlphaCoin < connect4Price){
            cout << "\nSorry, not enough coins\nRefund: " << coins << "CC" << endl;
            cout << "If you want more coins visit the refill coins dungeon!" << endl;
            cout << "-------------------------------------" << endl;
        }
        else
        {
            cout << "Success!" << endl;
            cout << "\nChange Due: " << coins - connect4Price << "CC" << endl;
            cout << "-------------------------------------" << endl;

            AlphaCoin = AlphaCoin - 8;
            cGame();
        }
        menuChoice();
    }
    
    void gameChoice()
    {
        while (1)
        {
            int choice;
            cout << "-------------------------------------" << endl;
            cout << "| What game would you like to play? |" << endl;
            cout << "|       ---------------------       |" << endl;
            cout << "|         1) Hangman                |" << endl;
            cout << "|         2) Tic Tac Toe            |" << endl;
            cout << "|         3) Minesweeper            |" << endl;
            cout << "|         4) Connect 4              |" << endl;
            cout << "-------------------------------------" << endl;
            cin >> choice;
            switch (choice){
            case 1:
            {
                hangmanPurchase();
                break;
            }
            case 2:
            {
                tictactoePurchase();
                break;
            }
            case 3:
            {
                minesweeperPurchase();
                break;
            }
            case 4:
            {
                connect4Purchase();
                break;
            }
            case 5:
            {
                cout << "-------------------------------------" << endl;
                cout << "| Invalid option, please choose 1-4 |" << endl;
                cout << "-------------------------------------" << endl;
            }
            }
        }
    }

    void requestRefill(){
       int money;
       int coins;

       cout << "-------------------------------------" << endl;
       cout << "   Welcome to coin refill Dungeon!  " << endl;
       cout << "You have been visited by the conversion Wizard\n" << endl;
       cout << " When inserting money, we will convert it \ninto coins (CC's)" << endl;
       cout << "\nHow much money do you want to convert?: " << endl;
       cin >> money;

        AlphaCoin = AlphaCoin + (money*0.75);

        cout << " \n**POOF MAGIC**\n " << endl;
        cout << "You now have " << AlphaCoin << "CC coins in the bank" << endl;
        cout << "Have fun playing, come back soon \n(I'm lonely in the dungeon by myself)" << endl;
        cout << "-------------------------------------" << endl;
        menuChoice();
    }

    void statusCheck(){
        cout << "-------------------------------------" << endl;
        cout << "You currently have: " << AlphaCoin << "CC coins" << endl;
        if(AlphaCoin < 5){
            cout << "Sorry, you dont have enough coins for any game." << endl;
            cout << "Visit the refill coins dungeon and talk to the wizard to get more coins!" << endl;
            cout << "-------------------------------------" << endl;
            menuChoice();
        }
        else if (AlphaCoin == 7){
            cout << "\nYou have enough coins to play hangman, minesweeper, and tic tac toe."<< endl;
            cout << "If you want more coins visit the refill coins dungeon!" << endl;
            cout << "-------------------------------------" << endl;
            menuChoice();
        }
        else if (AlphaCoin >= 5 && AlphaCoin <= 6){
            cout << "\nYou have enough coins to play hangman and minesweeper." << endl;
            cout << "If you want more coins visit the refill coins dungeon!" << endl;
            cout << "-------------------------------------" << endl;
            menuChoice();
        }
        else{
            cout << "\nYou have enough coins to play any game. Have Fun!" << endl;
            cout << "-------------------------------------" << endl;
            menuChoice();
        }
    }

    void menuChoice(){
        while (1)
        {
            int choice;
            cout << "|       ---------------------       |" << endl;
            cout << "|        1) Play a game             |" << endl;
            cout << "|        2) Refill coins            |" << endl;
            cout << "|        3) Check coin status       |" << endl;
            cout << "|        4) Exit the machine        |" << endl;
            cout << "-------------------------------------" << endl;
            cin >> choice;
            switch (choice)
            {
            case 1:
            {
                gameChoice();
                break;
            }
            case 2:
            {
                requestRefill();
                break;
            }
            case 3:
            {
                statusCheck();
                break;
            }
            case 4:
            {
                cout << "-------------------------------------" << endl;
                cout << "| Thank you for using this Machine! |" << endl;
                cout << "|         Have a nice day!          |" << endl;
                cout << "|                                   |" << endl;
                cout << "|           Written by:             |" << endl;
                cout << "|         ----------------          |" << endl;
                cout << "|          Eli Shtindler            |" << endl;
                cout << "|          Vitek Sabath             |" << endl;
                cout << "|          Omar Elkhafif            |" << endl;
                cout << "|         Atharva Shaligram         |" << endl;
                cout << "-------------------------------------" << endl;
                cout << "\n\n"
                     << endl;
                exit(1);
                break;
            }
            case 5:
            {
                cout << "-------------------------------------" << endl;
                cout << "| Invalid option, please choose 1-4 |" << endl;
                cout << "-------------------------------------" << endl;
                break;
            }
            }
        }
    }
};

int main()
{
    ArcadeMachine Mukund;
    float money;

    cout << "-------------------------------------" << endl;
    cout << "|    WELCOME TO THE AVOE ARCADE!    |" << endl;
    cout << "|      Select something below:      |" << endl;

    Mukund.menuChoice();

    return (0);
}
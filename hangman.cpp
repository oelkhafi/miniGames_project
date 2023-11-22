// Hangman Game
#include <iostream>
#include <string>
#include <fstream>
#include <random>

using namespace std;
// Define the wordbank file
const string WORDBANK = "wordbank.txt";

// Function Prototypes
void display(int lives);
string getRandWord();

int main()
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
    return 0;
}

// Function Definitions
// Display the hangman based on the number of lives
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

// Get a random word from the wordbank
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
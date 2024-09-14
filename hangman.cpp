#include <iostream>
#include <string>
using namespace std;

int main() {
    int wr = 0;
    string word;
    char letter;
    char empty[5] = { '_', '_', '_', '_', '_' };
    char wrong[5] = { '_', '_', '_', '_', '_' };
    bool correctGuess;

    cout << "This is a Hang Man game!!\nRules:\n1. Player 1 enters a 5 letter word.\n2. Player 2 has to guess the letters of the word one-by-one.\n3. Player 2 has three chances.\n4. When the fourth guess letter is wrong, the man will be fully hung and the game is over\nEnjoy!\n" << endl;

    cout << "Player 1 enters a 5 letter word:" << endl;
    cin >> word;

    if (word.length() != 5) {
        cout << "Error! Please enter a 5 letter word!" << endl;
        exit(0);
    }

    while (wr < 5 && (empty[0] == '_' || empty[1] == '_' || empty[2] == '_' || empty[3] == '_' || empty[4] == '_')) {
        // Display Hangman 
        if (wr == 0) {
            cout << "|________\n|\n|\n|\n|\n|--------" << endl;
        }
        else if (wr == 1) {
            cout << "|________\n|      |\n|\n|\n|\n|--------" << endl;
        }
        else if (wr == 2) {
            cout << "|________\n|      |\n|      0\n|\n|\n--------" << endl;
        }
        else if (wr == 3) {
            cout << "|________\n|      |\n|      0\n|     /|\\\n|\n|--------" << endl;
        }
        else if (wr == 4) {
            cout << "|________\n|      |\n|      0\n|     /|\\\n|     / \\ \n|\n--------\nGAME IS OVER!!!!!" << endl;
            break;
        }

        // Display guessed letters
        cout << "Correct letters: ";
        for (char c : empty) cout << c << ' ';
        cout << endl;

        cout << "Wrong letters: ";
        for (char c : wrong) cout << c << ' ';
        cout << endl;

        cout << "\nEnter a letter:" << endl;
        cin >> letter;

        correctGuess = false;
        for (int i = 0; i < word.length(); i++) {
            if (letter == word[i]) {
                empty[i] = letter;
                word[i] = '_';  // Mark this letter as guessed
                correctGuess = true;
            }
        }

        if (!correctGuess) {
            if (wr < 5) {
                wrong[wr] = letter;
                wr++;
            }
        }
    }

    if (empty[0] != '_' && empty[1] != '_' && empty[2] != '_' && empty[3] != '_' && empty[4] != '_') {
        cout << "Congratulations! You've guessed the word: ";
        for (char c : empty) cout << c;
        cout << endl;
    }
    else {
        cout << "Game over! The correct word was: ";
        for (char c : empty) cout << c;
        cout << endl;
    }

    return 0;
}

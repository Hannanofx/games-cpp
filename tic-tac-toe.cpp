#include <iostream>
#include <string>
using namespace std;

void printBoard(const char pos[9]) {
    cout << "  " << pos[0] << " | " << pos[1] << " | " << pos[2] << "\n";
    cout << "  -----------\n";
    cout << "  " << pos[3] << " | " << pos[4] << " | " << pos[5] << "\n";
    cout << "  -----------\n";
    cout << "  " << pos[6] << " | " << pos[7] << " | " << pos[8] << endl;
}

bool checkWin(const char pos[9], char player) {
    // Check rows, columns, and diagonals
    return (pos[0] == player && pos[1] == player && pos[2] == player) || // Row 1
           (pos[3] == player && pos[4] == player && pos[5] == player) || // Row 2
           (pos[6] == player && pos[7] == player && pos[8] == player) || // Row 3
           (pos[0] == player && pos[3] == player && pos[6] == player) || // Column 1
           (pos[1] == player && pos[4] == player && pos[7] == player) || // Column 2
           (pos[2] == player && pos[5] == player && pos[8] == player) || // Column 3
           (pos[0] == player && pos[4] == player && pos[8] == player) || // Diagonal \
           (pos[2] == player && pos[4] == player && pos[6] == player);   // Diagonal /
}

bool isBoardFull(const char pos[9]) {
    for (int i = 0; i < 9; i++) {
        if (pos[i] == ' ') {
            return false;
        }
    }
    return true;
}

int main() {
    string a, b;
    int position;
    char pos[9] = { ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
    
    cout << "THIS IS A TIC-TAC-TOE GAME.\nInstruction:\n1. Player will enter the position. The sign of the player will be entered on the position.\nENJOY!!" << endl;
    cout << "Enter player one name:" << endl;
    cin >> a;
    cout << "Enter player two name:" << endl;
    cin >> b;
    cout << "  1 | 2 | 3 \n -----------\n  4 | 5 | 6\n -----------\n  7 | 8 | 9\n\n Remember these positions." << endl;

    cout << "Player one assigned sign: o\nPlayer two assigned sign: x" << endl;

    for (int turn = 0; turn < 9; turn++) {
        char currentPlayer = (turn % 2 == 0) ? 'o' : 'x';
        string currentPlayerName = (turn % 2 == 0) ? a : b;

        printBoard(pos);
        cout << currentPlayerName << "'s turn (Player " << currentPlayer << ")\nEnter position (1-9):" << endl;
        cin >> position;

        while (position < 1 || position > 9 || pos[position - 1] != ' ') {
            cout << "Invalid position. Enter again:" << endl;
            cin >> position;
        }

        pos[position - 1] = currentPlayer;

        if (checkWin(pos, currentPlayer)) {
            printBoard(pos);
            cout << "Congratulations!! Player " << currentPlayerName << " won!" << endl;
            return 0;
        }

        if (isBoardFull(pos)) {
            printBoard(pos);
            cout << "It's a draw!" << endl;
            return 0;
        }
    }

    return 0;
}

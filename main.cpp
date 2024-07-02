#include <iostream>
#include <vector>

using namespace std;

const int SIZE = 3;
vector<vector<char> > board(SIZE, vector<char>(SIZE, ' '));
void printBoard() {
    cout << "  0 1 2" << endl;
    for (int i = 0; i < SIZE; ++i) {
        cout << i << " ";
        for (int j = 0; j < SIZE; ++j) {
            cout << board[i][j];
            if (j < SIZE - 1) cout << "|";
        }
        cout << endl;
        if (i < SIZE - 1) cout << "  -----" << endl;
    }
}
bool isWin(char player) {
    // Check rows and columns
    for (int i = 0; i < SIZE; ++i) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player)
            return true;
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player)
            return true;
    }
    // Check diagonals
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player)
        return true;
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player)
        return true;
    return false;
}
bool isDraw() {
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            if (board[i][j] == ' ') return false;
        }
    }
    return true;
}
void playGame() {
    char currentPlayer = 'X';
    while (true) {
        printBoard();
        int row, col;
        cout << "Player " << currentPlayer << ", enter your move (row and column): ";
        cin >> row >> col;

        if (row < 0 || row >= SIZE || col < 0 || col >= SIZE || board[row][col] != ' ') {
            cout << "This move is not valid. Try again." << endl;
            continue;
        }

        board[row][col] = currentPlayer;
        if (isWin(currentPlayer)) {
            printBoard();
            cout << "Player " << currentPlayer << " wins!" << endl;
            break;
        }
        if (isDraw()) {
            printBoard();
            cout << "The game is a draw!" << endl;
            break;
        }
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }
}
int main() {
    cout << "Hey Backbenchers Welcome to the world of Tic Tac Toe!" << endl;
    playGame();
    return 0;
}

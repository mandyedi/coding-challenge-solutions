/*
Title: TicTacToe
Tags: easy, conditions, simulation, 2D array, string manipulation
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool isWinningMove(const string &line, int &index) {
    if (line[0] == '.' && line[1] == 'O' && line[2] == 'O') {
        index = 0;
        return true;
    }
    else if (line[0] == 'O' && line[1] == '.' && line[2] == 'O') {
        index = 1;
        return true;
    }
    else if (line[0] == 'O' && line[1] == 'O' && line[2] == '.') {
        index = 2;
        return true;
    }
    else {
        index = 0;
        return false;
    }
}

int main()
{
    string board[3];
    for (int i = 0; i < 3; i++) {
        string line;
        getline(cin, line);
        board[i] = line;
    }

    int index = 0;
    bool win = true;
    // Horizontal
    if (isWinningMove(board[0], index)) {
        board[0][index] = 'O';
    }
    else if (isWinningMove(board[1], index)) {
        board[1][index] = 'O';
    }
    else if (isWinningMove(board[2], index)) {
        board[2][index] = 'O';
    }
    // Vertical
    else if (isWinningMove({board[0][0], board[1][0], board[2][0]}, index)) {
        board[index][0] = 'O';
    }
    else if (isWinningMove({board[0][1], board[1][1], board[2][1]}, index)) {
        board[index][1] = 'O';
    }
    else if (isWinningMove({board[0][2], board[1][2], board[2][2]}, index)) {
        board[index][2] = 'O';
    }
    // Diagonal
    else if (isWinningMove({board[0][0], board[1][1], board[2][2]}, index)) {
        board[index][index] = 'O';
    }
    else if (isWinningMove({board[0][2], board[1][1], board[2][0]}, index)) {
        board[index][2 - index] = 'O';
    }
    else {
        win = false;
    }

    if (win) {
        cout << board[0] << endl;
        cout << board[1] << endl;
        cout << board[2] << endl;
    }
    else {
        cout << "false\n";
    }
}

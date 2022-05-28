/*
Title: Mountain Map
Tags: easy, ascii art
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n; // the number of mountains
    cin >> n; cin.ignore();
    vector<int> heights;
    int boardWidth = 0;
    int boardHeight = 0;
    for (int i = 0; i < n; i++) {
        int height; // height of the mountain
        cin >> height; cin.ignore();
        heights.push_back(height);
        boardWidth += height * 2;
        if (height > boardHeight) {
            boardHeight = height;
        }
    }

    cerr << "width: " << boardWidth << " height: " << boardHeight << endl;

    string **board = new string*[boardHeight];
    for(int i = 0; i < boardHeight; ++i) {
        board[i] = new string[boardWidth];
    }

    for (int i = 0; i < boardHeight; i++) {
        for (int j = 0; j < boardWidth; j++) {
            board[i][j] = ' ';
        }
    }

    int posRow = boardHeight - 1;
    int posCol = 0;
    for (int height : heights) {
        cerr << "posRow: " << posRow << " posCol: " << posCol << endl;
        // Uphill
        for (int j = 0; j < height; j++) {
            board[posRow][posCol] = '/';
            posRow--;
            posCol++;
        }
        posRow++;
        // Downhill
        for (int j = 0; j < height; j++) {
            board[posRow][posCol] = '\\';
            posRow++;
            posCol++;
        }
        posRow--;
    }

    for (int i = 0; i < boardHeight; i++) {
        for (int j = boardWidth - 1; j >= 0; j--) {
            if (board[i][j] == "\\") {
                if (j != boardWidth - 1) {
                    board[i][j+1] = "-";
                }
                break;
            }
        }
    }

    // for (int i = 0; i < boardHeight; i++) {
    //     for (int j = 0; j < boardWidth; j++) {
    //         cerr << board[i][j];
    //     }
    //     cerr << endl;
    // }

    for (int i = 0; i < boardHeight; i++) {
        for (int j = 0; j < boardWidth; j++) {
            if (board[i][j] == "-") {
                break;
            }
            cout << board[i][j];
        }
        cout << endl;
    }
}

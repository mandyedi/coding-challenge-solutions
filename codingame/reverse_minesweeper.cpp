/*
Title: Reverse Minesweeper
Tags: easy, 2D array
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

unsigned int getNumberOfMines(const vector<string> &grid, int width, int height, int row, int col) {
    unsigned int mines = 0;
    for (int r = row - 1; r <= row + 1; r++) {
        for (int c = col - 1; c <= col + 1; c++) {
            if (r < 0 || r >= height || c < 0 || c >= width) {
                continue;
            }
            if (grid[r][c] == 'x' && !(r == row && c == col)) {
                mines++;
            }
        }
    }
    return mines;
}

void printGrid(const vector<string> &grid, int width, int height) {
    for (int row = 0; row < height; row++) {
        for (int coll = 0; coll < width; coll++) {
            cout << grid[row][coll];
        }
        if (row + 1 < height) {
            cout << endl;
        }
    }
}

int main()
{
    int w;
    cin >> w; cin.ignore();
    int h;
    cin >> h; cin.ignore();
    vector<string> grid;
    for (int i = 0; i < h; i++) {
        string line;
        getline(cin, line);
        grid.push_back(line);
    }

    for (int row = 0; row < h; row++) {
        for (int col = 0; col < w; col++) {
            if (grid[row][col] == '.') {
                unsigned int mines = getNumberOfMines(grid, w, h, row, col);
                if (mines == 0) {
                    grid[row][col] = '.';
                }
                else {
                    grid[row][col] = '0'+mines;
                }
            }
        }
    }

    for (int row = 0; row < h; row++) {
        for (int col = 0; col < w; col++) {
            if (grid[row][col] == 'x') {
                grid[row][col] = '.';
            }
        }
    }

    printGrid(grid, w, h);
}

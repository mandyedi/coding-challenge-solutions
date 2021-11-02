/*
Title: Custom Game of Life
Tags: easy, conditions, loops, lists, simulation, 2D array
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool isAlive(char cell, const string &ruleAlive, const string &ruleDead, unsigned int numberOfNeighbours) {
    if (cell == 'O') {
        return ruleAlive[numberOfNeighbours] == '1';
    }
    else {
        return ruleDead[numberOfNeighbours] == '1';
    }
}

unsigned int getNumberOfNeighbours(const vector<string> &grid, int width, int height, int row, int coll) {
    unsigned int neighbours = 0;
    for (int r = row - 1; r <= row + 1; r++) {
        for (int c = coll - 1; c <= coll + 1; c++) {
            if (r < 0 || r >= height || c < 0 || c >= width) {
                continue;
            }
            if (grid[r][c] == 'O' && !(r == row && c == coll)) {
                neighbours++;
            }
        }
    }
    return neighbours;
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
    int h;
    int w;
    int n;
    cin >> h >> w >> n; cin.ignore();
    string alive;
    getline(cin, alive);
    string dead;
    getline(cin, dead);
    vector<string> currentGrid;
    vector<string> nextGrid;
    for (int i = 0; i < h; i++) {
        string line;
        getline(cin, line);
        currentGrid.push_back(line);
        nextGrid.push_back(line);
    }

        for (int i = 0; i < n; i++) {
        for (int row = 0; row < h; row++) {
            for (int coll = 0; coll < w; coll++) {
                unsigned int n = getNumberOfNeighbours(currentGrid, w, h, row, coll);
                nextGrid[row][coll] = isAlive(currentGrid[row][coll], alive, dead, n) ? 'O' : '.';
            }
        }

        currentGrid.swap(nextGrid);
    }

    printGrid(currentGrid, w, h);
}

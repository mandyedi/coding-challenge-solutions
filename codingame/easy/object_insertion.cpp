/*
Title: Object Insertion
Tags: easy, loops, 2d array 
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int row_object;
    int col_object;
    cin >> row_object >> col_object; cin.ignore();
    vector<string> object;
    for (int i = 0; i < row_object; i++) {
        string object_line;
        getline(cin, object_line);
        object.push_back(object_line);
    }
    int row_grid;
    int col_grid;
    cin >> row_grid >> col_grid; cin.ignore();
    vector<string> grid;
    for (int i = 0; i < row_grid; i++) {
        string grid_line;
        getline(cin, grid_line);
        grid.push_back(grid_line);
    }

    unsigned int numberOfFit = 0;
    for (int row = 0; row <= row_grid - row_object; row++ ) {
        for (int col = 0; col <= col_grid - col_object; col++ ) {
            bool fit = true;
            for (int r = 0; r < row_object; r++) {
                for (int c = 0; c < col_object; c++) {
                    if (object[r][c] == '*' && grid[row+r][col+c] == '#') {
                        fit = false;
                        break;
                    }
                }
                if (!fit) {
                    break;
                }
            }

            if (fit) {
                numberOfFit++;
                for (int r = 0; r < row_object; r++) {
                    for (int c = 0; c < col_object; c++) {
                        if (grid[row+r][col+c] == '.') {
                            grid[row+r][col+c] = object[r][c];
                        }
                    }
                }
            }
        }
    }

    cout << numberOfFit << endl;
    if (numberOfFit == 1) {
        for (int row = 0; row < row_grid; row++ ) {
            for (int col = 0; col < col_grid; col++ ) {
                cout << grid[row][col];
            }
            cout << endl;
        }
    }
}

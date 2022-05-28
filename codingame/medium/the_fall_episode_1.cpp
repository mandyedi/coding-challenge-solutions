/*
Title: The Fall - Episode 1
Tags: medium, conditions
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

void GetTokens( const std::string &line, std::vector<int> &tokens )
{
    tokens.clear();
    std::stringstream lineStream( line );
    std::string token;
    while ( std::getline( lineStream, token, ' ' ) )
    {
        tokens.push_back( stoi( token ) );
    }
}

int main()
{
    int w; // number of columns.
    int h; // number of rows.
    cin >> w >> h; cin.ignore();
    vector<vector<int>> grid;
    for (int i = 0; i < h; i++) {
        string line;
        getline(cin, line); // represents a line in the grid and contains W integers. Each integer represents one room of a given type.
        // cerr << line << endl;
        vector<int> numbers;
        GetTokens(line, numbers);
        grid.push_back(numbers);
    }
    int ex; // the coordinate along the X axis of the exit (not useful for this first mission, but must be read).
    cin >> ex; cin.ignore();
    cerr << "ex: " << ex << endl;

    for (auto &line : grid) {
        for (int i : line) {
            cerr << i << " ";
        }
        cerr << endl;
    }

    // game loop
    int prevx = 0;
    int prevy = 0;
    while (1) {
        int xi;
        int yi;
        string pos;
        cin >> xi >> yi >> pos; cin.ignore();
        cerr << xi << " " << yi << " " << pos << endl;
        cerr << "grid[xi][yi]: " << grid[yi][xi] << endl;

        switch(grid[yi][xi]) {
            case 1:
            case 3:
            case 7:
            case 8:
            case 9:
                cout << xi << " " << yi + 1 << endl;
                break;
            case 2:
            case 6:
                if (xi > prevx) {
                    cout << xi + 1 << " " << yi << endl;
                }
                else {
                    cout << xi - 1 << " " << yi << endl;
                }
                break;
            case 4:
                if (xi < prevx) {
                    cout << xi << " " << yi + 1 << endl;
                }
                else {
                    cout << xi - 1 << " " << yi << endl;
                }
                break;
            case 5:
                if (xi > prevx) {
                    cout << xi << " " << yi + 1 << endl;
                }
                else {
                    cout << xi + 1 << " " << yi << endl;
                }
                break;
            case 10:
                cout << xi - 1 << " " << yi << endl;
                break;
            case 11:
                cout << xi + 1 << " " << yi << endl;
                break;
            case 12:
                cout << xi << " " << yi + 1 << endl;
                break;
            case 13:
                cout << xi << " " << yi + 1 << endl;
                break;
        };

        prevx = xi;
        prevy = yi;
    }
}

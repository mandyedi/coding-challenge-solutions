/*
Title: There Is No Spoon - Episode 1
Tags: medium, lists
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

/**
 * Don't let the machines win. You are humanity's last hope...
 **/
int main()
{
    int width; // the number of cells on the X axis
    cin >> width; cin.ignore();
    int height; // the number of cells on the Y axis
    cin >> height; cin.ignore();
    string grid[height][width];
    for (int i = 0; i < height; i++) {
        string line; // width characters, each either 0 or .
        getline(cin, line);
        for ( int j = 0; j < width; j++ ) {
            grid[i][j] = line[j];
        }
    }

    // Print grid
    // for (int i = 0; i < height; i++) {
    //     for ( int j = 0; j < width; j++ ) {
    //         cerr << grid[i][j] << " ";
    //     }
    //     cerr << endl;
    // }

    // Write an action using cout. DON'T FORGET THE "<< endl"
    // To debug: cerr << "Debug messages..." << endl;

    for (int i = 0; i < height; i++) {
        for ( int j = 0; j < width; j++ ) {
            std::ostringstream output;
            if ( grid[i][j] == "0" ) {
                output << j << " " << i << " ";

                // Check right
                if ( j == width - 1 ) {
                    output << "-1 -1 ";
                } else {
                    // Find nodes on the right
                    bool found = false;
                    for ( int k = j + 1; k < width; k++ ) {
                        if ( grid[i][k] == "0" ) {
                            found = true;
                            output << k << " " << i << " ";
                            break;
                        }
                    }

                    if ( !found ) {
                        output << "-1 -1 ";
                    }
                }

                // Check bottom
                if ( i == height - 1 ) {
                    output << "-1 -1 ";
                } else {
                    // Find nodes on the bottom
                    bool found = false;
                    for ( int k = i + 1; k < height; k++ ) {
                        if ( grid[k][j] == "0" ) {
                            found = true;
                            output << j << " " << k << " ";
                            break;
                        }
                    }

                    if ( !found ) {
                        output << "-1 -1 ";
                    }
                }

                // if ( i == height - 1 ) {
                //     output << "-1 -1 ";
                // } else if ( grid[i+1][j] == "0" ) {
                //     output << j << " " << i+1;
                // } else {
                //     output << "-1 -1 ";
                // }

                cout << output.str() << endl;
            }
        }
    }

    // cout << "0 0 1 0 0 1" << endl; // Three coordinates: a node, its right neighbor, its bottom neighbor
    // cout << "1 0 -1 -1 -1 -1" << endl;
    // cout << "0 1 -1 -1 -1 -1" << endl;
}

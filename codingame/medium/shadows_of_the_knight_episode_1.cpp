/*
Title: Shadows of the Jnight - Episode 1
Tags: medium, binary search, intervals
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int w; // width of the building.
    int h; // height of the building.
    cin >> w >> h; cin.ignore();
    int n; // maximum number of turns before game over.
    cin >> n; cin.ignore();
    int x;
    int y;
    cin >> x >> y; cin.ignore();

    int minx = 0, maxx = w - 1;
    int miny = 0, maxy = h - 1;

    // game loop
    while (1) {
        string bomb_dir; // the direction of the bombs from batman's current location (U, UR, R, DR, D, DL, L or UL)
        cin >> bomb_dir; cin.ignore();

        if (bomb_dir.find("L") != string::npos) {
            maxx = x - 1;
        }
        else if (bomb_dir.find("R") != string::npos) {
            minx = x + 1;
        }

        if (bomb_dir.find("D") != string::npos) {
            miny = y + 1;
        }
        else if (bomb_dir.find("U") != string::npos) {
            maxy = y - 1;
        }

        x = minx + (maxx - minx) / 2;
        y = miny + (maxy - miny) / 2;

        cout << x << " " << y << endl;
    }
}

/*
Title: Dungeons and Maps
Tags: easy, strings, pathfinding, loops, 2D array
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

const char UP = '^';
const char DOWN = 'v';
const char LEFT = '<';
const char RIGHT = '>';

class Vec2 {
public:
    Vec2() : x(0), y(0) {}
    Vec2(int x, int y) : x(x), y(y) {}

    int x, y;
};

void getNextPosition(const Vec2 &currentPosition, char currentDirection, Vec2 &nextPosition) {
    nextPosition = currentPosition;
    switch (currentDirection) {
        case UP:
            nextPosition.y = currentPosition.y - 1;
            break;
        case DOWN:
            nextPosition.y = currentPosition.y + 1;
            break;
        case LEFT:
            nextPosition.x = currentPosition.x - 1;
            break;
        case RIGHT:
            nextPosition.x = currentPosition.x + 1;
            break;
    }
}

int main()
{
    int w;
    int h;
    cin >> w >> h; cin.ignore();
    int start_row;
    int start_col;
    cin >> start_row >> start_col; cin.ignore();
    int n;
    cin >> n; cin.ignore();
    vector<vector<string>> maps;
    for (int i = 0; i < n; i++) {
        vector<string> map;
        for (int j = 0; j < h; j++) {
            string map_row;
            getline(cin, map_row);
            map.push_back(map_row);
        }
        maps.push_back(map);
    }

    // cerr << "start: " << start_col << " " << start_row << endl;
    // for (int i = 0; i < n; i++) {
    //     cerr << i << endl;
    //     for (int j = 0; j < h; j++) {
    //         cerr << maps[i][j] << endl;
    //     }
    // }

    int minSteps = numeric_limits<int>::max();
    int minMapIndex = -1;
    for( int i = 0; i < n; i++) {
        cerr << "map: " << i << endl;
        bool run = true;
        Vec2 currentPosition(start_col, start_row);
        char currentDirection = maps[i][start_row][start_col];
        int steps = 0;
        while (run) {
            steps++;

            char currentChar = maps[i][currentPosition.y][currentPosition.x];
            // cerr << "current char: " << currentChar << endl;

            if (currentChar == '.' || (steps > 1 && currentPosition.x == start_col && currentPosition.y == start_row)) {
                run = false;
            }
            else if (currentChar == 'T') {
                // cerr << "found T, steps: " << steps << ", minSteps: " << minSteps << endl;
                if (steps < minSteps) {
                    minSteps = steps;
                    minMapIndex = i;
                }
                run = false;
            }
            else {
                Vec2 nextPosition;
                getNextPosition(currentPosition, currentChar, nextPosition);
                //cerr << "next position: " << nextPosition.x << " " << nextPosition.y << endl;
                if (nextPosition.x < 0 || nextPosition.x >= w || nextPosition.y < 0 || nextPosition.y >= h) {
                    run = false;
                }
                else {
                    currentPosition = nextPosition;
                }
            }
        };
    }

    if (minMapIndex == -1) {
        cout << "TRAP";
    }
    else {
        cout << minMapIndex << endl;
    }
}

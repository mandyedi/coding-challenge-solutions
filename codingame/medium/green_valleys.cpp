/*
Title: Green Valley
Tags: medium, 2D array, recursion
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Area {
public:
    Area() = default;
    Area(int value, bool visited) : Value(value), Visited(visited) {}
    int Value = 0;
    bool Visited = false;
};

class Valley {
public:
    Valley() = default;
    Valley(int count, int deepest) : Count(count), Deepest(deepest) {}
    int Count = 0;
    int Deepest = 0;
};

int h = 0;
int n = 0;
vector<vector<Area>> map;
Valley resultValley(0,0);

void solveValley(int i, int j, Valley &valley) {
    if (i < 0 || j < 0 || i >= n || j >= n) {
        return;
    }
    if (map[i][j].Visited == false) {
        map[i][j].Visited = true;
        if (map[i][j].Value <= h) {
            valley.Count++;
            valley.Deepest = min(valley.Deepest, map[i][j].Value);
            solveValley(i-1, j, valley);
            solveValley(i, j+1, valley);
            solveValley(i+1, j, valley);
            solveValley(i, j-1, valley);
        }
    }
}

int main()
{
    cin >> h; cin.ignore();
    cin >> n; cin.ignore();

    for (int i = 0; i < n; i++) {
        vector<Area> line;
        for (int j = 0; j < n; j++) {
            int h;
            cin >> h; cin.ignore();
            line.push_back(Area(h, false));
        }
        map.push_back(line);
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (map[i][j].Visited == false && map[i][j].Value <= h) {
                Valley currentValley(0, h);
                solveValley(i, j, currentValley);

                if (currentValley.Count > resultValley.Count) {
                    resultValley = currentValley;
                }
                else if (currentValley.Count == resultValley.Count) {
                    if (currentValley.Deepest < resultValley.Deepest) {
                        resultValley.Deepest = currentValley.Deepest;
                    }
                }
            }
        }
    }

    cout << resultValley.Deepest << endl;
}

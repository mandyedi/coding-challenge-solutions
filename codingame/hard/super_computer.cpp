/*
Title: Super Computer
Tags: hard, greedy algorithms, scheduling
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

typedef pair<int, int> P;

struct comp
{
    template<typename T>
    bool operator()(const T &l, const T &r) const
    {
        if (l.second == r.second) {
            return l.first < r.first;
        }
        return l.second < r.second;
    }
};

int main()
{
    int n;
    cin >> n; cin.ignore();

    set<P, comp> intervals;

    for (int i = 0; i < n; i++) {
        int j;
        int d;
        cin >> j >> d; cin.ignore();
        intervals.insert({j, j+d-1});
    }

    int count = 0;
    int lastSecond = 0;
    for (auto &interval : intervals) {
        if (interval.first > lastSecond) {
            count++;
            lastSecond = interval.second;
        }
    }

    cout << count << endl;
}

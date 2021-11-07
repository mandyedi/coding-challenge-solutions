/*
Title: Robot Show
Tags: easy
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int l;
    cin >> l; cin.ignore();
    int n;
    cin >> n; cin.ignore();
    int min = numeric_limits<int>::max();
    int max = 0;
    for (int i = 0; i < n; i++) {
        int b;
        cin >> b; cin.ignore();
        if (b < min) {
            min = b;
        }
        if (b > max) {
            max = b;
        }
    }

    int max_distance = l - max;
    cout << (min < max_distance ? (l - min) : max) << endl;
}

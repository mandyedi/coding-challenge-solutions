/*
Title: The Gift
Tags: medium, greedy algorithms
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    vector<int> budgets;
    int sum = 0;

    int n;
    cin >> n; cin.ignore();
    int c;
    cin >> c; cin.ignore();
    for (int i = 0; i < n; i++) {
        int b;
        cin >> b; cin.ignore();
        budgets.push_back(b);
        sum += b;
    }

    if (sum < c) {
        cout << "IMPOSSIBLE";
    }
    else {
        sort(budgets.begin(), budgets.end());

        for(int i = 0; i < n; i++) {
            int contribution = c / (n - i);
            contribution = min(contribution, budgets[i]);
            cout << contribution << endl;
            c -= contribution;
        }
    }
}

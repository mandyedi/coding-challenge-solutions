/*
Title: Happy Numbers
Tags: loops, data types
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long int GetSum(const string s) {
    long long int sum = 0;
    for( char c : s) {
        long long int x = c - '0';
        sum += x * x;
    }
    return sum;
}

int main()
{
    int n;
    cin >> n; cin.ignore();
    for (int i = 0; i < n; i++) {
        string s;
        getline(cin, s);

        long long int sum = GetSum(s);
        bool happy = false;
        for (int i = 0; i < 20; i++) {
            if (sum == 1) {
                happy = true;
                break;
            }
            else if (sum == 4) {
                break;
            }
            else {
                sum = GetSum(to_string(sum));
            }
        }

        if (happy) {
            cout << s << " :)\n";
        }
        else {
            cout << s << " :(\n";
        }
    }
}

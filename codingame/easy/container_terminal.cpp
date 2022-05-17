/*
Title: Container Terminal
Tags: easy, stack
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

int main()
{
    int n;
    cin >> n; cin.ignore();
    for (int i = 0; i < n; i++) {
        string line;
        getline(cin, line);

        vector<stack<char>> stacks;

        for( char c : line) {
            bool pushed = false;
            
            for (auto &s : stacks) {
                if (s.top() >= c) {
                    s.push(c);
                    pushed = true;
                    break;
                }
            }

            if (stacks.empty() || pushed == false) {
                stack<char> s;
                s.push(c);
                stacks.push_back(s);
            }
        }

        cout << stacks.size() << "\n";
    }
}

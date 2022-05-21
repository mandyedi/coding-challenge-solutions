/*
Title: Revers Polish Notation
Tags: stack, revers polish notation, interpreters
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

bool GetOperands(vector<int> &s, int &a, int &b) {
    if (s.size() >= 2) {
        b = s.back();
        s.pop_back();
        a = s.back();
        s.pop_back();
        return false;
    }
    else if (s.size() == 1) {
        s.pop_back();
        return true;
    }
    return true;
}

void PrintStack(vector<int> &s) {
    for (int i = 0; i < s.size(); i++) {
        cout << s[i];
        if (i < s.size() - 1) {
            cout << " ";
        }
    }
}

int main()
{
    vector<int> s;
    bool error = false;

    int n;
    cin >> n; cin.ignore();
    for (int i = 0; i < n; i++) {

    // int n = 5;
    // vector<string> strings = {"23","42","36","0","DIV"};
    // for( int i = 0; i < n; i++ ) {
        string instruction;
        cin >> instruction; cin.ignore();
        // instruction = strings[i];

        error = false;
        int a, b;
        if (instruction == "ADD") {
            error = GetOperands(s, a, b);
            if (!error) {
                s.push_back(a + b);
            }
        }
        else if (instruction == "SUB") {
            error = GetOperands(s, a, b);
            if (!error) {
                s.push_back(a - b);
            }
        }
        else if (instruction == "MUL") {
            error = GetOperands(s, a, b);
            if (!error) {
                s.push_back(a * b);
            }
        }
        else if (instruction == "DIV") {
            error = GetOperands(s, a, b);
            error = error || b == 0;
            if (!error) {
                s.push_back(a / b);
            }
        }
        else if (instruction == "MOD") {
            error = GetOperands(s, a, b);
            error = error || b == 0;
            if (!error) {
                s.push_back(a % b);
            }
        }
        else if (instruction == "POP") {
            if (s.size() == 0) {
                error = true;
            }
            else {
                s.pop_back();
            }
        }
        else if (instruction == "DUP") {
            if (s.size() == 0) {
                error = true;
            }
            else {
                s.push_back(s.back());
            }
        }
        else if (instruction == "SWP") {
            error = GetOperands(s, a, b);
            if (!error) {
                s.push_back(b);
                s.push_back(a);
            }
        }
        else if (instruction == "ROL") {
            if (s.size() == 0) {
                error = true;
            }
            else {
                int rol = s.back();
                if (rol <= s.size())
                {
                    s.pop_back();

                    stack<int> s2;
                    for (int j = 0; j < rol - 1; j++) {
                        s2.push(s.back());
                        s.pop_back();
                    }

                    int top = s.back();
                    s.pop_back();

                    while(!s2.empty()) {
                        s.push_back(s2.top());
                        s2.pop();
                    }

                    s.push_back(top);
                }
                else {
                    error = true;
                }
            }
        }
        else {
            s.push_back(stoi(instruction));
        }

        if (error) {
            PrintStack(s);
            if (s.size() > 0) {
                cout << " ";
            }
            cout << "ERROR\n";
            break;
        }
    }

    if (!error) {
        PrintStack(s);
    }
}

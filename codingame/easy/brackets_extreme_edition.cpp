/*
Title: Brackets, Extreme Edition
Tags: easy, stack
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

bool isValid(char currentBracket, char lastBracket) {
    if (currentBracket == ')' && lastBracket == '(') {
        return true;
    }
    if (currentBracket == ']' && lastBracket == '[') {
        return true;
    }
    if (currentBracket == '}' && lastBracket == '{') {
        return true;
    }
    return false;
}

int main()
{
    string expression;
    cin >> expression; cin.ignore();

    stack<char> s;

    bool valid = true;
    for (char bracket : expression) {
        if (bracket == '(' || bracket == '[' || bracket == '{') {
            s.push(bracket);
        }
        else if (bracket == ')' || bracket == ']' || bracket == '}') {
            if (s.size() > 0 && isValid(bracket, s.top())) {
                s.pop();
            }
            else {
                valid = false;
                break;
            }
        }
    }

    cout << ((valid && s.size() == 0) ? "true" : "false") << endl;
}

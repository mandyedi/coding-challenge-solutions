/*
Title: Micro Assembly
Tags: medium, stack, interpreters
*/

#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;


void GetTokens( const std::string &line, std::vector<string> &tokens )
{
    tokens.clear();
    std::stringstream lineStream( line );
    std::string token;
    while ( std::getline( lineStream, token, ' ' ) )
    {
        tokens.push_back( token );
    }
}

int a;
int b;
int c;
int d;

int GetValue(const string &s) {
    if (s == "a") {
        return a;
    } else if (s == "b") {
        return b;
    } else if (s == "c") {
        return c;
    } else if (s == "d") {
        return d;
    } else {
        return stoi(s);
    }
}

void SetValue(const string &s, int value) {
    if (s == "a") {
        a = value;
    } else if (s == "b") {
        b = value;
    } else if (s == "c") {
        c = value;
    } else if (s == "d") {
        d = value;
    }
}

int main()
{
    cin >> a >> b >> c >> d; cin.ignore();
    int n;
    cin >> n; cin.ignore();
    vector<vector<string>> instructions;
    for (int i = 0; i < n; i++) {
        string s;
        getline(cin, s);

        vector<string> instruction;
        GetTokens(s, instruction);
        instructions.push_back(instruction);
    }

    int i = 0;
    while (i < instructions.size()) {
        auto &instruction = instructions[i];

        if (instruction.size() == 3) {
            SetValue(instruction[1], GetValue(instruction[2]));
            i++;
        }
        else {
            if (instruction[0] == "ADD") {
                int x = GetValue(instruction[2]);
                int y = GetValue(instruction[3]);
                SetValue(instruction[1], x + y);
                i++;
            } else if (instruction[0] == "SUB") {
                int x = GetValue(instruction[2]);
                int y = GetValue(instruction[3]);
                SetValue(instruction[1], x - y);
                i++;
            } else if (instruction[0] == "JNE") {
                int x = GetValue(instruction[2]);
                int y = GetValue(instruction[3]);
                if (x != y) {
                    i = GetValue(instruction[1]);
                } else {
                    i++;
                }
            }
        }
    }

    cout << a << " " << b << " " << c << " " << d << endl;
}

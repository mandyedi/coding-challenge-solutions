/*
Title: Prefix code
Tags: easy, tries, string manipulation
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

int main()
{
    int n;
    cin >> n; cin.ignore();
    unordered_map<string, int> codeTable;
    for (int i = 0; i < n; i++) {
        string b;
        int c;
        cin >> b >> c; cin.ignore();
        codeTable[b] = c;
    }
    string s;
    cin >> s; cin.ignore();

    string output;
    int i = 0;
    while (i < s.size()) {
        bool valid = false;
        for (int j = 1; i+j <= s.size(); j++ ) {
            if (codeTable.find(s.substr(i, j)) != codeTable.end()) {
                valid = true;
                output += (char)codeTable[s.substr(i, j)];
                i = i + j;
            }
        }

        if (valid == false) {
            output = "DECODE FAIL AT INDEX " + to_string(i);
            break;
        }
    }

    cout << output << endl;
}

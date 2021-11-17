/*
Title: 7-segment scanner
Tags: easy, loops, conditions, string manipulation, ascii art
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

int main()
{
    string line_1;
    getline(cin, line_1);
    string line_2;
    getline(cin, line_2);
    string line_3;
    getline(cin, line_3);

    vector<string> numbers;

    for (int i = 0; i < line_1.size(); i += 3) {
        string number = line_1.substr(i, 3) + line_2.substr(i, 3) + line_3.substr(i, 3);
        numbers.push_back(number);
    }

    unordered_map<string, int> numberTable;
    numberTable[" _ | ||_|"] = 0;
    numberTable["     |  |"] = 1;
    numberTable[" _  _||_ "] = 2;
    numberTable[" _  _| _|"] = 3;
    numberTable["   |_|  |"] = 4;
    numberTable[" _ |_  _|"] = 5;
    numberTable[" _ |_ |_|"] = 6;
    numberTable[" _   |  |"] = 7;
    numberTable[" _ |_||_|"] = 8;
    numberTable[" _ |_| _|"] = 9;

    for (auto &number : numbers) {
        cout << numberTable[number];
    }

    cout << endl;
}

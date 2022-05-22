/*
Title: Logic Gates
Tags: easy, logic
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

char Gate(const string &type, char a, char b) {
    bool A = a == '-' ? true : false;
    bool B = b == '-' ? true : false;
    bool C = false;
    if (type == "AND") {
        C = A && B;
    }
    else if (type == "OR") {
        C = A || B;
    }
    else if (type == "XOR") {
        C = A != B;
    }
    else if (type == "NAND") {
        C = !(A && B);
    }
    else if (type == "NOR") {
        C = !(A || B);
    }
    else if (type == "NXOR") {
        C = !(A != B);
    }

    return C ? '-' : '_';
}

int main()
{
    int n;
    cin >> n; cin.ignore();
    int m;
    cin >> m; cin.ignore();


    unordered_map<string, string> inputs;

    for (int i = 0; i < n; i++) {
        string input_name;
        string input_signal;
        cin >> input_name >> input_signal; cin.ignore();
        inputs[move(input_name)] = move(input_signal);
    }
    for (int i = 0; i < m; i++) {
        string output_name;
        string type;
        string input_name_1;
        string input_name_2;
        cin >> output_name >> type >> input_name_1 >> input_name_2; cin.ignore();

        const string &input_a = inputs[input_name_1];
        const string &input_b = inputs[input_name_2];
        int length = input_a.size();
        cout << output_name << " ";
        for (int j = 0; j < length; j++) {
            char A = input_a[j];
            char B = input_b[j];
            char C = Gate(type, A, B);
            cout << C;
        }
        cout << endl;
    }
}

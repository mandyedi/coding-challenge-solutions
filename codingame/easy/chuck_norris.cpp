/*
Title: Chuck Norris
Tags: easy, conditions, loops, encoding, strings
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <bitset>

using namespace std;

int main()
{
    string MESSAGE;
    getline(cin, MESSAGE);

    cerr << MESSAGE << endl;

    int N = MESSAGE.length();
    string binString = "";
    for ( int i = 0; i < N; i++ ) {
        char c = MESSAGE[i];
        int dec = int(c);
        std::bitset<7> bin(dec);
        binString += bin.to_string();
    }

    cerr << binString << endl;

    string output = "";
    int length = binString.length();
    int posDigit = 0;
    while ( posDigit < length ) {
        if ( binString[posDigit] == '1' ) {
            output += "0 ";
        } else {
            output += "00 ";
        }

        int countBlock = 1;
        while ( posDigit < length && binString[posDigit] == binString[posDigit+1] ) {
            countBlock++;
            posDigit++;
        }

        for ( int j = 0; j < countBlock; j++ ) {
            output += "0";
        }
        output += " ";
        posDigit++;
    }

    output = output.substr(0, output.size()-1);
    cout << output << endl;
}

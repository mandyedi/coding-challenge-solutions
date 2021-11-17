/*
Title: Create the longest sequence of 1s
Tags: easy, string manipulation
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

void getLengths( const std::string &line, std::vector<int> &tokens )
{
    tokens.clear();
    std::stringstream lineStream( line );
    std::string token;
    while ( std::getline( lineStream, token, '0' ) )
    {
        int length = static_cast<int>(token.length() );
        tokens.push_back( length );
    }
}

int main()
{
    string b;
    getline(cin, b);
    cerr << b << endl;

    vector<int> lengths;
    getLengths(b, lengths);


    int longest = 0;
    if (lengths.size() == 0) {
        cout << "1" << endl;
    }
    else {
        for (int i = 0; i < lengths.size() - 1; i++) {
            if (lengths[i] + lengths[i+1] + 1 > longest) {
                longest = lengths[i] + lengths[i+1] + 1;
            }
        }
        cout << longest << endl;
    }
}

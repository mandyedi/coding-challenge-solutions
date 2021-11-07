/*
Title: Horse-Racing Duals
Tags: easy, loops
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main()
{
    int N;
    cin >> N; cin.ignore();
    vector<int> strengths;
    strengths.reserve( N );
    for (int i = 0; i < N; i++) {
        int Pi;
        cin >> Pi; cin.ignore();
        strengths.push_back( Pi );
    }

    sort( strengths.begin(), strengths.end() );
    int min = 100000000;
    for ( int i = 0; i < N-1; i++ ) {
        int diff = strengths[i+1] - strengths[i];
        if ( diff < min ) {
            min = diff;
        }
    }

    cout << min << endl;
}

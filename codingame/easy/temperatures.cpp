/*
Title: Temperatures
Tags: easy, conditions, loops, arrays
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main()
{
    int n; // the number of temperatures to analyse
    cin >> n; cin.ignore();
    string s;
    int closest = 10000;
    while ( getline( cin, s, ' ' ) ) {
        int temp = atoi( s.c_str() );
        if ( closest < 0 && temp > 0 && abs( closest ) == temp ) {
            closest = temp;
        } else if ( abs( temp ) < abs( closest ) ) {
            closest = temp;
        }
    }
    cout << closest << endl;
}

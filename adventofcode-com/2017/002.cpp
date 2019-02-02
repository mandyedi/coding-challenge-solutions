#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

int main(int argc, char **argv)
{
    ifstream infile( "002.txt" );
    string line;

    // vector< vector< int > > numbers;
    int numbers[16][16];
    int i = 0;
    
    while (std::getline(infile, line))
    {
        int j = 0;
        string buf;
        stringstream ss( line );
        // vector<int> tokens;

        while (ss >> buf)
        {
            int n = stoul( buf );
            numbers[i][j] = n;
            // tokens.push_back( n );
            j++;
        }

        // numbers.push_back( tokens );
        i++;
    }

    int sum = 0;

    for( int i = 0; i < 16; i++) {
        for( int j = 0; j < 16; j++) {
            for( int j2 = 0; j2 < 16; j2++) {
                if( j != j2 && numbers[i][j] % numbers[i][j2] == 0) {
                    sum += numbers[i][j] / numbers[i][j2];
                }
            }
        }
    }

    cout << sum;

    return 0;
}
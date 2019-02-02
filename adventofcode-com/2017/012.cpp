#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;


int main(int argc, char **argv)
{
    ifstream infile( "012.txt" );
    string line;
    set<int> programs;

    while (std::getline(infile, line))
    {
        string buf;
        stringstream ss( line );
        vector<int> tokens;

        while (ss >> buf)
        {
            tokens.push_back( stoi( buf ) );
        }

        if ( tokens[0] > 0 )
        {
            if ( find( tokens.begin(), tokens.end(), 0 ) != tokens.end() )
            {
                for ( int i = 1; i < tokens.size(); i++ )
                {
                    programs.insert( tokens[i] );
                }
            }
        }

    }

    cout << programs.size();

    return 0;
}
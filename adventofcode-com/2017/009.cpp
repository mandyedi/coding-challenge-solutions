#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(int argc, char **argv)
{
    // string s = "abc<sfsd>sfas";
    // return 0;
    
    ifstream infile( "009.txt" );
    string line;

    int numbers[16][16];
    int i = 0;
   
    std::getline(infile, line);
    infile.close();

    string::iterator it = line.begin();
    while ( it != line.end() )
    {
        char c = *it;
        if ( c == '!' )
        {
            it = line.erase( it );
            it = line.erase( it );
        }
        else
        {
            ++it;
        }
    }

    // ofstream outfile( "009_cancel.txt" );
    // outfile << line;
    // outfile.close();
    
    string::size_type pos = 0;
    int garbageCount = 0;
    while ( pos != string::npos )
    {
        pos = line.find( '<' );
        if ( pos != string::npos )
        {
            string::size_type pos2 = line.find( '>', pos );
            garbageCount += pos2 - pos - 1;
            line.erase( pos, pos2 - pos + 1 );
            pos = ++pos2;
        }
    }

    // ofstream outfile2( "009_garbage.txt" );
    // outfile2 << line;
    // outfile2.close();

    int score = 0;
    int sum = 0;
    for ( int i = 0; i < line.size(); i++ )
    {
        char c = line[i];
        if ( c == '{' )
        {
            score++;
            sum += score;
        }
        else if ( c == '}' )
        {
            score--;
        }
    }

    cout << sum << "\n";
    cout << garbageCount;

    return 0;
}
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

/*
    ""
    "abc"
    "aaa\"aaa"
    "\x27"


    \\

    23 - 11 = 12
*/

int NumberOfSpecials( const string &line, const string &spec )
{
    // cout << "    " << line << "    spec: " << spec << endl;
    int n = 0;
    size_t pos = 0;
    while ( ( pos = line.find( spec, pos ) ) != string::npos )
    {
        pos += spec.length();
        n++;
    }
    return n;
}

int main(int argc, char **argv)
{
    ifstream infile("008.txt");
    string line;
    int length = 0, totalLength = 0;

    while (std::getline(infile, line))
    {
        // cout << line << endl;
        length += line.length();
        totalLength += line.length() - 2;
        int n = 0;
        if ( ( n = NumberOfSpecials( line.substr( 1, line.length() - 2), "\\\"" ) ) > 0 )
        {
            // cout << "  \\\" " << n;
            totalLength -= n;
        }
        
        if ( ( n = NumberOfSpecials( line.substr( 1, line.length() - 2), "\\\\" ) ) > 0 )
        {
            // cout << "  \\\\ " << n;
            totalLength -= n;
        }
        
        if ( ( n = NumberOfSpecials( line.substr( 1, line.length() - 2), "\\x" ) ) > 0 )
        {
            // cout << "  \\x " << n;
            totalLength -= 3 * n;
        }
        // cout << endl;
    }

    cout << "\n\nlength " << length << endl;
    cout << "total  " << totalLength << endl;
    cout << "result " << (length - totalLength) << endl;

    return 0;
}
/*
Title: MIME Type
Tags: easy, conditions, loops, hash tables, strings
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int main()
{
    int N; // Number of elements which make up the association table.
    cin >> N; cin.ignore();
    int Q; // Number Q of file names to be analyzed.
    cin >> Q; cin.ignore();

    map<string, string> table;
    for (int i = 0; i < N; i++) {
        string EXT; // file extension
        string MT; // MIME type.
        cin >> EXT >> MT; cin.ignore();
        transform(EXT.begin(), EXT.end(), EXT.begin(), ::tolower);
        table[EXT] = MT;
    }
    vector<string> fileNames;
    for (int i = 0; i < Q; i++) {
        string FNAME; // One file name per line.
        getline(cin, FNAME);
        transform(FNAME.begin(), FNAME.end(), FNAME.begin(), ::tolower);
        fileNames.push_back( FNAME );
    }

    cerr << "Table" << endl;
    typedef map<string, string>::iterator it_type;
    for ( it_type iterator = table.begin(); iterator != table.end(); ++iterator ) {
        cerr << iterator->first << " " << iterator->second << endl;
    }

    cerr << endl << "File names" << endl;
    for ( int i = 0; i < fileNames.size(); i++ ) {
        cerr << fileNames[i] << endl;
    }
    cerr << endl;

    unsigned int size = fileNames.size();
    for ( int i = 0; i < size; i++ ) {
        string fileName = fileNames[i];

        size_t posDot = fileName.find_last_of( "." );

        if ( posDot == string::npos ) {
            cout << "UNKNOWN" << endl;
        } else {
            string ext = fileName.substr( posDot + 1 );
            map<string, string>::iterator it;
            it = table.find( ext );
            if ( it != table.end() ) {
                cout << it->second << endl;
            } else {
                cout << "UNKNOWN" << endl;
            }
        }


    }
}

#include <iostream>
#include "md5.h"

using namespace std;

int main( int argc, char **argv )
{
    string input("ckczppom");

    int i = 0;
    string result("");
    while (1)
    {
        string hash = md5(input + to_string(i));
        string sub = hash.substr(0, 6);
        if (sub.compare("000000") == 0)
        {
            break;
        }
        if ( i > 10000000 )
        {
            break;
        }
        i++;
    }

    cout << i << endl;

    return 0;
}
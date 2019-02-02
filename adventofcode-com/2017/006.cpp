#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void printVector( vector<int> &v )
{
    vector<int>::iterator it;
    for ( it = v.begin(); it != v.end(); ++it )
    {
        cout << *it << " ";
    }
    cout << "\n";
}

int main(int argc, char **argv)
{
    // part 1
    // vector<int> banks = { 0, 5, 10, 0, 11, 14, 13, 4, 11, 8, 8, 7, 1, 4, 12, 11 };
    // part 2
    vector<int> banks = { 10, 9, 8, 7, 6, 5, 4, 3, 1, 1, 0, 15, 14, 13, 11, 12 };
    int size = 16;
    // vector<int> banks = { 0, 2, 7, 0 };
    // int size = 4;
    // printVector( banks );
    vector< vector<int> > history;
    history.push_back( banks );

    bool isRunning = true;
    vector<int>::iterator itBanks;
    vector< vector< int > >::iterator itHistory;
    while ( isRunning )
    {
        itBanks = max_element( banks.begin(), banks.end() );
        int index = distance( banks.begin(), itBanks );
        int max = *itBanks;
        *itBanks = 0; 

        while ( max > 0 )
        {
            index++;
            if ( index >= size )
            {
                index = 0;
            }
            banks[index]++;
            max--;
        }
        // printVector( banks );

        for ( itHistory = history.begin(); itHistory != history.end(); ++itHistory )
        {
            vector<int> &b = *itHistory;
            if ( equal( banks.begin(), banks.end(), b.begin() ) )
            {
                printVector( b );
                isRunning = false;
                break;
            }
        }

        if ( isRunning )
        {
            history.push_back( banks );
        }
    }

    cout << history.size();

    // for ( itHistory = history.begin(); itHistory != history.end(); ++itHistory )
    // {
    //     vector<int> &b = *itHistory;
    //     for ( itBanks = b.begin(); itBanks != banks.end(); ++itBanks )
    //     {
    //         cout << *itBanks << " ";
    //     }
    //     cout << "\n";
    // }

    return 0;
}
#include <iostream>

using namespace std;

const int SIZE = 256;
// int SIZE = 5;

void reverse( int *original, int start, int length )
{
    int *temp = new int[length];
    int tempIndex = 0;
    int originalIndex = start;
    while( tempIndex < length )
    {
        if ( originalIndex >= SIZE )
        {
            originalIndex = 0;
        }
        temp[tempIndex] = original[originalIndex];
        tempIndex++;
        originalIndex++;
    }

    // cout << "temp before reverse:  ";
    // for ( int i = 0; i < length; i++ )
    // {
    //     cout << temp[i] << " ";
    // }
    // cout << "\n";

    for ( int i = 0; i < length / 2; i++ )
    {
        int t = temp[i];
        temp[i] = temp[length - 1 - i];
        temp[length - 1 - i] = t;
    }

    // cout << "temp after reverse: ";
    // for ( int i = 0; i < length; i++ )
    // {
    //     cout << temp[i] << " ";
    // }
    // cout << "\n";

    tempIndex = 0;
    originalIndex = start;
    while( tempIndex < length )
    {
        if ( originalIndex >= SIZE )
        {
            originalIndex = 0;
        }
        original[originalIndex] = temp[tempIndex];
        tempIndex++;
        originalIndex++;
    }    

    // for ( int i = 0; i < length; i++ )
    // {
        // cout << temp[i] << " ";
    // }
}

int main(int argc, char **argv)
{
    int elements[SIZE];
    for ( int i = 0; i < SIZE; i++ )
    {
        elements[i] = i;
    }

    int lengths[16] = { 94,84,0,79,2,27,81,1,123,93,218,23,103,255,254,243 };
    // int lengths[4] = { 3, 4, 1, 5 };

    int pos = 0;
    for ( int i = 0; i < 16; i++ )
    // for ( int i = 0; i < 4; i++ )
    {
        // cout << "original before reverese: ";
        // for ( int i = 0; i < SIZE; i++ )
        // {
        //     cout << elements[i] << " ";
        // }
        // cout << "\n";

        // cout << "pos: " << pos << "\n";

        reverse( elements, pos, lengths[i] );

        int count = 0;
        while ( count < lengths[i] + i )
        {
            pos++;
            if ( pos >= SIZE )
            {
                pos = 0;
            }
            count++;
        }

        // cout << "original after reverse: ";
        // for ( int i = 0; i < SIZE; i++ )
        // {
        //     cout << elements[i] << " ";
        // }
        // cout << "\n\n";
    }

    cout << elements[0] * elements[1];

    return 0;
}
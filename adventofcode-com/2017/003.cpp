#include <iostream>
#include <cmath>

using namespace std;







/* PART 2

147  142  133  122   59
304    5    4    2   57
330   10    1    1   54
351   11   23   25   26
362  747  806--->   ...

*/

// const int SIZE = 633;
const int SIZE = 20;
int m[SIZE][SIZE] = {0};

int sumNeighbours( int x, int y )
{
    // cout << " " << x << " " << y << "\n";
    // if ( x + 1 >= SIZE || x - 1 < 0 || y + 1 >= SIZE || y - 1 < 0 )
    if ( x < 1 || y < 1 || x > SIZE - 2 || y > SIZE -2 )
    {
        // cout << "    RETURN\n";
        return 0;
    }
    // cout << "    OK\n";
    int sum = 0;
    for ( int i = x - 1; i <= x + 1; i++ )
    {
        for ( int j = y - 1; j <= y + 1; j++ )
        {
            // cout << m[i][j] << " ";
            // if ( i != x && j != y )
            // {
            //     sum += m[i][j];
            // }
            if ( i == x && j == y )
            {
                continue;
            }
            sum += m[i][j];
        }
        // cout << "\n";
    } 

    return sum;
}

int main(int argc, char **argv)
{
    int row = floor( SIZE / 2 );
    int col = floor( SIZE / 2 );
    // cout << row << " " << col << "\n\n";

    int step = 2;
    m[row][col] = 1;

    int i = 0;
    int result = 0;
    // while ( i < 347992 )
    while ( row < SIZE && row > 0 && col < SIZE && col > 0 )
    {
        // cout << i << "\n";
        col++;
        if (row >= SIZE || row < 0 || col >= SIZE || col < 0)
        {
            continue;
        }
        m[row][col] = sumNeighbours( row, col );
        if ( result == 0 && m[row][col] > 347991 )
        {
            result = m[row][col];
        }

        // up
        for ( int a = 0; a < step - 1; a++ )
        {
            row--;
            if (row >= SIZE || row < 0 || col >= SIZE || col < 0)
            {
                continue;
            }
            m[row][col] = sumNeighbours( row, col );
            if ( result == 0 && m[row][col] > 347991 )
            {
                result = m[row][col];
            }
        }
        // left
        for ( int a = 0; a < step; a++ )
        {
            col--;
            if (row >= SIZE || row < 0 || col >= SIZE || col < 0)
            {
                continue;
            }
            m[row][col] = sumNeighbours( row, col );
            if ( result == 0 && m[row][col] > 347991 )
            {
                result = m[row][col];
            }
        }
        // down
        for ( int a = 0; a < step; a++ )
        {
            row++;
            if (row >= SIZE || row < 0 || col >= SIZE || col < 0)
            {
                continue;
            }
            m[row][col] = sumNeighbours( row, col );
            if ( result == 0 && m[row][col] > 347991 )
            {
                result = m[row][col];
            }
        }
        // right
        for ( int a = 0; a < step; a++ )
        {
            col++;
            m[row][col] = sumNeighbours( row, col );
            if ( result == 0 && m[row][col] > 347991 )
            {
                result = m[row][col];
            }
        }
        step += 2;
        i++;
    }

    cout << result;

    // for ( int row = 0; row < SIZE; row++ )
    // {
    //     for ( int col = 0; col < SIZE; col++ )
    //     {
    //         // if ( m[row][col] < 10 )
    //         // {
    //         //     cout << " ";
    //         // }
    //         cout << m[row][col] << "       ";
    //         // cout << row << "." << col << " ";

    //     }
    //     cout << "\n";
    // }

    return 0;
}

/* PART 1

65  64  63  62  61  60  59  58  57
66  37  36  35  34  33  32  31  56
67  38  17  16  15  14  13  30  55
68  39  18   5   4   3  12  29  54
69  40  19   6   1   2  11  28  53
70  41  20   7   8   9  10  27  52
71  42  21  22  23  24  25  26  51
72  43  44  45  46  47  48  49  50
73  74  75  76  77  78  79  80  81  82

n of elements in the frames 1  8  16  24  32
n of steps in the frames       2   4   6   8

*/

// int main(int argc, char **argv)
// {
//     int m[633][633];
//     // int m[9][9];
//     int row = floor( 633 / 2 );
//     int col = floor( 633 / 2 );
//     // int row = floor( 9 / 2 );
//     // int col = floor( 9 / 2 );
//     // cout << row << " " << col << "\n\n";
//     int i = 1;
//     int step = 2;
//     m[row][col] = i;

//     int row2, col2;

//     while ( i < 347992 )
//     // while ( i < 82 )
//     {
//         col++;
//         i++;
//         m[row][col] = i;
//         if ( i == 347991 )
//         {
//             row2 = row;
//             col2 = col;
//         }
//         // up
//         for ( int a = 0; a < step - 1; a++ )
//         {
//             row--;
//             i++;
//             m[row][col] = i;
//             if ( i == 347991 )
//             {
//                 row2 = row;
//                 col2 = col;
//             }
//         }
//         // left
//         for ( int a = 0; a < step; a++ )
//         {
//             col--;
//             i++;
//             m[row][col] = i;
//             if ( i == 347991 )
//             {
//                 row2 = row;
//                 col2 = col;
//             }
//         }
//         // down
//         for ( int a = 0; a < step; a++ )
//         {
//             row++;
//             i++;
//             m[row][col] = i;
//             if ( i == 347991 )
//             {
//                 row2 = row;
//                 col2 = col;
//             }
//         }
//         // right
//         for ( int a = 0; a < step; a++ )
//         {
//             col++;
//             i++;
//             m[row][col] = i;
//             if ( i == 347991 )
//             {
//                 row2 = row;
//                 col2 = col;
//             }
//         }
//         step += 2;
//     }

//     cout << abs( floor( 633 / 2 ) - row2 ) + abs( floor( 633 / 2 ) - col2 );

//     // for ( int row = 0; row < 633; row++ )
//     // {
//     //     for ( int col = 0; col < 633; col++ )
//     //     {
//     //         // if ( m[row][col] < 10 )
//     //         // {
//     //         //     cout << " ";
//     //         // }
//     //         // cout << m[row][col] << " ";
//     //         // cout << row << "." << col << " ";

//     //     }
//     //     cout << "\n";
//     // }

//     return 0;
// }
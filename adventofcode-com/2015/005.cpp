#include <iostream>
#include <fstream>

using namespace std;

/*
It contains at least three vowels (aeiou only),
like aei, xazegov, or aeiouaeiouaeiou.

It contains at least one letter that appears twice in a row,
like xx, abcdde (dd), or aabbccdd (aa, bb, cc, or dd).

It does not contain the strings ab, cd, pq, or xy,
even if they are part of one of the other requirements.
*/

/*
It contains a pair of any two letters that appears at least twice in the string without overlapping,
like xyxy (xy) or aabcdefgaa (aa), but not like aaa (aa, but it overlaps).

It contains at least one letter which repeats with exactly one letter between them,
like xyx, abcdefeghi (efe), or even aaa.
*/

int main(int argc, char **argv)
{
    std::ifstream infile("005.txt");
    std::string line;
    int nice = 0;
    while (std::getline(infile, line))
    {
        // 1st
        // int vovels = 0;
        // bool doubles = false;
        // bool pairs = false;

        // 2nd
        bool doublePairs = false;
        bool repeats = false;

        for ( int i = 0; i < line.length(); i++ )
        {
            // 1st
            // // vovel check
            // char c = line[i];
            // if ( c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' )
            // {
            //     vovels++;
            // }

            // // double check
            // // pair check
            // if ( i < line.length() - 1 )
            // {
            //     char a = line[i];
            //     char b = line[i+1];
            //     if ( !doubles )
            //     {
            //         doubles = (a == b);
            //     }

            //     if ( !pairs )
            //     {
            //         pairs = (a == 'a' && b == 'b') || (a == 'c' && b == 'd') || (a == 'p' && b == 'q') || (a == 'x' && b == 'y');
            //     }
            // }


            // 2nd
            // double pairs
            if ( i < line.length() - 3 )
            {
                char a = line[i];
                char b = line[i+1];
                for ( int j = i+2; j < line.length(); j++ )
                {
                    char c = line[j];
                    char d = line[j+1];

                    if ( !doublePairs )
                    {
                        doublePairs = (a == c) && (b == d);
                    }
                }
            }

            // repeat check
            if ( i < line.length() - 2 )
            {
                char a = line[i];
                char b = line[i+2];

                if ( !repeats )
                {
                    repeats = (a == b);
                }
            }
        }

        // 1st
        // nice += (int)( (vovels > 2) && doubles && !pairs );

        // 2nd
        nice += (int)( doublePairs && repeats );
    }

    cout << "nice: " << nice << endl;

    infile.close();

    return 0;
}
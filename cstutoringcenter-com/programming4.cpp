/* http://www.cstutoringcenter.com
 *
 * Problem 4 solution
 * Problem: Given the following information about a US telephone touchtone keypad:
 *              1: (NONE)   2: A,B,C    3: D,E,F
 *              4: G,H,I    5: J,K,L    6: M,N,O
 *              7: P,R,S    8: T,U,V	9: W,X,Y
 *          calculate the product of each characters value.
 *
 *          As an example, say the user enters: "Practice", the product would be:
 *              7 * 7 * 2 * 2 * 8 * 4 * 2 * 3 = 37,632
 *          What is the value of this string: "Programming Challenges are fun"?
 *
 * author:  mandyedi
 * contact: mandyedi@gmail.com
 */

#include <iostream>

using namespace std;

int main()
{
    string s = "programmingchallengesarefun";
    double sum = 1;
    cout.precision(20);

    for(int i=0; i<s.size(); i++)
    {
        if(s[i] == 'a' || s[i] == 'b' || s[i] == 'c')
        {
            sum *= 2;
        }

        if(s[i] == 'd' || s[i] == 'e' || s[i] == 'f')
        {
            sum *= 3;
        }

        if(s[i] == 'g' || s[i] == 'h' || s[i] == 'i')
        {
            sum *= 4;
        }

        if(s[i] == 'j' || s[i] == 'k' || s[i] == 'l')
        {
            sum *= 5;
        }

        if(s[i] == 'm' || s[i] == 'n' || s[i] == 'o')
        {
            sum *= 6;
        }

        if(s[i] == 'p' || s[i] == 'r' || s[i] == 's')
        {
            sum *= 7;
        }

        if(s[i] == 't' || s[i] == 'u' || s[i] == 'v')
        {
            sum *= 8;
        }

        if(s[i] == 'w' || s[i] == 'x' || s[i] == 'y')
        {
            sum *= 9;
        }
    }

    cout << sum;

    return 0;
}
